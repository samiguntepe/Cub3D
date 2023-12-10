/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:58 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/10 09:21:29 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_cub
{
	char	**map;
}	t_cub;

char	*read_mapfile(int fd);
char	*ft_strjoin_(char const *s1, char const *s2, char **leak);
void	control_components(char **map);
void	inits(t_cub	*cub3d, int fd);
void	map_control(t_cub	*cub3d);

#endif