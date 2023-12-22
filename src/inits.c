/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:56 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/22 09:15:23 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	inits(t_file *fl)
{
	char	*ptr;

	fl->EA = NULL;
	fl->SO = NULL;
	fl->WE = NULL;
	fl->NO = NULL;
	fl->C = NULL;
	fl->F = NULL;
	fl->map_h = 0;
	fl->map_w = 0;
	fl->control_index[0] = NULL;
	fl->control_index[1] = NULL;
	ptr = fl->verify;
	ft_strcpy(&ptr, "NO SO WE EA ");
}

// void	game_inits(t_game *g)
// {
// 	g->w = false;
//     g->a = false;
//     g->s = false;
//     g->d = false;
//     g->left = false;
//     g->right = false;
// }
