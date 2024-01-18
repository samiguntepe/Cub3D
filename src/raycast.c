/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:15 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/04 16:52:28 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda(t_game *g, t_file *fl)
{
	g->ray.hit = 0;
	while (g->ray.hit == 0)
	{
		if (g->ray.sidedist_x < g->ray.sidedist_y)
		{
			g->ray.sidedist_x += g->ray.deltadist_x;
			g->ray.map_x += g->ray.step_x;
			g->ray.side = 0;
		}
		else
		{
			g->ray.sidedist_y += g->ray.deltadist_y;
			g->ray.map_y += g->ray.step_y;
			g->ray.side = 1;
		}
		if (fl->map[g->ray.map_y][g->ray.map_x] == '1')
			g->ray.hit = 1;
	}
}

void	dda2(t_game *g)
{
	if (g->ray.side == 0)
		g->ray.perpwalldist = g->ray.sidedist_x - g->ray.deltadist_x;
	else
		g->ray.perpwalldist = g->ray.sidedist_y - g->ray.deltadist_y;
	g->text.line_h = (int)(SH / g->ray.perpwalldist);
}

void	draw(t_game *g)
{
	g->text.draw_start = -g->text.line_h / 2 + SH / 2;
	if (g->text.draw_start < 0)
		g->text.draw_start = 0;
	g->text.draw_end = g->text.line_h / 2 + SH / 2;
	if (g->text.draw_end >= SH)
		g->text.draw_end = SH - 1;
	if (g->ray.side == 0)
		g->ray.wall_x = g->ray.pos_y + g->ray.perpwalldist * g->ray.raydir_y;
	else
		g->ray.wall_x = g->ray.pos_x + g->ray.perpwalldist * g->ray.raydir_x;
	g->ray.wall_x = g->ray.wall_x - (int)g->ray.wall_x;
}

void	draw2(t_game *g)
{
	g->text.tex_x = (int)(g->ray.wall_x * (double)g->text.text_w);
	if (g->ray.side == 0 && g->ray.raydir_x < 0)
		g->text.tex_x = g->text.text_w - g->text.tex_x - 1;
	if (g->ray.side == 1 && g->ray.raydir_y > 0)
		g->text.tex_x = g->text.text_w - g->text.tex_x - 1;
	g->text.step = 1.0 * g->text.text_h / g->text.line_h;
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
			if (g->ray.side == 1 && g->ray.raydir_y < 0)
				g->img->addr[y * SW + x] = g->text.imgso->addr[g->text.text_h
					* g->text.tex_y + g->text.tex_x];
			else if (g->ray.side == 1 && g->ray.raydir_y > 0)
				g->img->addr[y * SW + x] = g->text.imgno->addr[g->text.text_h
					* g->text.tex_y + g->text.tex_x];
			if (g->ray.side == 0 && g->ray.raydir_x < 0)
				g->img->addr[y * SW + x] = g->text.imgwe->addr[g->text.text_h
					* g->text.tex_y + g->text.tex_x];
			else if (g->ray.side == 0 && g->ray.raydir_x > 0)
				g->img->addr[y * SW + x] = g->text.imgea->addr[g->text.text_h
					* g->text.tex_y + g->text.tex_x];
			g->text.text_pos += g->text.step;
		}
	}
}
