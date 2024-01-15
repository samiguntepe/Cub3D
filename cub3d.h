/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:58 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/15 16:11:45 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <stdbool.h>
# include <unistd.h>

# define NO_TEXTURE 0
# define SO_TEXTURE 1
# define WE_TEXTURE 2
# define EA_TEXTURE 3
# define SW 1024
# define SH 768
# define BUFFER_SIZE 1024
# define RED "\033[0;31m"
# define CODE "\033[m"

typedef struct s_game	t_game;

typedef struct s_file
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	verify[12];
	char	**lines;
	char	*whole_lines;
	int		map_h;
	int		map_w;
	int		line_count;
	int		fd;
	int		*rowlen;
	char	**spc_map;
	int		max_len;
	t_game	*game;
}	t_file;

typedef struct s_image
{
	void	*img;
	int		*addr;
}	t_image;

typedef struct s_texture
{
	double		step;
	double		text_pos;
	int			line_h;
	int			floor;
	int			ceiling;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	int			text_w;
	int			text_h;
	t_image		*imgno;
	t_image		*imgso;
	t_image		*imgwe;
	t_image		*imgea;
	t_game		*game;
}	t_texture;

typedef struct s_raycast
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		raydir_x;
	double		raydir_y;
	double		camera_x;
	double		plane_x;
	double		plane_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	double		wall_x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}	t_raycast;

struct s_game
{
	void		*mlx;
	void		*mlxwin;
	bool		w;
	bool		s;
	bool		a;
	bool		d;
	bool		left;
	bool		right;
	float		speed;
	float		rspeed;
	t_image		*img;
	t_texture	text;
	t_raycast	ray;
	t_file		*file;
	int			control;
};

int		move_press(int key_code, t_game *g);
int		move_release(int key_code, t_game *g);
int		game_loop(t_game *g);
void	raycast(t_game *g, t_file *fl);
void	calculate(t_game *g);
void	init2(t_game *g);
void	init(t_game *g, int x);
void	dda(t_game *g, t_file *fl);
void	dda2(t_game *g);
void	draw(t_game *g);
void	draw2(t_game *g);
void	draw3(t_game *g, int x, int y);
void	movement_ws(t_game *g, t_file *fl);
void	movement_da(t_game *g, t_file *fl);
void	rotate_right(t_game *g);
void	rotate_left(t_game *g);
void	texture_init(t_game *g);
void	find_player(t_file *fl, t_game *g);
void	playerpos_ns(t_file *fl, t_game *g, int i, int j);
void	playerpos_we(t_file *fl, t_game *g, int i, int j);
void	inits_rgb(t_game *g);
int		create_rgb(int r, int g, int b);
int		close_window(void *game);
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
char	*read_file(t_file *fl);
void	file_parcer(t_file *file);
void	find_textures(t_file *fl, int textures);
void	copy_textures(t_file *fl, int textures, int i);
char	**split_lines(const char *str, int line_count, size_t start, int i);
char	**split_lines_free(char **lines, int i);
int		line_counter(const char *str);
int		get_line_length(const char *str, int line_number, char sep);
void	copy_rgb(t_file *fl, int comma_count, char type, int i);
void	find_rgb(t_file *fl, int f_count, int c_count, int i);
int		control_rgb_path(char *mainStr, char *subStr, size_t i, size_t j);
char	**ft_split(char const *s, char c);
int		wordcounter(const char *s, char delimiter);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	find_map(t_file *fl);
char	*ft_strstr(const char *str, const char *substr);
int		control_components(char *map_line, int len, int count, int isspace);
void	map_size(t_file *fl);
void	str_cpy(char *destination, const char *source);
void	map_name_control(char *map_name);
void	double_array_free(char **arr);
void	control_rgb_comma(char *code, t_game *game);
int		split_and_validate_rgb(const char *code);
int		count_commas(const char *code);
int		validate_number(int num);
void	sur_control(t_file *fl);
void	loc_around_space(t_file *fl, int i);
void	test(t_file *fl, int map_h);
int		space_diagon(t_file *fl, int row, int col, int rows);
int		is_map_valid(t_file *fl, int rows);
void	fill_row_map_data(char *row, const char *map_row, size_t max_length);
void	init_row_spaces(char *row, size_t length);
size_t	find_max_len(t_file *fl);
void	around_space(t_file *fl);
int		check_map_char(t_file *fl, int rows);
void	fill_row_len(t_file *fl, int rows);
void	loc_row_len(t_file *fl, int rows);
void	control_companent(t_file *fl, int i, int j);
int		space_around(t_file *fl, int row, int col, int rows);
t_file	*init_t_file(void);
t_image	*init_t_image(void);
void	init_t_texture(t_texture *texture);
void	inits(t_game *game);
void	init_t_raycast(t_raycast *raycast);
void	init_t_game(t_game *game);
void	upload_image(t_game *g);
void	next(t_game *g);
void	free_space_map(char **spc_map);
void	free_game(t_game *game);
void	free_file(t_file *file);
void	free_texture(t_texture *tex);
void	exit_game(t_game *game, char *msg);
void	control_companent_count(t_file *fl, int i);

#endif