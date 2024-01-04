/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:27 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/04 14:25:30 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_right(t_game *g)
{
	double	olddir_x;
	double	oldplane_x;

	if (g->right)
	{
		olddir_x = g->rayc.dir_x;
		g->rayc.dir_x = g->rayc.dir_x * cos(g->rspeed) - g->rayc.dir_y
			* sin(g->rspeed);
		g->rayc.dir_y = olddir_x * sin(g->rspeed) + g->rayc.dir_y
			* cos(g->rspeed);
		oldplane_x = g->rayc.plane_x;
		g->rayc.plane_x = g->rayc.plane_x * cos(g->rspeed) - g->rayc.plane_y
			* sin(g->rspeed);
		g->rayc.plane_y = oldplane_x * sin(g->rspeed) + g->rayc.plane_y
			* cos(g->rspeed);
	}
}

void	movement_ws(t_game *g, t_file *fl)
{
	if (g->w)
	{
		if (fl->map[(int)(g->rayc.pos_y)][(int)(g->rayc.pos_x + g->rayc.dir_x
			* g->speed)] != 49)
			g->rayc.pos_x += g->rayc.dir_x * g->speed;
		if (fl->map[(int)(g->rayc.pos_y + g->rayc.dir_y * g->speed)]
			[(int)(g->rayc.pos_x)] != 49)
			g->rayc.pos_y += g->rayc.dir_y * g->speed;
	}
	if (g->s)
	{
		if (fl->map[(int)(g->rayc.pos_y)][(int)(g->rayc.pos_x - g->rayc.dir_x
			* g->speed)] != 49)
			g->rayc.pos_x -= g->rayc.dir_x * g->speed;
		if (fl->map[(int)(g->rayc.pos_y - g->rayc.dir_y * g->speed)]
			[(int)(g->rayc.pos_x)] != 49)
			g->rayc.pos_y -= g->rayc.dir_y * g->speed;
	}
}

void	movement_da(t_game *g, t_file *fl)
{
	if (g->a)
	{
		if (fl->map[(int)(g->rayc.pos_y - g->rayc.plane_y * g->speed)]
			[(int)(g->rayc.pos_x)] != 49)
			g->rayc.pos_y -= g->rayc.plane_y * g->speed;
		if (fl->map[(int)(g->rayc.pos_y)][(int)(g->rayc.pos_x - g->rayc.plane_x
			* g->speed)] != 49)
			g->rayc.pos_x -= g->rayc.plane_x * g->speed;
	}
	if (g->d)
	{
		if (fl->map[(int)(g->rayc.pos_y)][(int)(g->rayc.pos_x + g->rayc.plane_x
			* g->speed)] != 49)
			g->rayc.pos_x += g->rayc.plane_x * g->speed;
		if (fl->map[(int)(g->rayc.pos_y + g->rayc.plane_y * g->speed)]
			[(int)(g->rayc.pos_x)] != 49)
			g->rayc.pos_y += g->rayc.plane_y * g->speed;
	}
}

void	rotate_left(t_game *g)
{
	double	olddir_x;
	double	oldplane_x;

	if (g->left)
	{
		olddir_x = g->rayc.dir_x;
		g->rayc.dir_x = g->rayc.dir_x * cos(g->rspeed) + g->rayc.dir_y
			* sin(g->rspeed);
		g->rayc.dir_y = -olddir_x * sin(g->rspeed) + g->rayc.dir_y
			* cos(g->rspeed);
		oldplane_x = g->rayc.plane_x;
		g->rayc.plane_x = g->rayc.plane_x * cos(g->rspeed) + g->rayc.plane_y
			* sin(g->rspeed);
		g->rayc.plane_y = -oldplane_x * sin(g->rspeed) + g->rayc.plane_y
			* cos(g->rspeed);
	}
}
