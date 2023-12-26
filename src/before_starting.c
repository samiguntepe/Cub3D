/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_starting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:04:50 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 20:59:33 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	before_starting(t_game *g)
{
	file_parcer(g->file);
	control_companent(g->file, 0, 0);
	find_player(g->file, g);
	inits_rgb(g);
	texture_init(g);
	texture_init_next(g);
	game_inits(g);
	g->mlxwin = mlx_new_window(g->mlx, SW, SH, "cub3D");
}

void	next(t_game *g)
{
	int	n;

	inits(g->file);
	g->mlx = mlx_init();
	before_starting(g);
	g->img = malloc(sizeof(t_image));
	g->img->img = mlx_new_image(g->mlx, SW, SH);
	g->img->addr = (int *)mlx_get_data_addr(g->img->img, &n, &n, &n);
	mlx_hook(g->mlxwin, 2, 1L << 0, move_press, g);
	mlx_hook(g->mlxwin, 3, 1L << 1, move_release, g);
	mlx_hook(g->mlxwin, 17, 0, close_window, g);
	mlx_loop_hook(g->mlx, &game_loop, g);
	mlx_loop(g->mlx);
}

void	inits_structs()
{
	
}