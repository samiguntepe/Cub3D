/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/17 16:20:28 by sguntepe         ###   ########.fr       */
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
	printf("%s", file->EA);
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
		exit(printf("Wrong, RGB path!\nError\n 1"));
	while (str[i] != '\0')
	{
		if (str[i] > 32 && count < 11)
		{
			temp[count] = str[i];
			count++;
		}
		i++;
	}
	if (!control_RGB_comma(temp))
		exit(printf("Wrong, RGB path!\nError\n 2"));
	// if (temp[3] != ',' || temp[7] != ',')
	// 	exit(printf("Wrong, RGB path!\nError\n 2"));
	temp[count] = '\0';
	new = ft_strcpy(new, temp);
	if (!control_RGB_path(str, new))
	{
		exit(printf("Wrong, RGB path!\nError\n 3"));
	}
	free(str);
	return (new);
}