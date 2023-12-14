/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:58 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/14 10:50:01 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>

typedef	struct s_file
{
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	**colorRGB;
	char	**lines;
	int		*wrgLines;
	char	*whole_lines;
	int		wrgLines_count;
	int		fd;
}	t_file;

typedef struct s_cub
{
	t_file	file;
	
}	t_cub;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);



char	*ft_strjoin_(char const *s1, char const *s2, char **leak);
char 	*read_file(t_file *file);
void	file_parcer(t_file *file);
char	**file_parcer_textures(char **lines, char **textures);
void	inits(t_cub *cub3d);
int		*point_ignore_line(t_file	*fl);
void	count_wrgLine(t_file *fl);

char 	**split_lines(const char *str);
int	line_counter(const char *str);
void 	free_lines(char **lines, int line_count);
int 	get_line_length(const char *str, int line_number, char sep);

#endif