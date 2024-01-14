/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:45:25 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/14 22:22:34 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	free_image(t_image *img)
{
	if (img)
	{
		free(img);
	}
}

void	free_texture(t_texture *tex)
{
	if (tex)
	{
		free_image(tex->imgno);
		free_image(tex->imgso);
		free_image(tex->imgwe);
		free_image(tex->imgea);
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
		if (game->text.imgno && game->text.imgno->img)
			mlx_destroy_image(game->mlx, game->text.imgno->img);
		if (game->text.imgso && game->text.imgso->img)
			mlx_destroy_image(game->mlx, game->text.imgso->img);
		if (game->text.imgea && game->text.imgea->img)
			mlx_destroy_image(game->mlx, game->text.imgea->img);
		if (game->text.imgwe && game->text.imgwe->img)
			mlx_destroy_image(game->mlx, game->text.imgwe->img);
		if (game->img && game->img->img)
			mlx_destroy_image(game->mlx, game->img->img);
		free_texture(&(game->text));
		free_file(game->file);
		if (game->mlx && game->mlxwin)
			mlx_destroy_window(game->mlx, game->mlxwin);
	}
}
