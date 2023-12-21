#include "../cub3D.h"


int main(int argc, char *argv[])
{
    t_game g;





    keyinit(&g);

    g.mlx = mlx_init();
    g.mlxWin = mlx_new_window(g.mlx, SW, SH, "cub3D");
    g.img = malloc(sizeof(t_image)); 
    g.img->i = mlx_new_image(g.mlx, SW, SH);
    g.img->addr = (int *)mlx_get_data_addr(g.img->i, &g.img->nbr, &g.img->nbr, &g.img->nbr);
    
    mlx_hook(g.mlxWin, 2, 1L<<0, movePress, &g);
    mlx_hook(g.mlxWin, 3, 1L<<1, moveRelease, &g);
    mlx_hook_loop(g.mlx, &game, &g);
    mlx_loop(g.mlx);
    return (0);
}