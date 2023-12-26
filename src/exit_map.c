/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:36:35 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 21:24:43 by sguntepe         ###   ########.fr       */
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
	if (g->file->no != NULL)
		free(g->file->no);
	if (g->file->so != NULL)
		free(g->file->so);
	if (g->file->we != NULL)
		free(g->file->we);
	if (g->file->ea != NULL)
		free(g->file->ea);
	if (g->file->f != NULL)
		free(g->file->f);
	if (g->file->c != NULL)
		free(g->file->c);
	if (g->file->whole_lines != NULL)
		free(g->file->whole_lines);
	if (g->file->rowlen != NULL)
		free(g->file->rowlen);
	if (g->file->spc_map != NULL)
		double_array_free(g->file->spc_map);
	if (g->file->map != NULL)
		double_array_free(g->file->map);
	if (g->file->lines != NULL)
		double_array_free(g->file->lines);
	printf("%s\nError\n", msg);
}
