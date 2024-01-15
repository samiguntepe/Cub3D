/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:56 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/15 12:17:33 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

t_image	*init_t_image(void)
{
	t_image	*new_image;

	new_image = malloc(sizeof(t_image));
	if (new_image == NULL)
		return (NULL);
	new_image->img = NULL;
	new_image->addr = NULL;
	return (new_image);
}

t_file	*init_t_file(void)
{
	t_file	*new_file;
	char	*ptr;

	new_file = malloc(sizeof(t_file));
	if (new_file == NULL)
		return (NULL);
	ptr = new_file->verify;
	ft_strcpy(&ptr, "NO SO WE EA ");
	new_file->map = NULL;
	new_file->no = NULL;
	new_file->so = NULL;
	new_file->we = NULL;
	new_file->ea = NULL;
	new_file->f = NULL;
	new_file->c = NULL;
	new_file->lines = NULL;
	new_file->whole_lines = NULL;
	new_file->map_h = 0;
	new_file->map_w = 0;
	new_file->line_count = 0;
	new_file->rowlen = NULL;
	new_file->spc_map = NULL;
	new_file->max_len = 0;
	return (new_file);
}

void	init_t_texture(t_texture *texture)
{
	texture->step = 0.0;
	texture->text_pos = 0.0;
	texture->line_h = 0;
	texture->floor = 0;
	texture->ceiling = 0;
	texture->draw_start = 0;
	texture->draw_end = 0;
	texture->tex_x = 0;
	texture->tex_y = 0;
	texture->text_w = 0;
	texture->text_h = 0;
	texture->imgno = NULL;
	texture->imgso = NULL;
	texture->imgwe = NULL;
	texture->imgea = NULL;
}

void	init_t_raycast(t_raycast *raycast)
{
	raycast->pos_x = 0.0;
	raycast->pos_y = 0.0;
	raycast->dir_x = 0.0;
	raycast->dir_y = 0.0;
	raycast->raydir_x = 0.0;
	raycast->raydir_y = 0.0;
	raycast->camera_x = 0.0;
	raycast->plane_x = 0.0;
	raycast->plane_y = 0.0;
	raycast->sidedist_x = 0.0;
	raycast->sidedist_y = 0.0;
	raycast->deltadist_x = 0.0;
	raycast->deltadist_y = 0.0;
	raycast->perpwalldist = 0.0;
	raycast->wall_x = 0.0;
	raycast->map_x = 0;
	raycast->map_y = 0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->hit = 0;
	raycast->side = 0;
}

void	init_t_game(t_game *game)
{
	game->mlx = NULL;
	game->mlxwin = NULL;
	game->w = false;
	game->a = false;
	game->s = false;
	game->d = false;
	game->left = false;
	game->right = false;
	game->speed = 0.100f;
	game->rspeed = 0.05f;
	game->text.text_h = 64;
	game->text.text_w = 64;
	game->control = 0;
}
