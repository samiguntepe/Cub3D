/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:50 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/25 11:38:17 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	control_components(char *map_line, int len, int count, int isspace)
{
	int	i;

	i = 0;
	len = 0;
	count = 0;
	isspace = 0;
	while (map_line[i])
	{
		if (map_line[i] == '0' || map_line[i] == '1' || map_line[i] == 'N'
			|| map_line[i] == 'S' || map_line[i] == 'E' || map_line[i] == 'W'
			|| map_line[i] == ' ')
		{
			if (map_line[i] <= 32)
				isspace++;
			count++;
		}
		i++;
	}
	len = ft_strlen(map_line);
	if (isspace == len)
		return (0);
	if (count == len)
		return (1);
	return (0);
}

void	control_companent_count(t_file *fl, int i)
{
	int	count;

	count = 0;
	i = 0;
	while (fl->lines[i])
	{
		if (fl->lines[i][0] == 'F' || fl->lines[i][0] == 'C'
			|| fl->lines[i][0] == 'N' || fl->lines[i][0] == 'S'
			|| fl->lines[i][0] == 'W' || fl->lines[i][0] == 'E')
			count++;
		i++;
	}
	if (count > 6)
		exit_game(fl->game, "Wrong, companents count!");
}

void	rgb_is_number(t_file *fl, int i, int j)
{
	while (fl->lines[i])
	{
		if ((fl->lines[i][0] == 'F' && fl->lines[i][1] == ' ')
			|| (fl->lines[i][0] == 'C' && fl->lines[i][1] == ' '))
		{
			j = 2;
			while (fl->lines[i][j])
			{
				if (!((fl->lines[i][j] >= '0' && fl->lines[i][j] <= '9')
					|| (fl->lines[i][j] == ',' || fl->lines[i][j] == ' ')))
					exit_game(fl->game, "Wrong, RGB path!");
				j++;
			}
		}
		i++;
	}
}
