/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:50 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/10 09:21:55 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

void	control_components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N' ||
				map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W');
			else
				perror("Error\n");
			j++;
		}
		i++;
	}
}

void	map_control(t_cub	*cub3d)
{
	control_components(cub3d->map);
}
