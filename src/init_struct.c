#include "../cub3d.h"

void	init_struct(t_game *g)
{
	g->file = (t_file *)malloc(sizeof(t_file));
	g->img = (t_image *)malloc(sizeof(t_image));
}