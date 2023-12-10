/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:42 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/10 09:10:04 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft/libft.h"
#include <stdlib.h>
#include "cub3d.h"
#include <stdio.h>

char	*ft_strjoin_(char const *s1, char const *s2, char **leak)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(ptr))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < i + ft_strlen(s2) && s2[j] != '\0')
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	free(*leak);
	return (ptr);
}

char	*read_mapfile(int fd)
{
	char	c;
	char	**leak;
	char	*map_file;
	int		read_bytes;

	map_file = malloc(sizeof(char) * 2);
	read_bytes = read(fd, map_file, 1);
	map_file[1] = '\0';
	while (read_bytes > 0)
	{
		read_bytes = read(fd, &c, 1);
		leak = &map_file;
		map_file = ft_strjoin_(map_file, &c, leak);
	}
	return (map_file);
}
