/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:50 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/18 12:54:49 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include <stdlib.h>

int	control_components(char **map, int i, int j)
{
	if ((map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N' ||
		map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W') &&
		(map[i][j] == ' ' || map[i][j] == '0' || map[i][j] == '1' ||
		map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' ||
		map[i][j] == 'W'))
		return 1;
	else
		return 0;
}

int control_RGB_path(char *mainStr, char *subStr) {
    int i = 0;
    int main_length = ft_strlen(mainStr);
    int sub_length = ft_strlen(subStr);

    while (i <= main_length - sub_length) {
        int j = 0;

        if (mainStr[i] == subStr[0]) {
            while (j < sub_length && mainStr[i + j] == subStr[j]) {
                j++;
            }
            if (j == sub_length) {
                while (mainStr[i + j] != '\0') {
                    if (mainStr[i + j] > 32) {
                        return 0;
                    }
                    j++;
                }
                return 1;
            }
        }
        i++;
    }
    return 0;
}

int	control_RGB_comma(char *kod)
{
	int	i;
	int	num;
    char **ptr;
	
	i = 0;
	num = 0;
	while (kod[i])
	{
		if (kod[i] == ',')
			num++;
		i++;
	}
	if (num != 2)
		return 1;
	ptr = ft_split(kod, ',');
	i = 0;
	while (ptr[i])
	{
		num = ft_atoi(ptr[i]);
		if (num  > 255 || num < 0)
			return 1;
		i++;
	}
	if(i != 3)
		return 1;
	return 0;
}


void	map_control(t_cub	*cub3d)
{
	(void)cub3d;
}
