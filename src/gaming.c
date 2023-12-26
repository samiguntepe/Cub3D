/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:24 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 15:20:41 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	game_loop(t_game *g)
{
	movement_ws(g, g->file);
	movement_da(g, g->file);
	rotate_left(g);
	rotate_right(g);
	raycast(g, g->file);
	return (0);
}

void	init(t_game *g, int x)
{
	g->rayc.camera = 2 * x / (double)SW - 1;
	g->rayc.raydirx = g->rayc.dirx + g->rayc.planex * g->rayc.camera;
	g->rayc.raydiry = g->rayc.diry + g->rayc.planey * g->rayc.camera;
	g->rayc.mapx = (int)g->rayc.posx;
	g->rayc.mapy = (int)g->rayc.posy;
}

void	init2(t_game *g)
{
	if (g->rayc.raydirx == 0)
		g->rayc.deltadistx = 1e30;
	else
		g->rayc.deltadistx = fabs(1 / g->rayc.raydirx);
	if (g->rayc.raydiry == 0)
		g->rayc.deltadisty = 1e30;
	else
		g->rayc.deltadisty = fabs(1 / g->rayc.raydiry);
}

void	calculate(t_game *g)
{
	if (g->rayc.raydirx < 0)
	{
		g->rayc.stepx = -1;
		g->rayc.sidedistx = (g->rayc.posx - g->rayc.mapx) * g->rayc.deltadistx;
	}
	else
	{
		g->rayc.stepx = 1;
		g->rayc.sidedistx
			= (g->rayc.mapx + 1.0 - g->rayc.posx) * g->rayc.deltadistx;
	}
	if (g->rayc.raydiry < 0)
	{
		g->rayc.stepy = -1;
		g->rayc.sidedisty = (g->rayc.posy - g->rayc.mapy) * g->rayc.deltadisty;
	}
	else
	{
		g->rayc.stepy = 1;
		g->rayc.sidedisty
			= (g->rayc.mapy + 1.0 - g->rayc.posy) * g->rayc.deltadisty;
	}
}

void	raycast(t_game *g, t_file *fl)
{
	int	x;

	x = -1;
	while (++x < SW)
	{
		init(g, x);
		init2(g);
		calculate(g);
		dda(g, fl);
		dda2(g);
		draw(g);
		draw2(g);
		draw3(g, x, -1);
	}
	mlx_put_image_to_window(g->mlx, g->mlxwin, g->img->img, 0, 0);
}
