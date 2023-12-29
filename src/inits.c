/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:56 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/29 16:14:20 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <unistd.h>

void	inits(t_game *game)
{
	game->file = init_t_file();
	game->img = init_t_image();
	init_t_texture(&game->text);
	texture_init(game);
	init_t_game(game);
	init_t_raycast(&game->rayc);
	
}

t_image *init_t_image(void)
{
    t_image *new_image;

	new_image = malloc(sizeof(t_image));
    if (new_image == NULL)
        return NULL;
    // new_image->img = NULL;
    // new_image->addr = NULL;
    return (new_image);
}

t_file	*init_t_file(void)
{
    t_file *new_file;
	char	*ptr;
	
	new_file = malloc(sizeof(t_file));
    if (new_file == NULL)
        return NULL;
	ptr = new_file->verify;
	ft_strcpy(&ptr, "NO SO WE EA ");
    new_file->map = NULL;
    new_file->NO = NULL;
    new_file->SO = NULL;
    new_file->WE = NULL;
    new_file->EA = NULL;
    new_file->F = NULL;
    new_file->C = NULL;
    new_file->lines = NULL;
    new_file->whole_lines = NULL;
    new_file->map_h = 0;
    new_file->map_w = 0;
    new_file->line_count = 0;
    new_file->fd = -1;
    new_file->rowlen = NULL;
    new_file->spc_map = NULL;
    new_file->max_len = 0;
    return (new_file);
}

void	init_t_texture(t_texture *texture)
{
	texture->step = 0.0;
    texture->texPos = 0.0;
    texture->lineH = 0;
    texture->floor = 0;
    texture->ceiling = 0;
    texture->drawStart = 0;
    texture->drawEnd = 0;
    texture->texX = 0;
    texture->texY = 0;
    texture->texWidth = 0;
    texture->texHeight = 0;
    texture->imgNO = NULL;
    texture->imgSO = NULL;
    texture->imgWE = NULL;
    texture->imgEA = NULL;
}

void	init_t_raycast(t_raycast *raycast)
{
	raycast->posX = 0.0;
    raycast->posY = 0.0;
    raycast->dirX = 0.0;
    raycast->dirY = 0.0;
    raycast->rayDirX = 0.0;
    raycast->rayDirY = 0.0;
    raycast->cameraX = 0.0;
    raycast->planeX = 0.0;
    raycast->planeY = 0.0;
    raycast->sideDistX = 0.0;
    raycast->sideDistY = 0.0;
    raycast->deltaDistX = 0.0;
    raycast->deltaDistY = 0.0;
    raycast->perpwalldist = 0.0;
    raycast->wallX = 0.0;
    raycast->mapX = 0;
    raycast->mapY = 0;
    raycast->stepX = 0;
    raycast->stepY = 0;
    raycast->hit = 0;
    raycast->side = 0;
}

void	init_t_game(t_game *game)
{
	game->w = false;
	game->a = false;
	game->s = false;
	game->d = false;
	game->left = false;
	game->right = false;
	game->speed = 0.100f;
	game->rspeed = 0.05f;
	game->text.texHeight = 64;
	game->text.texWidth = 64;
}

void	inits_rgb(t_game *g)
{
	char	**ptr_f;
	char	**ptr_c;

	ptr_f = ft_split(g->file->F, ',');
	ptr_c = ft_split(g->file->C, ',');
	g->text.floor
		= create_rgb(ft_atoi(ptr_f[0]),
			ft_atoi(ptr_f[1]), ft_atoi(ptr_f[2]));
	g->text.ceiling
		= create_rgb(ft_atoi(ptr_c[0]),
			ft_atoi(ptr_c[1]), ft_atoi(ptr_c[2]));
	double_array_free(ptr_f, 3);
	double_array_free(ptr_c, 3);
}

void	texture_init(t_game *g)
{
	g->text.imgNO = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		exit(printf("Error\n"));
	else
		printf("yer açıldı");
	g->text.imgSO = malloc(sizeof(t_image));
	if (!g->text.imgSO)
		exit(printf("Error\n"));
	g->text.imgWE = malloc(sizeof(t_image));
	if (!g->text.imgWE)
		exit(printf("Error\n"));
	g->text.imgEA = malloc(sizeof(t_image));
	if (!g->text.imgEA)
		exit(printf("Error\n"));
}

void	upload_image(t_game *g)
{
	int	n;
	int	k;
	
	g->text.imgNO->img = mlx_xpm_file_to_image(g->mlx, g->file->NO, &n, &n);
	if (g->text.imgNO->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgSO->img = mlx_xpm_file_to_image(g->mlx, g->file->SO, &n, &n);
	if (g->text.imgSO->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgEA->img = mlx_xpm_file_to_image(g->mlx, g->file->EA, &n, &n);
	if (g->text.imgEA->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgWE->img = mlx_xpm_file_to_image(g->mlx, g->file->WE, &n, &n);
	if (g->text.imgWE->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgNO->addr
		= (int *)mlx_get_data_addr(g->text.imgNO->img, &k, &k, &k);
	g->text.imgSO->addr
		= (int *)mlx_get_data_addr(g->text.imgSO->img, &k, &k, &k);
	g->text.imgEA->addr
		= (int *)mlx_get_data_addr(g->text.imgEA->img, &k, &k, &k);
	g->text.imgWE->addr
		= (int *)mlx_get_data_addr(g->text.imgWE->img, &k, &k, &k);
}
