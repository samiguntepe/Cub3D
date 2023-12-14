/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:58 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/14 17:08:37 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>



#define NO_Texture 0
#define SO_Texture 1
#define WE_Texture 2
#define EA_Texture 3

typedef	struct s_file
{
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	verify[12];
	char	**lines;
	char	*whole_lines;
	int		fd;
}	t_file;

typedef struct s_cub
{
	t_file	file;
	
}	t_cub;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
void	ft_strcpy(char *destination, const char *source);


char	*ft_strjoin_(char const *s1, char const *s2, char **leak);
char 	*read_file(t_file *file);
void	file_parcer(t_file *file);
void	inits(t_cub *cub3d);
void	copy_textures(t_file *fl, int textures, int i, int j, int k);
void	find_textures(t_file *fl, int textures);

char 	**split_lines(const char *str);
int		line_counter(const char *str);
void 	free_lines(char **lines, int line_count);
int 	get_line_length(const char *str, int line_number, char sep);

#endif