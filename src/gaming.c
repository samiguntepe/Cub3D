/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:24 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/04 14:28:11 by sguntepe         ###   ########.fr       */
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
	g->rayc.camera_x = 2 * x / (double)SW - 1;
	g->rayc.raydir_x = g->rayc.dir_x + g->rayc.plane_x * g->rayc.camera_x;
	g->rayc.raydir_y = g->rayc.dir_y + g->rayc.plane_y * g->rayc.camera_x;
	g->rayc.map_x = (int)g->rayc.pos_x;
	g->rayc.map_y = (int)g->rayc.pos_y;
}

void	init2(t_game *g)
{
	if (g->rayc.raydir_x == 0)
		g->rayc.deltadist_x = 1e30;
	else
		g->rayc.deltadist_x = fabs(1 / g->rayc.raydir_x);
	if (g->rayc.raydir_y == 0)
		g->rayc.deltadist_y = 1e30;
	else
		g->rayc.deltadist_y = fabs(1 / g->rayc.raydir_y);
}

void	calculate(t_game *g)
{
	if (g->rayc.raydir_x < 0)
	{
		g->rayc.step_x = -1;
		g->rayc.sidedist_x = (g->rayc.pos_x - g->rayc.map_x) * g->rayc.deltadist_x;
	}
	else
	{
		g->rayc.step_x = 1;
		g->rayc.sidedist_x
			= (g->rayc.map_x + 1.0 - g->rayc.pos_x) * g->rayc.deltadist_x;
	}
	if (g->rayc.raydir_y < 0)
	{
		g->rayc.step_y = -1;
		g->rayc.sidedist_y = (g->rayc.pos_y - g->rayc.map_y) * g->rayc.deltadist_y;
	}
	else
	{
		g->rayc.step_y = 1;
		g->rayc.sidedist_y
			= (g->rayc.map_y + 1.0 - g->rayc.pos_y) * g->rayc.deltadist_y;
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
