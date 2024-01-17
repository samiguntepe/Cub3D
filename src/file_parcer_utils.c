/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:47:48 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/17 17:04:57 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

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
		exit_game(fl->game, "Wrong, textures path!");
}

void	copy_textures(t_file *fl, int textures, int i)
{
	if (textures == NO_TEXTURE)
		ft_strcpy(&(fl->no), fl->lines[i]);
	else if (textures == SO_TEXTURE)
		ft_strcpy(&(fl->so), fl->lines[i]);
	else if (textures == WE_TEXTURE)
		ft_strcpy(&(fl->we), fl->lines[i]);
	else if (textures == EA_TEXTURE)
		ft_strcpy(&(fl->ea), fl->lines[i]);
	else
		exit_game(fl->game, "Wrong, textures path!");
}

void	find_rgb(t_file *fl, int f_count, int c_count, int i)
{
	int	j;

	f_count = 0;
	c_count = 0;
	i = 0;
	while (fl->lines[i])
	{
		j = 0;
		while (fl->lines[i][j])
		{
			if (fl->lines[i][0] == 'F' && fl->lines[i][1] == ' ')
			{
				if (fl->lines[i][j] == ',')
					copy_rgb(fl, ++f_count, 'F', i);
			}
			if (fl->lines[i][0] == 'C' && fl->lines[i][1] == ' ')
			{
				if (fl->lines[i][j] == ',')
					copy_rgb(fl, ++c_count, 'C', i);
			}
			j++;
		}
		i++;
	}
}

void	copy_rgb(t_file *fl, int comma_count, char type, int i)
{
	if (type == 'F')
	{
		if (comma_count == 2)
		{
			fl->lines[i]++;
			while (*fl->lines[i] <= 32)
				fl->lines[i]++;
			ft_strcpy(&(fl->f), fl->lines[i]);
		}
	}
	else if (type == 'C')
	{
		if (comma_count == 2)
		{
			fl->lines[i]++;
			while (*fl->lines[i] <= 32)
				fl->lines[i]++;
			ft_strcpy(&(fl->c), fl->lines[i]);
		}
	}
	else
		exit_game(fl->game, "Wrong, textures path!");
}

char	*set_textures(char *str)
{
	char	*new;

	if (str == NULL)
		return (NULL);
	new = ft_strtrim(str, "NSOWEA ");
	free(str);
	return (new);
}
