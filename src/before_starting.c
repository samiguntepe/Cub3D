/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_starting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:04:50 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 16:12:49 by sguntepe         ###   ########.fr       */
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
