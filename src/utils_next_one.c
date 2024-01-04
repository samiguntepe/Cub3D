/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:17:34 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/04 16:52:58 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

char	*ft_strstr(const char *str, const char *substr)
{
	const char	*temp_str;
	const char	*temp_substr;

	temp_substr = NULL;
	temp_str = NULL;
	if (*substr == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		temp_str = str;
		temp_str = substr;
		while (*temp_substr != '\0' && *temp_str == *temp_substr)
		{
			temp_str++;
			temp_substr++;
		}
		if (*temp_substr == '\0')
			return ((char *)str);
		str++;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

void	map_name_control(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[--len] == 'b')
	{
		if (map_name[--len] == 'u')
		{
			if (map_name[--len] == 'c')
			{
				if (map_name[--len] == '.')
					;
				else
					exit(printf("Wrong, map name!"));
			}
			else
				exit(printf("Wrong, map name!"));
		}
		else
			exit(printf("Wrong, map name!"));
	}
	else
		exit(printf("Wrong, map name!"));
}

int	create_rgb(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}
