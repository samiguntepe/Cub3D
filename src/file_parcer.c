/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/15 13:08:42 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void	file_parcer(t_file *file)
{
	file->whole_lines = read_file(file);
	file->line_count = line_counter(file->whole_lines);
	file->lines = split_lines(file->whole_lines, file->line_count, 0, 0);
	find_textures(file, 0);
	find_rgb(file, 0, 0, 0);
	control_rgb_comma(file->f, file->game);
	control_rgb_comma(file->c, file->game);
	if (file->f == NULL || file->c == NULL)
		exit_game(file->game, "Wrong RGB path!");
	file->ea = set_textures(file->ea);
	file->we = set_textures(file->we);
	file->so = set_textures(file->so);
	file->no = set_textures(file->no);
	if (file->ea == NULL || file->we == NULL || file->so == NULL
		|| file->no == NULL)
		exit_game(file->game, "Wrong, textures path!");
	map_size(file);
	find_map(file);
	sur_control(file);
}

void	find_map(t_file *fl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (fl->lines[i])
	{
		if (control_components(fl->lines[i], 0, 0, 0))
		{
			fl->map_w = ft_strlen(fl->lines[i]);
			fl->map[j] = ft_calloc(fl->map_w, (sizeof(char *) + 1));
			ft_strcpy(&(fl->map[j]), fl->lines[i]);
			fl->map[j][fl->map_w] = '\0';
			j++;
		}
		if (j > 0 && !(control_components(fl->lines[i], 0, 0, 0)))
			exit_game(fl->game, "Map is wrong!");
		i++;
	}
}

void	map_size(t_file *fl)
{
	int	i;

	i = 0;
	fl->map_h = 0;
	while (fl->lines[i])
	{
		if (control_components(fl->lines[i], 0, 0, 0))
			fl->map_h++;
		i++;
	}
	if (fl->map_h < 3)
		exit_game(fl->game, "Map is free!");
	fl->map = ft_calloc(fl->map_h, (sizeof(char **) + 1));
	i = 0;
	while (i < fl->map_h)
	{
		fl->map[i] = NULL;
		i++;
	}
}
