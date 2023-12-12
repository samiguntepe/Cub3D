/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:58 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/12 20:42:22 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "./include/libft/libft.h"


typedef	struct s_file
{
	char	**map;
	char	**textures;
	char	**colorRGB;
	char	**lines;
	int		*wrgLines;
	int		wrgLines_count;
	int		fd;
}	t_file;

typedef struct s_cub
{
	t_file	file;
	
}	t_cub;

char	*ft_strjoin_(char const *s1, char const *s2, char **leak);
void	control_components(char **map);
void	map_control(t_cub	*cub3d);
int		ncounter(char *map_file);



char 	*read_file(int fd);
void	file_parcer(t_file *file);
char	**file_parcer_textures(char **lines, char **textures);
void	inits(t_cub *cub3d);
int		*point_ignore_line(t_file	*fl);
int 	count_lines(t_file	*fl);

#endif