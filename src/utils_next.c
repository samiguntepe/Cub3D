/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:26:47 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/14 22:44:56 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i <= (n - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (ft_strlen (src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_strcpy(char **destination, const char *source)
{
	int	i;

	if (*destination == NULL)
	{
		*destination = malloc(sizeof(char) * ft_strlen(source) + 1);
		if (*destination == NULL)
			return ;
	}
	i = 0;
	while (source[i] != '\0')
	{
		(*destination)[i] = source[i];
		i++;
	}
	(*destination)[i] = 0;
}

void	str_cpy(char *destination, const char *source)
{
	while (*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
