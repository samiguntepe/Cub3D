/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:36:35 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 16:55:15 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	mlx_destroy_window(g->mlx, g->mlxwin);
	system("leaks cub3D");
	exit(1);
	return (0);
}

void	game_exit(t_game *g, char *msg)
{
	(void)g;
	// printf("%s\nError\n", msg);
	perror(msg);
}
