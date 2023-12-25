/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:47:43 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 14:28:35 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

char	**split_lines(const char *str, int line_count, size_t start, int i)
{
	char	**lines;
	int		line_length;

	lines = (char **)malloc((line_count + 1) * sizeof(char *));
	if (!lines)
		return (NULL);
	start = 0;
	i = 0;
	while (start < ft_strlen(str))
	{
		line_length = get_line_length(str, i, '\n');
		if (line_length == -1)
			break ;
		lines[i] = (char *)malloc((line_length + 1) * sizeof(char));
		if (!lines[i])
			return (split_lines_free(lines, i));
		ft_strlcpy(lines[i], &str[start], line_length + 1);
		lines[i][line_length] = '\0';
		start += line_length + 1;
		i++;
	}
	lines[i] = NULL;
	return (lines);
}

char	**split_lines_free(char **lines, int i)
{
	while (i > 0)
		free(lines[--i]);
	free(lines);
	return (NULL);
}

int	line_counter(const char *str)
{
	int	line_count;

	line_count = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			line_count++;
		str++;
	}
	if (*(str - 1) != '\n')
		line_count++;
	return (line_count);
}

int	get_line_length(const char *str, int line_number, char sep)
{
	int	line_count;
	int	line_length;
	int	i;

	i = 0;
	line_count = 0;
	while (str[i] != '\0' && line_count < line_number)
	{
		if (str[i] == sep || str[i] == '\0')
			line_count++;
		i++;
	}
	if (line_count == line_number)
	{
		line_length = 0;
		while (str[i] != '\0' && str[i] != sep)
		{
			line_length++;
			i++;
		}
		return (line_length);
	}
	return (-1);
}
