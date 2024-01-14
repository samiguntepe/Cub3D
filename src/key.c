/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:20 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/14 22:24:42 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_press(int key_code, t_game *g)
{
	if (key_code == 53)
	{
		free_game(g);
		printf("Game is closed.\n");
		exit(0);
	}
	if (key_code == 13)
		g->w = true;
	if (key_code == 1)
		g->s = true;
	if (key_code == 0)
		g->a = true;
	if (key_code == 2)
		g->d = true;
	if (key_code == 124)
		g->right = true;
	if (key_code == 123)
		g->left = true;
	return (0);
}

int	move_release(int key_code, t_game *g)
{
	if (key_code == 13)
		g->w = false;
	if (key_code == 1)
		g->s = false;
	if (key_code == 0)
		g->a = false;
	if (key_code == 2)
		g->d = false;
	if (key_code == 124)
		g->right = false;
	if (key_code == 123)
		g->left = false;
	return (0);
}

int	press_close_key(void)
{
	printf("\n\033[0;35mGame is closed!\033[0m\n");
	exit(1);
}
