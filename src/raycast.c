/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:15 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 12:17:48 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda(t_game *g, t_file *fl)
{
	g->rayc.hit = 0;
	while (g->rayc.hit == 0)
	{
		if (g->rayc.sideDistX < g->rayc.sideDistY)
		{
			g->rayc.sideDistX += g->rayc.deltaDistX;
			g->rayc.mapX += g->rayc.stepX;
			g->rayc.side = 0;
		}
		else
		{
			g->rayc.sideDistY += g->rayc.deltaDistY;
			g->rayc.mapY += g->rayc.stepY;
			g->rayc.side = 1;
		}
		if (fl->map[g->rayc.mapY][g->rayc.mapX] == '1')
			g->rayc.hit = 1;
	}
}

void	dda2(t_game *g)
{
	if (g->rayc.side == 0)
		g->rayc.perpwalldist = g->rayc.sideDistX - g->rayc.deltaDistX;
	else
		g->rayc.perpwalldist = g->rayc.sideDistY - g->rayc.deltaDistY;
	g->text.lineH = (int)(SH / g->rayc.perpwalldist);
}

void	draw(t_game *g)
{
	g->text.drawStart = -g->text.lineH / 2 + SH / 2;
	if (g->text.drawStart < 0)
		g->text.drawStart = 0;
	g->text.drawEnd = g->text.lineH / 2 + SH / 2;
	if (g->text.drawEnd >= SH)
		g->text.drawEnd = SH - 1;
	if (g->rayc.side == 0)
		g->rayc.wallX = g->rayc.posY + g->rayc.perpwalldist * g->rayc.rayDirY;
	else
		g->rayc.wallX = g->rayc.posX + g->rayc.perpwalldist * g->rayc.rayDirX;
	g->rayc.wallX = g->rayc.wallX - (int)g->rayc.wallX;
}

void	draw2(t_game *g)
{
	g->text.texX = (int)(g->rayc.wallX * (double)g->text.texWidth);
	if (g->rayc.side == 0 && g->rayc.rayDirX < 0)
		g->text.texX = g->text.texWidth - g->text.texX - 1;
	if (g->rayc.side == 1 && g->rayc.rayDirY > 0)
		g->text.texX = g->text.texWidth - g->text.texX - 1;
	g->text.step = 1.0 * g->text.texHeight / g->text.lineH;
	g->text.texPos = (g->text.drawStart - SH / 2 + g->text.lineH / 2)
		* g->text.step;
}

void	draw3(t_game *g, int x, int y)
{
	while (++y < SH)
	{
		g->text.texY = (int)g->text.texPos;
		if (y < g->text.drawStart)
			g->img->addr[y * SW + x] = g->text.ceiling;
		else if (y > g->text.drawEnd)
			g->img->addr[y * SW + x] = g->text.floor;
		else
		{
			if (g->rayc.side == 1 && g->rayc.rayDirY < 0)
				g->img->addr[y * SW + x] = g->text.imgSO->addr[g->text.texHeight
					* g->text.texY + g->text.texX];
			else if (g->rayc.side == 1 && g->rayc.rayDirY > 0)
				g->img->addr[y * SW + x] = g->text.imgNO->addr[g->text.texHeight
					* g->text.texY + g->text.texX];
			if (g->rayc.side == 0 && g->rayc.rayDirX < 0)
				g->img->addr[y * SW + x] = g->text.imgWE->addr[g->text.texHeight
					* g->text.texY + g->text.texX];
			else if (g->rayc.side == 0 && g->rayc.rayDirX > 0)
				g->img->addr[y * SW + x] = g->text.imgEA->addr[g->text.texHeight
					* g->text.texY + g->text.texX];
			g->text.texPos += g->text.step;
		}
	}
}
