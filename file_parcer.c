/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/18 13:33:30 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	file_parcer(t_file *file)
{
	file->whole_lines = read_file(file);
	file->lines = split_lines(file->whole_lines);
	find_textures(file, 0);
	find_RGB(file);
	file->F = set_RGB(file->F);
	file->C = set_RGB(file->C);
	file->EA = set_textures(file->EA);
	file->WE = set_textures(file->WE);
	file->SO = set_textures(file->SO);
	file->NO = set_textures(file->NO);
	filterLines(file->lines, )
	
}

char	*set_RGB(char *str)
{
	int		i;
	int		count;
	char	*new;
	char	temp[12];

	
	i = 1;
	count = 0;
	new = NULL;	
	if (str == NULL)
		exit(printf("Wrong, RGB path!\nError\n"));
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
	if (control_RGB_comma(temp))
		exit(printf("Wrong, RGB path!\nError\n"));
	new = ft_strcpy(new, temp);
	if (!control_RGB_path(str, new))
		exit(printf("Wrong, RGB path!\nError\n"));
	free(str);
	return (new);
}

void	find_map(t_file *fl)
{
	int	i;
	int	j;
	int k;
	int l;
	
	k = 0;
	i = 0;
	while (fl->lines[i])
	{
		l = 0;
		j = 0;
		while (fl->lines[i][j])
		{
			if (control_components(fl->lines, i, j))
			{
				fl->map[k][l] = fl->lines[i][j];
			}
			j++;
			l++;
		}
		fl->map[k][l] = '\0';
		i++;
		k++;
	}
}
void	map_size(t_file *fl)
{
	int	i;
	int	j;

	i = 0;
	while (fl->lines[i])
		i++;
	fl->lines = (char **)malloc(sizeof(char *) * i + 1);
	fl->lines[i] = '\0';
	i = 0;
	while (fl->lines[i])
	{
		j = 0;
		while (fl->lines[i][j])
		{
			if (control_components(fl->lines, i, j))
			{
				
			}
			j++;
		}
		i++;
	}
}