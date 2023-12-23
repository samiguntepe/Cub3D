/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/23 19:40:24 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>
#include <stdlib.h>

void	file_parcer(t_file *file)
{
	file->whole_lines = read_file(file);
	file->lines = split_lines(file->whole_lines);
	find_textures(file, 0);
	find_rgb(file);
	file->F = set_rgb(file->F);
	file->C = set_rgb(file->C);
	file->EA = set_textures(file->EA);
	file->WE = set_textures(file->WE);
	file->SO = set_textures(file->SO);
	file->NO = set_textures(file->NO);
	map_size(file);
	find_map(file);
}

char	*set_rgb(char *str)
{
	int		i;
	int		count;
	char	*new;
	char	temp[12];

	
	i = 1;
	count = 0;
	new = NULL;	
	if (str == NULL)
		exit(printf("Wrong, rgb path!\nError\n"));
	while (str[i] != '\0')
	{
		if ((str[i] > 32 && count < 11) || (str[i] >= '0' && str[i] <= '9'))
		{
			temp[count] = str[i];
			count++;
		}
		i++;
	}
	temp[count] = '\0';
	if (control_rgb_comma(temp))
		exit(printf("Wrong, rgb path!\nError\n"));
	ft_strcpy(&new, temp);
	if (!control_rgb_path(str, new))
		exit(printf("Wrong, rgb path!\nError\n"));
	free(str);
	return (new);
}

void	find_map(t_file *fl)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	
	while (fl->lines[i])
	{
		if (control_components(fl->lines[i]))
		{
			fl->map_w = ft_strlen(fl->lines[i]);
			fl->map[j] = ft_calloc(fl->map_w, (sizeof(char *) + 1));
			ft_strcpy(&(fl->map[j]), fl->lines[i]);
			fl->map[j][fl->map_w] = '\0';
			j++;
		}
		if (j > 0 && !(control_components(fl->lines[i])))
			exit(printf("Wrong map!\nError\n"));
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
		if (control_components(fl->lines[i]))
			fl->map_h++;
		i++;
	}
	if (fl->map_h < 3)
		exit(printf("Map is free!\nError\n"));
	fl->map = ft_calloc(fl->map_h, (sizeof(char **) + 1));
	i = 0;
	while (i < fl->map_h)
	{
		fl->map[i] = NULL;
		i++;
	}
}