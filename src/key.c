/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:20 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/24 11:37:02 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int movePress(int keyCode, t_game *g)
{
	if (keyCode == 53)
	{
		game_free(g);
		// system("leaks cub3D");
		exit(0);
	}
    if (keyCode == 13)
        g->w = true;
    if (keyCode == 1)
        g->s = true;
    if (keyCode == 0)
        g->a = true;
    if (keyCode == 2)
        g->d = true;
    if (keyCode == 124)
        g->right = true;
    if (keyCode == 123)
        g->left = true;
    return (0);
}

int moveRelease(int keyCode, t_game *g)
{
    if (keyCode == 13)
        g->w = false;
    if (keyCode == 1)
        g->s = false;
    if (keyCode == 0)
        g->a = false;
    if (keyCode == 2)
        g->d = false;
    if (keyCode == 124)
        g->right = false;
    if (keyCode == 123)
        g->left = false;
    return (0);
}

int	press_close_key()
{
	printf("\n\033[0;35mGame is closed!\033[0m\n");
	exit(1);
}