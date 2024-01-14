/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:24 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/15 02:09:59 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

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
	g->ray.camera_x = 2 * x / (double)SW - 1;
	g->ray.raydir_x = g->ray.dir_x + g->ray.plane_x * g->ray.camera_x;
	g->ray.raydir_y = g->ray.dir_y + g->ray.plane_y * g->ray.camera_x;
	g->ray.map_x = (int)g->ray.pos_x;
	g->ray.map_y = (int)g->ray.pos_y;
}

void	init2(t_game *g)
{
	if (g->ray.raydir_x == 0)
		g->ray.deltadist_x = 1e30;
	else
		g->ray.deltadist_x = fabs(1 / g->ray.raydir_x);
	if (g->ray.raydir_y == 0)
		g->ray.deltadist_y = 1e30;
	else
		g->ray.deltadist_y = fabs(1 / g->ray.raydir_y);
}

void	calculate(t_game *g)
{
	if (g->ray.raydir_x < 0)
	{
		g->ray.step_x = -1;
		g->ray.sidedist_x = (g->ray.pos_x - g->ray.map_x) * g->ray.deltadist_x;
	}
	else
	{
		g->ray.step_x = 1;
		g->ray.sidedist_x
			= (g->ray.map_x + 1.0 - g->ray.pos_x) * g->ray.deltadist_x;
	}
	if (g->ray.raydir_y < 0)
	{
		g->ray.step_y = -1;
		g->ray.sidedist_y = (g->ray.pos_y - g->ray.map_y) * g->ray.deltadist_y;
	}
	else
	{
		g->ray.step_y = 1;
		g->ray.sidedist_y
			= (g->ray.map_y + 1.0 - g->ray.pos_y) * g->ray.deltadist_y;
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
