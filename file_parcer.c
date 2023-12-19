/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/19 18:32:42 by sguntepe         ###   ########.fr       */
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
	map_size(file);
	find_map(file);
	printf("%s\n",file->map[0]);
	printf("%s\n",file->map[1]);
	printf("%s\n",file->map[2]);
	printf("%s\n",file->map[3]);
	printf("%s\n",file->map[4]);
	printf("%s\n",file->map[5]);
	printf("%s\n",file->map[6]);
	printf("%s\n",file->map[7]);
	printf("%s\n",file->map[8]);
	printf("%s\n",file->map[9]);
	printf("%s\n",file->map[10]);
	printf("%s\n",file->map[11]);
	printf("%s\n",file->map[12]);
	printf("%s\n",file->map[13]);

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
	
	i = 0;
	j = 0;
	
	while (fl->lines[i])
	{
		if (control_components(fl->lines[i]))
		{
			ft_strcpy(fl->map[j], fl->lines[i]);
			// printf("%d: %s\n", i,fl->lines[i]);
			// printf("%d: %s\n\n",i, fl->map[j]);
			// printf("%d\n", i);
			j++;
			fl->map[i][ft_strlen(fl->lines[i])] = '\0';
		}
		i++;
	}
}
void	map_size(t_file *fl)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (fl->lines[i])
	{
		if (control_components(fl->lines[i]))
			len++;
		i++;
	}
	fl->map = (char **)malloc(sizeof(char *) * len + 1);
	fl->map[len] = NULL;
	i = 0;
	while (fl->lines[i])
	{
		len = 0;
		len = ft_strlen(fl->lines[i]);
		fl->map[i] = malloc(sizeof(char) * len + 1);
		fl->map[i][len] = '\0';
		i++;
	}
}