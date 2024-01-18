/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:45:25 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/18 14:40:21 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void	double_array_free(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	exit_game(t_game *game, char *msg)
{
	if (msg)
	{
		printf(RED"%s Error"CODE, msg);
		printf("\n");
		free_game(game);
		exit(1);
	}
	else
	{
		free_game(game);
		exit(0);
	}
}

void	free_texture(t_texture *tex)
{
	if (tex)
	{
		free(tex->imgno);
		free(tex->imgso);
		free(tex->imgwe);
		free(tex->imgea);
	}
}

void	free_file(t_file *file)
{
	if (file)
	{
		double_array_free(file->map);
		free(file->no);
		free(file->so);
		free(file->we);
		free(file->ea);
		free(file->f);
		free(file->c);
		double_array_free(file->lines);
		free(file->whole_lines);
		free(file->rowlen);
		free(file);
	}
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->control)
		{
			if (game->text.imgno->img)
				mlx_destroy_image(game->mlx, game->text.imgno->img);
			if (game->text.imgso->img)
				mlx_destroy_image(game->mlx, game->text.imgso->img);
			if (game->text.imgea->img)
				mlx_destroy_image(game->mlx, game->text.imgea->img);
			if (game->text.imgwe->img)
				mlx_destroy_image(game->mlx, game->text.imgwe->img);
		}
		free_texture(&(game->text));
		free_file(game->file);
		if (game->img && game->img->img)
			mlx_destroy_image(game->mlx, game->img->img);
		if (game->mlx && game->mlxwin)
			mlx_destroy_window(game->mlx, game->mlxwin);
	}
}
