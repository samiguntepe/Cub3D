/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:50 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/23 19:27:11 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../cub3d.h"
#include <stdlib.h>

int	control_components(char *map_line)
{
	int i;
	int	count;
	int	len;
	int	isspace;

	i = 0;
	len = 0;
	count = 0;
	isspace = 0;
	while (map_line[i])
	{
		if (map_line[i] == '0' || map_line[i] == '1' || map_line[i] == 'N' ||
		map_line[i] == 'S' || map_line[i] == 'E' || map_line[i] == 'W' || map_line[i] == ' ')
		{
			if (map_line[i] <= 32)
				isspace++;
			count++;
		}
		i++;
	}
	len = ft_strlen(map_line);
	if (isspace == len)
		return 0;
	if (count == len)
		return 1;
	return 0;
}

int control_rgb_path(char *mainStr, char *subStr) {
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

int	control_rgb_comma(char *kod)
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
	double_array_free(ptr, i);
	return 0;
}

void	map_control(t_file *fl)
{
	(void)fl;
}