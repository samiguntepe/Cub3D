/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:27 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 15:20:41 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_right(t_game *g)
{
	double	olddir_x;
	double	oldplane_x;

	if (g->right)
	{
		olddir_x = g->rayc.dirx;
		g->rayc.dirx = g->rayc.dirx * cos(g->rspeed) - g->rayc.diry
			* sin(g->rspeed);
		g->rayc.diry = olddir_x * sin(g->rspeed) + g->rayc.diry
			* cos(g->rspeed);
		oldplane_x = g->rayc.planex;
		g->rayc.planex = g->rayc.planex * cos(g->rspeed) - g->rayc.planey
			* sin(g->rspeed);
		g->rayc.planey = oldplane_x * sin(g->rspeed) + g->rayc.planey
			* cos(g->rspeed);
	}
}

void	movement_ws(t_game *g, t_file *fl)
{
	if (g->w)
	{
		if (fl->map[(int)(g->rayc.posy)][(int)(g->rayc.posx + g->rayc.dirx
			* g->speed)] != 49)
			g->rayc.posx += g->rayc.dirx * g->speed;
		if (fl->map[(int)(g->rayc.posy + g->rayc.diry * g->speed)]
			[(int)(g->rayc.posx)] != 49)
			g->rayc.posy += g->rayc.diry * g->speed;
	}
	if (g->s)
	{
		if (fl->map[(int)(g->rayc.posy)][(int)(g->rayc.posx - g->rayc.dirx
			* g->speed)] != 49)
			g->rayc.posx -= g->rayc.dirx * g->speed;
		if (fl->map[(int)(g->rayc.posy - g->rayc.diry * g->speed)]
			[(int)(g->rayc.posx)] != 49)
			g->rayc.posy -= g->rayc.diry * g->speed;
	}
}

void	movement_da(t_game *g, t_file *fl)
{
	if (g->a)
	{
		if (fl->map[(int)(g->rayc.posy - g->rayc.planey * g->speed)]
			[(int)(g->rayc.posx)] != 49)
			g->rayc.posy -= g->rayc.planey * g->speed;
		if (fl->map[(int)(g->rayc.posy)][(int)(g->rayc.posx - g->rayc.planex
			* g->speed)] != 49)
			g->rayc.posx -= g->rayc.planex * g->speed;
	}
	if (g->d)
	{
		if (fl->map[(int)(g->rayc.posy)][(int)(g->rayc.posx + g->rayc.planex
			* g->speed)] != 49)
			g->rayc.posx += g->rayc.planex * g->speed;
		if (fl->map[(int)(g->rayc.posy + g->rayc.planey * g->speed)]
			[(int)(g->rayc.posx)] != 49)
			g->rayc.posy += g->rayc.planey * g->speed;
	}
}

void	rotate_left(t_game *g)
{
	double	olddir_x;
	double	oldplane_x;

	if (g->left)
	{
		olddir_x = g->rayc.dirx;
		g->rayc.dirx = g->rayc.dirx * cos(g->rspeed) + g->rayc.diry
			* sin(g->rspeed);
		g->rayc.diry = -olddir_x * sin(g->rspeed) + g->rayc.diry
			* cos(g->rspeed);
		oldplane_x = g->rayc.planex;
		g->rayc.planex = g->rayc.planex * cos(g->rspeed) + g->rayc.planey
			* sin(g->rspeed);
		g->rayc.planey = -oldplane_x * sin(g->rspeed) + g->rayc.planey
			* cos(g->rspeed);
	}
}
