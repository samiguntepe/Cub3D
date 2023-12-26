/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:15 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 15:20:41 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda(t_game *g, t_file *fl)
{
	g->rayc.hit = 0;
	while (g->rayc.hit == 0)
	{
		if (g->rayc.sidedistx < g->rayc.sidedisty)
		{
			g->rayc.sidedistx += g->rayc.deltadistx;
			g->rayc.mapx += g->rayc.stepx;
			g->rayc.side = 0;
		}
		else
		{
			g->rayc.sidedisty += g->rayc.deltadisty;
			g->rayc.mapy += g->rayc.stepy;
			g->rayc.side = 1;
		}
		if (fl->map[g->rayc.mapy][g->rayc.mapx] == '1')
			g->rayc.hit = 1;
	}
}

void	dda2(t_game *g)
{
	if (g->rayc.side == 0)
		g->rayc.perpwalldist = g->rayc.sidedistx - g->rayc.deltadistx;
	else
		g->rayc.perpwalldist = g->rayc.sidedisty - g->rayc.deltadisty;
	g->text.lineh = (int)(SH / g->rayc.perpwalldist);
}

void	draw(t_game *g)
{
	g->text.drw_start = -g->text.lineh / 2 + SH / 2;
	if (g->text.drw_start < 0)
		g->text.drw_start = 0;
	g->text.drw_end = g->text.lineh / 2 + SH / 2;
	if (g->text.drw_end >= SH)
		g->text.drw_end = SH - 1;
	if (g->rayc.side == 0)
		g->rayc.wallx = g->rayc.posy + g->rayc.perpwalldist * g->rayc.raydiry;
	else
		g->rayc.wallx = g->rayc.posx + g->rayc.perpwalldist * g->rayc.raydirx;
	g->rayc.wallx = g->rayc.wallx - (int)g->rayc.wallx;
}

void	draw2(t_game *g)
{
	g->text.tx_x = (int)(g->rayc.wallx * (double)g->text.tx_width);
	if (g->rayc.side == 0 && g->rayc.raydirx < 0)
		g->text.tx_x = g->text.tx_width - g->text.tx_x - 1;
	if (g->rayc.side == 1 && g->rayc.raydiry > 0)
		g->text.tx_x = g->text.tx_width - g->text.tx_x - 1;
	g->text.step = 1.0 * g->text.tx_height / g->text.lineh;
	g->text.tx_pos = (g->text.drw_start - SH / 2 + g->text.lineh / 2)
		* g->text.step;
}

void	draw3(t_game *g, int x, int y)
{
	while (++y < SH)
	{
		g->text.tx_y = (int)g->text.tx_pos;
		if (y < g->text.drw_start)
			g->img->addr[y * SW + x] = g->text.ceiling;
		else if (y > g->text.drw_end)
			g->img->addr[y * SW + x] = g->text.floor;
		else
		{
			if (g->rayc.side == 1 && g->rayc.raydiry < 0)
				g->img->addr[y * SW + x] = g->text.imgso->addr[g->text.tx_height
					* g->text.tx_y + g->text.tx_x];
			else if (g->rayc.side == 1 && g->rayc.raydiry > 0)
				g->img->addr[y * SW + x] = g->text.imgno->addr[g->text.tx_height
					* g->text.tx_y + g->text.tx_x];
			if (g->rayc.side == 0 && g->rayc.raydirx < 0)
				g->img->addr[y * SW + x] = g->text.imgwe->addr[g->text.tx_height
					* g->text.tx_y + g->text.tx_x];
			else if (g->rayc.side == 0 && g->rayc.raydirx > 0)
				g->img->addr[y * SW + x] = g->text.imgea->addr[g->text.tx_height
					* g->text.tx_y + g->text.tx_x];
			g->text.tx_pos += g->text.step;
		}
	}
}
