/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:53:29 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 12:07:10 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	split_and_validate_rgb(const char *code)
{
	char	**ptr;
	int		i;
	int		num;

	ptr = ft_split(code, ',');
	i = 0;
	while (ptr[i])
	{
		num = ft_atoi(ptr[i]);
		if (!validate_number(num))
		{
			double_array_free(ptr, i);
			return (0);
		}
		i++;
	}
	if (i != 3)
	{
		double_array_free(ptr, i);
		return (0);
	}
	double_array_free(ptr, i);
	return (1);
}

int	control_rgb_comma(char *code)
{
	const int	required_commas = 2;

	if (count_commas(code) != required_commas)
		return (1);
	if (!split_and_validate_rgb(code))
		return (1);
	return (0);
}

int	validate_number(int num)
{
	return ((num >= 0) && (num <= 255));
}

int	count_commas(const char *code)
{
	int	commas;

	commas = 0;
	while (*code)
	{
		if (*code == ',')
			commas++;
		code++;
	}
	return (commas);
}
