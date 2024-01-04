/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:15 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/04 14:34:27 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda(t_game *g, t_file *fl)
{
	g->rayc.hit = 0;
	while (g->rayc.hit == 0)
	{
		if (g->rayc.sidedist_x < g->rayc.sidedist_y)
		{
			g->rayc.sidedist_x += g->rayc.deltadist_x;
			g->rayc.map_x += g->rayc.step_x;
			g->rayc.side = 0;
		}
		else
		{
			g->rayc.sidedist_y += g->rayc.deltadist_y;
			g->rayc.map_y += g->rayc.step_y;
			g->rayc.side = 1;
		}
		if (fl->map[g->rayc.map_y][g->rayc.map_x] == '1')
			g->rayc.hit = 1;
	}
}

void	dda2(t_game *g)
{
	if (g->rayc.side == 0)
		g->rayc.perpwalldist = g->rayc.sidedist_x - g->rayc.deltadist_x;
	else
		g->rayc.perpwalldist = g->rayc.sidedist_y - g->rayc.deltadist_y;
	g->text.line_h = (int)(SH / g->rayc.perpwalldist);
}

void	draw(t_game *g)
{
	g->text.draw_start = -g->text.line_h / 2 + SH / 2;
	if (g->text.draw_start < 0)
		g->text.draw_start = 0;
	g->text.draw_end = g->text.line_h / 2 + SH / 2;
	if (g->text.draw_end >= SH)
		g->text.draw_end = SH - 1;
	if (g->rayc.side == 0)
		g->rayc.wall_x = g->rayc.pos_y + g->rayc.perpwalldist * g->rayc.raydir_y;
	else
		g->rayc.wall_x = g->rayc.pos_x + g->rayc.perpwalldist * g->rayc.raydir_x;
	g->rayc.wall_x = g->rayc.wall_x - (int)g->rayc.wall_x;
}

void	draw2(t_game *g)
{
	g->text.tex_x = (int)(g->rayc.wall_x * (double)g->text.text_width);
	if (g->rayc.side == 0 && g->rayc.raydir_x < 0)
		g->text.tex_x = g->text.text_width - g->text.tex_x - 1;
	if (g->rayc.side == 1 && g->rayc.raydir_y > 0)
		g->text.tex_x = g->text.text_width - g->text.tex_x - 1;
	g->text.step = 1.0 * g->text.text_height / g->text.line_h;
	g->text.text_pos = (g->text.draw_start - SH / 2 + g->text.line_h / 2)
		* g->text.step;
}

void	draw3(t_game *g, int x, int y)
{
	while (++y < SH)
	{
		g->text.tex_y = (int)g->text.text_pos;
		if (y < g->text.draw_start)
			g->img->addr[y * SW + x] = g->text.ceiling;
		else if (y > g->text.draw_end)
			g->img->addr[y * SW + x] = g->text.floor;
		else
		{
			if (g->rayc.side == 1 && g->rayc.raydir_y < 0)
				g->img->addr[y * SW + x] = g->text.imgso->addr[g->text.text_height
					* g->text.tex_y + g->text.tex_x];
			else if (g->rayc.side == 1 && g->rayc.raydir_y > 0)
				g->img->addr[y * SW + x] = g->text.imgno->addr[g->text.text_height
					* g->text.tex_y + g->text.tex_x];
			if (g->rayc.side == 0 && g->rayc.raydir_x < 0)
				g->img->addr[y * SW + x] = g->text.imgwe->addr[g->text.text_height
					* g->text.tex_y + g->text.tex_x];
			else if (g->rayc.side == 0 && g->rayc.raydir_x > 0)
				g->img->addr[y * SW + x] = g->text.imgea->addr[g->text.text_height
					* g->text.tex_y + g->text.tex_x];
			g->text.text_pos += g->text.step;
		}
	}
}
