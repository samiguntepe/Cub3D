/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:47:48 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/17 16:31:22 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void	find_textures(t_file *fl, int textures)
{
	int	i;
	int	m;
	
	i = 0;
	m = 3 * textures;
	while (fl->lines[i])
	{
			if (fl->lines[i][0] == fl->verify[m]
			&& fl->lines[i][1] == fl->verify[m +1]
			&& fl->lines[i][2] == fl->verify[m +2])
			{
				copy_textures(fl, textures, i);
				textures++;
				m = 3 * textures;
				i = -1;
			}
			if (!(textures < 4))
				break ;
		i++;
	}
	if (textures != 4)
		printf("Wrong, texture path!\nError\n");
}

void	copy_textures(t_file *fl, int textures, int i)
{
	if (textures == NO_Texture)
		fl->NO = ft_strcpy(fl->NO, fl->lines[i]);
	else if (textures == SO_Texture)
		fl->SO = ft_strcpy(fl->SO, fl->lines[i]);
	else if (textures == WE_Texture)
		fl->WE = ft_strcpy(fl->WE, fl->lines[i]);
	else if (textures == EA_Texture)
		fl->EA = ft_strcpy(fl->EA, fl->lines[i]);
	else
		printf("Wrong, texture path!\nError\n");
}

void	find_RGB(t_file *fl)
{
	int	i;
	int	j;
	int fCount;
	int cCount;

	fCount = 0;
	cCount = 0;
	i = 0;
	while (fl->lines[i])
	{
		j = 0;
		while (fl->lines[i][j])
		{
			if(fl->lines[i][0] == 'F')
			{
				if (fl->lines[i][j] == ',')
				{
					copy_RGB(fl, ++fCount, 'F', i);
				}
			}
			if(fl->lines[i][0] == 'C')
			{
				if (fl->lines[i][j] == ',')
				{
					copy_RGB(fl, ++cCount, 'C', i);
				}
			}
			j++;
		}
		i++;
	}
}

void	copy_RGB(t_file *fl, int comma_count, char type, int i)
{
	if (type == 'F')
	{
		if (comma_count == 2)
		{
			fl->F = ft_strcpy(fl->F, fl->lines[i]);
		}
	}
	else if (type == 'C')
	{
		if (comma_count == 2)
		{
			fl->C = ft_strcpy(fl->C, fl->lines[i]);
		}
	}
	else	
		printf("Wrong, RGB path!\nError\n");

}

char	*set_textures(char *str)
{
	char *new;
	if (str == NULL)
		exit(printf("Wrong, texturex path!\nError\n"));
	new = ft_strtrim(str, "NSOWEA ");
	return (new);
}