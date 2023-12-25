/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:27 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 09:50:35 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_right(t_game *g)
{
	double	olddir_x;
	double	oldplane_x;

	if (g->right)
	{
		olddir_x = g->rayc.dirX;
		g->rayc.dirX = g->rayc.dirX * cos(g->rspeed) - g->rayc.dirY
			* sin(g->rspeed);
		g->rayc.dirY = olddir_x * sin(g->rspeed) + g->rayc.dirY
			* cos(g->rspeed);
		oldplane_x = g->rayc.planeX;
		g->rayc.planeX = g->rayc.planeX * cos(g->rspeed) - g->rayc.planeY
			* sin(g->rspeed);
		g->rayc.planeY = oldplane_x * sin(g->rspeed) + g->rayc.planeY
			* cos(g->rspeed);
	}
}

void	movement_ws(t_game *g, t_file *fl)
{
	if (g->w)
	{
		if (fl->map[(int)(g->rayc.posY)][(int)(g->rayc.posX + g->rayc.dirX
			* g->speed)] != 49)
			g->rayc.posX += g->rayc.dirX * g->speed;
		if (fl->map[(int)(g->rayc.posY + g->rayc.dirY * g->speed)]
			[(int)(g->rayc.posX)] != 49)
			g->rayc.posY += g->rayc.dirY * g->speed;
	}
	if (g->s)
	{
		if (fl->map[(int)(g->rayc.posY)][(int)(g->rayc.posX - g->rayc.dirX
			* g->speed)] != 49)
			g->rayc.posX -= g->rayc.dirX * g->speed;
		if (fl->map[(int)(g->rayc.posY - g->rayc.dirY * g->speed)]
			[(int)(g->rayc.posX)] != 49)
			g->rayc.posY -= g->rayc.dirY * g->speed;
	}
}

void	movement_da(t_game *g, t_file *fl)
{
	if (g->a)
	{
		if (fl->map[(int)(g->rayc.posY - g->rayc.planeY * g->speed)]
			[(int)(g->rayc.posX)] != 49)
			g->rayc.posY -= g->rayc.planeY * g->speed;
		if (fl->map[(int)(g->rayc.posY)][(int)(g->rayc.posX - g->rayc.planeX
			* g->speed)] != 49)
			g->rayc.posX -= g->rayc.planeX * g->speed;
	}
	if (g->d)
	{
		if (fl->map[(int)(g->rayc.posY)][(int)(g->rayc.posX + g->rayc.planeX
			* g->speed)] != 49)
			g->rayc.posX += g->rayc.planeX * g->speed;
		if (fl->map[(int)(g->rayc.posY + g->rayc.planeY * g->speed)]
			[(int)(g->rayc.posX)] != 49)
			g->rayc.posY += g->rayc.planeY * g->speed;
	}
}

void	rotate_left(t_game *g)
{
	double	olddir_x;
	double	oldplane_x;

	if (g->left)
	{
		olddir_x = g->rayc.dirX;
		g->rayc.dirX = g->rayc.dirX * cos(g->rspeed) + g->rayc.dirY
			* sin(g->rspeed);
		g->rayc.dirY = -olddir_x * sin(g->rspeed) + g->rayc.dirY
			* cos(g->rspeed);
		oldplane_x = g->rayc.planeX;
		g->rayc.planeX = g->rayc.planeX * cos(g->rspeed) + g->rayc.planeY
			* sin(g->rspeed);
		g->rayc.planeY = -oldplane_x * sin(g->rspeed) + g->rayc.planeY
			* cos(g->rspeed);
	}
}
