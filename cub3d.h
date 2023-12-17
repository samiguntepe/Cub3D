/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:58 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/17 16:33:59 by sguntepe         ###   ########.fr       */
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
	char	*F;
	char	*C;
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
char	*ft_strcpy(char *destination, const char *source);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_checkset(char c, char const *set);
char 	*strtok_custom(char *str, const char *delim);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*set_textures(char *str);

char	*ft_strjoin(char *str, char *add);
char 	*read_file(t_file *fl);
void	file_parcer(t_file *file);
void	inits(t_cub *cub3d);
void	find_textures(t_file *fl, int textures);

void	copy_textures(t_file *fl, int textures, int i);
char 	**split_lines(const char *str);
int		line_counter(const char *str);
void 	free_lines(char **lines, int line_count);
int 	get_line_length(const char *str, int line_number, char sep);
void	copy_RGB(t_file *fl, int comma_count, char type, int i);
void	find_RGB(t_file *fl);
char	*set_RGB(char *str);
int		control_RGB_path(char *mainStr, char *subStr);
int		control_RGB_comma(char *kod);

#endif