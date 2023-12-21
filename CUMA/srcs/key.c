#include "../cub3D.h"

int movePress(int keyCode, t_game *g)
{
	if (keyCode == 53)
	{
		// all free
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