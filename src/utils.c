/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:47:31 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 13:17:43 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2)
{
	char	*result;
	size_t	total_len;

	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	if (s2 != NULL)
		len_s2 = ft_strlen(s2);
	total_len = len_s1 + len_s2;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	if (len_s1 > 0)
		str_cpy(result, s1);
	if (len_s2 > 0)
		str_cpy(result + len_s1, s2);
	result[total_len] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

int	ft_atoi(const char *str)
{
	int	d;
	int	s;

	d = 1;
	s = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		d = d * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s * d);
}

char	*ft_strchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
	}
	return (NULL);
}
