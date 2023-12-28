#include "../cub3d.h"

int close_window(void *game)
{
    t_game *g = (t_game *)game;
    mlx_destroy_window(g->mlx, g->mlxWin);
	exit(1);
    return (0);
}