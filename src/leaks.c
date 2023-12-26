/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:45:25 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 15:23:47 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	game_free(t_game *g)
{
	int	len;

	len = line_counter(g->file->whole_lines);
	free(g->file->no);
	free(g->file->we);
	free(g->file->ea);
	free(g->file->so);
	free(g->file->f);
	free(g->file->c);
	double_array_free(g->file->map, g->file->map_h);
	double_array_free(g->file->lines, len);
	free(g->file->whole_lines);
	mlx_destroy_image(g->mlx, g->text.imgea);
	mlx_destroy_image(g->mlx, g->text.imgno);
	mlx_destroy_image(g->mlx, g->text.imgwe);
	mlx_destroy_image(g->mlx, g->text.imgso);
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_window(g->mlx, g->mlxwin);
	free(g->file);
}

void	double_array_free(char **arr, int len)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	doubleint_array_free(int **arr, int len)
{
	int	i;

	i = 0;
	if (arr == NULL)
	{
		return ;
	}
	if (len == 0)
	{
		free(arr[0]);
		arr[0] = NULL;
		free(arr[1]);
		arr[1] = NULL;
		free(arr[2]);
		arr[2] = NULL;
	}
	while (i < len)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
