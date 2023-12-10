/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:42 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/10 17:37:33 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft/libft.h"
#include <stdlib.h>
#include "cub3d.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>



void trim(char *str) {
    int start = 0, end = strlen(str) - 1;

    // Başındaki boşlukları geç
    while (isspace(str[start])) {
        start++;
    }

    // Sondaki boşlukları geç
    while (end > start && isspace(str[end])) {
        end--;
    }

    // Son karakterin ardından NULL karakterini ekle
    str[end + 1] = '\0';

    // Metni kaydır
    memmove(str, str + start, end - start + 2);
}

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

char	*read_type_of_element(int fd)
{
	char	**leak;
	char	*types;
	int 	read_bytes;
	
	leak = NULL;
	types = malloc(sizeof(char) * 2);
	read_bytes = read(fd, types, 1);
	types[1] = '\0';
	types = read_type_while(leak, read_bytes, types, fd);
	// split_map(types);
	return (types);
}

char	*read_type_while(char **leak, int read_bytes, char *types, int fd)
{
	char	c;
	int		count;
	int		isspace;
	int		bytes_sum;
	int		last_sum;

	count = 0;
	isspace = 32;
	bytes_sum = 0;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, &c, 1);
		bytes_sum += read_bytes;
		leak = &types;
		if (c  > isspace)
		{
			if(c == ',')
				count++;
			types = ft_strjoin_(types, &c, leak);
			last_sum = bytes_sum;
			if(count == 4 && bytes_sum < last_sum + 4)
				break;
		}
	}
	return (types);
}

// char	**split_map(char *map_file)
// {
	
// 	int		ncount;
// 	// char *new_str;
// 	trim(map_file);
// 	printf("%s",map_file);
	
// 	// printf("%s",new_mapfile[0]);
// 	ncount = ncounter(map_file);
// 	return NULL;
	
// }

int	ncounter(char *map_file)
{
	int i;
	int exit;
	int ncount;

	i = 0;
	exit = 0;
	ncount = 0;
	while (map_file[i])
	{
		if (map_file[i] == '\n' && map_file[i+2] == '\n')
		{
			while (map_file[i] < 33)
			{
				if (map_file[i] == '\0')
				{
					exit = 1;
					break;
				}
				i++;
			}
			if (exit)
				break;
			ncount++;
		}
		i++;
	}
	return (ncount);
}