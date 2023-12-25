/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:58 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 13:26:18 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//MAP
#define NO_Texture 0
#define SO_Texture 1
#define WE_Texture 2
#define EA_Texture 3

//
# define SW 640
# define SH 480
#define BUFFER_SIZE 1024

//MAP
typedef	struct s_file
{
	char	**map;
	int		**mapInt;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	verify[12];
	char	**lines;
	char	*whole_lines;
	int		map_h;
	int		map_w;
	int		line_count;
	int		fd;
}	t_file;

//GAME
typedef struct s_image
{
	void *img;
	int  *addr;
} t_image;

typedef struct s_texture
{
	double      step;
	double      texPos;
	int         lineH;
	int         floor;
    int         ceiling;
    int         drawStart;
    int         drawEnd;
    int    		texX;
    int   		texY;
	int         texWidth;
	int         texHeight;
	t_image     *imgNO;
	t_image     *imgSO;
	t_image     *imgWE;
	t_image     *imgEA;
}	t_texture;

typedef struct s_raycast
{
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
	double		rayDirX;
	double		rayDirY;
	double      cameraX;
	double      planeX;
    double      planeY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpwalldist;
	double      wallX;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
}   t_raycast;

typedef struct s_game
{
	void        *mlx;
	void        *mlxWin;
 	bool   w;
    bool   s;
    bool   a;
    bool   d;
    bool   left;
    bool   right;
	float  speed;
    float  rspeed;
	t_image     *img;
	t_texture   text;
	t_raycast   rayc;
	t_file		*file;
} t_game;

// //GAME
int		move_press(int key_code, t_game *g);
int		move_release(int key_code, t_game *g);
int		game_loop(t_game *g);
void 	raycast(t_game *g, t_file *fl);
void 	calculate(t_game *g);
void 	init2(t_game *g);
void 	init(t_game *g, int x);
void 	dda(t_game *g, t_file *fl);
void 	dda2(t_game *g);
void 	draw(t_game *g);
void 	draw2(t_game *g);
void 	draw3(t_game *g, int x, int y);
void 	movement_ws(t_game *g, t_file *fl);
void	movement_da(t_game *g, t_file *fl);
void 	rotate_right(t_game *g);
void 	rotate_left(t_game *g);
void	game_inits(t_game *g);
void	texture_init(t_game *g);
void	texture_init_next(t_game *g);
// void testMap(t_file *fl);
// int floodFill(t_file *fl, int i, int j, int size);
void	find_player(t_file *fl, t_game *g);
void 	playerpos_ns(t_file *fl, t_game *g, int i, int j);
void 	playerpos_we(t_file *fl, t_game *g, int i, int j);
void	game_inits(t_game *g);
void	inits_rgb(t_game *g);
int		create_rgb(int r, int g, int b);
int		press_close_key();

//MAP
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
void	ft_strcpy(char **destination, const char *source);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_checkset(char c, char const *set);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*set_textures(char *str);
char	*ft_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2);
char 	*read_file(t_file *fl);
void	file_parcer(t_file *file);
void	inits(t_file *fl);
void	find_textures(t_file *fl, int textures);
void	copy_textures(t_file *fl, int textures, int i);
char	**split_lines(const char *str, int line_count, size_t start, int i);
char	**split_lines_free(char **lines, int i);
int		line_counter(const char *str);
int 	get_line_length(const char *str, int line_number, char sep);
void	copy_rgb(t_file *fl, int comma_count, char type, int i);
void	find_rgb(t_file *fl, int f_count, int c_count, int i);
char	*set_rgb(char *str, int i, int count);
int		control_rgb_path(char *mainStr, char *subStr, size_t i, size_t j);
int		control_rgb_comma(char *kod);
char	**ft_split(char const *s, char c);
int		wordcounter(const char *s, char delimiter);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	find_map(t_file *fl);
char*	ft_strstr(const char* str, const char* substr);
int		control_components(char *map_line, int len, int count, int isspace);
void	map_size(t_file *fl);
void 	str_cpy(char *destination, const char *source);
void	map_control(t_file *fl);
void	map_name_control(char *map_name);

void	double_array_free(char **arr, int len);
void	game_free(t_game *g);
void	doubleint_array_free(int **arr, int len);

int control_rgb_comma(char *code);
int	split_and_validate_rgb(const char *code);
int count_commas(const char *code);
int validate_number(int num);



#endif