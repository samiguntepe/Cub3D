/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:36:27 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/04 14:39:33 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	mlx_destroy_window(g->mlx, g->mlxwin);
	exit(1);
	return (0);
}
