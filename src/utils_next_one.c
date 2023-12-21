/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:17:34 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/21 17:22:59 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strstr(const char *str, const char *substr)
{
	const char	*temp_str;
	const char	*temp_substr;

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
