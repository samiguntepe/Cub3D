#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct s_image
{
	void *image;
	int  *addr;
	int  number;
} t_image;
typedef struct game
{
	void   *mlx;
	void   *mlxWin;
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double cameraX;
    double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	double wallX;
    double rayDirX;
    double rayDirY;
    double step;
    double texPos;
    int    color;
	int    mapX;
	int	   mapY;
	int	   stepX;
	int	   stepY;
	int	   hit;
	int	   side;
	int    lineH;
	int    floor;
    int    ceiling;
    int    drawStart;
    int    drawEnd;
    int    texX;
    int    texY;
    int    texH;
    int    texW;
    bool   w;
    bool   s;
    bool   a;
    bool   d;
    bool   left;
    bool   right;
    float  speed;
    float  rspeed;
    t_image *NO;
	t_image *SO;
	t_image *WE;
	t_image *EA;
    t_image *image;
    char **map;
} g;
# define SW 640
# define SH 480
# define  texWidth 64
# define  texHeight 64
void raycast(g *g)
{
    int x = 0;
    while (x < SW)
    {
        g->cameraX = 2 * x / (double)SW - 1;
        g->rayDirX = g->dirX + g->planeX * g->cameraX;
        g->rayDirY = g->dirY + g->planeY * g->cameraX;
        g->mapX = (int)g->posX;
        g->mapY = (int)g->posY;

	    if (g->rayDirX == 0)
		    g->deltaDistX = 1;
	    else
		    g->deltaDistX = fabs(1 / g->rayDirX);
	    if (g->rayDirY == 0)
		    g->deltaDistY = 1;
	    else
		    g->deltaDistY = fabs(1 / g->rayDirY);
        

        if (g->rayDirX < 0)
        {
            g->stepX = -1;
            g->sideDistX = (g->posX - g->mapX) * g->deltaDistX;
        }
        else 
        {
            g->stepX = 1;
            g->sideDistX = (g->mapX + 1.0 - g->posX) * g->deltaDistX;
        }
        if (g->rayDirY < 0)
        {
            g->stepY = -1;
            g->sideDistY = (g->posY - g->mapY) * g->deltaDistY;
        }
        else 
        {
            g->stepY = 1;
            g->sideDistY = (g->mapY + 1.0 - g->posY) * g->deltaDistY;
        }

        g->hit = 0;
        while (g->hit == 0)
        {
            if (g->sideDistX < g->sideDistY)
            {
                g->sideDistX += g->deltaDistX;
                g->mapX += g->stepX;
                g->side = 0;
            }
            else 
            {
                g->sideDistY += g->deltaDistY;
                g->mapY += g->stepY;
                g->side = 1;
            }
            if (g->map[g->mapY][g->mapX] == '1')
                g->hit = 1;
        }
        
        if (g->side == 0)
            g->perpWallDist = g->sideDistX - g->deltaDistX;
        else 
            g->perpWallDist = g->sideDistY - g->deltaDistY;
        g->lineH = (int)(SH / g->perpWallDist);

        g->drawStart = -g->lineH / 2 + SH / 2;
        if (g->drawStart < 0)
            g->drawStart = 0;
        g->drawEnd = g->lineH / 2 + SH / 2;
        if (g->drawEnd >= SH)
            g->drawEnd = SH - 1;
        
        if (g->side == 0)
            g->wallX = g->posY + g->perpWallDist * g->rayDirY;
        else 
            g->wallX = g->posX + g->perpWallDist * g->rayDirX;
        g->wallX = g->wallX - (int)g->wallX;

        
        g->texX = (int)(g->wallX * (double)texWidth);
        if (g->side == 0 && g->rayDirX > 0)
            g->texX = texWidth - g->texX - 1;
        if (g->side == 1 && g->rayDirY < 0)
            g->texX = texWidth - g->texX - 1;
 

        g->step = 1.0 * texHeight / g->lineH;
        g->texPos = (g->drawStart - SH / 2 + g->lineH / 2) * g->step;

        
        int y = 0;
        while (y < SH)
        {
            g->texY = (int)g->texPos;
            if (y < g->drawStart)
                g->image->addr[y * SW + x] = g->floor;
            else if (y > g->drawEnd)
                g->image->addr[y * SW + x] = g->ceiling;
            else 
            {
                if (g->side == 1 && g->rayDirY < 0)
                    g->image->addr[y * SW + x] = g->NO->addr[texHeight * g->texY + g->texX];
                else if (g->side == 1 && g->rayDirY > 0)
                    g->image->addr[y * SW + x] = g->NO->addr[texHeight * g->texY + g->texX];
                if (g->side == 0 && g->rayDirX < 0)
                    g->image->addr[y * SW + x] = g->NO->addr[texHeight * g->texY + g->texX];
                else if (g->side == 0 && g->rayDirX > 0)
                    g->image->addr[y * SW + x] = g->NO->addr[texHeight * g->texY + g->texX];
                g->texPos += g->step;
            }
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(g->mlx, g->mlxWin, g->image->image, 0, 0);
}
int movePress(int keyCode, g *g)
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
int moveRelease(int keyCode, g *g)
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
void movement(g *g)
{
    if (g->w)
    {
        if (g->map[(int)(g->posY)][(int)(g->posX + g->dirX * g->speed)] != '1')
            g->posX += g->dirX * g->speed;
        if (g->map[(int)(g->posY + g->dirY * g->speed)][(int)(g->posX)] != '1')
            g->posY += g->dirY * g->speed;
    }
    if (g->d)
    {
        if (g->map[(int)(g->posY)][(int)(g->posX + g->planeX * g->speed)] != '1')
            g->posX += g->planeX * g->speed;
        if (g->map[(int)(g->posY + g->planeY * g->speed)][(int)(g->posX)] != '1')
            g->posY += g->planeY * g->speed;
    }
    if (g->s)
    {
        if (g->map[(int)(g->posY)][(int)(g->posX - g->dirX * g->speed)] != '1')
            g->posX -= g->dirX * g->speed;
        if (g->map[(int)(g->posY - g->dirY * g->speed)][(int)(g->posX)] != '1')
            g->posY -= g->dirY * g->speed;
    }
    if (g->a)
    {
        if (g->map[(int)(g->posY)][(int)(g->posX - g->planeX * g->speed)] != '1')
            g->posX -= g->planeX * g->speed;
        if (g->map[(int)(g->posY - g->planeY * g->speed)][(int)(g->posX)] != '1')
            g->posY -= g->planeY * g->speed;
    }
}
void rotate(g *g)
{
    double oldDirX;
    double oldPlaneX;


    if (g->left)
    {
        oldDirX = g->dirX;
        g->dirX = g->dirX * cos(g->rspeed) - g->dirY * sin(g->rspeed);
        g->dirY = oldDirX * sin(g->rspeed) + g->dirY * cos(g->rspeed);


        oldPlaneX = g->planeX;
        g->planeX = g->planeX * cos(g->rspeed) - g->planeY * sin(g->rspeed);
        g->planeY = oldPlaneX * sin(g->rspeed) + g->planeY * cos(g->rspeed);
    }   
    if (g->right)
    {
	    oldPlaneX = g->dirX;
	    g->dirX = g->dirX * cos(g->rspeed) + g->dirY * sin(g->rspeed);
	    g->dirY = -oldPlaneX * sin(g->rspeed) + g->dirY * cos(g->rspeed);
	
	    oldPlaneX = g->planeX;
	    g->planeX = g->planeX * cos(g->rspeed) + g->planeY * sin(g->rspeed);
	    g->planeY = -oldPlaneX * sin(g->rspeed) + g->planeY * cos(g->rspeed);
    }
}
int game(g *g)
{
    movement(g);
    rotate(g);
    raycast(g);

    return (0);
}
void createMap(g *g)
{
    int size = 10;
    int i, j;

    g->map = (char **)malloc(size * sizeof(char *));
    for (i = 0; i < size; i++) {
        g->map[i] = (char *)malloc(size * sizeof(char));
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                g->map[i][j] = '1';
            else
                g->map[i][j] = '0';
        }
    }

    /*
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%c ", g->map[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < size; i++) {
        free(g->map[i]);
    }
    free(g->map);
    */
    

}
int create_trgb(int t, int r, int g, int b) {
    return (t << 24 | r << 16 | g << 8 | b);
}
int main()
{
    g g;
    g.posX = 1 + 0.5;
    g.posY = 1 + 0.5;
    g.dirX = 0;
    g.dirY = 1;
    g.planeX = 0.66;
    g.planeY = 0;
    g.speed = 0.100f;
    g.rspeed = 0.05f;

    g.floor = create_trgb(0, 50, 150, 150);
    g.ceiling = create_trgb(0, 100, 100, 255);
    int a;
    createMap(&g);
    g.w = false;
    g.a = false;
    g.s = false;
    g.d = false;
    g.left = false;
    g.right = false;
    g.mlx = mlx_init();
    g.mlxWin = mlx_new_window(g.mlx, SW, SH, "cub3D");
    g.image = malloc(sizeof(t_image));
    g.image->image = mlx_new_image(g.mlx, SW, SH);
    g.image->addr = (int*)mlx_get_data_addr(g.image->image, &a, &a, &a);
    int b;
    char *path = "./42N.xpm";
    g.NO = malloc(sizeof(t_image));
    if (!g.NO)
    {
        printf("%s\n", "error");
        return (1);
    }
    int k;
    g.NO->image = mlx_xpm_file_to_image(g.mlx, path, &b, &b);
    g.NO->addr = (int *)mlx_get_data_addr(g.NO->image, &k, &k, &k);
    mlx_hook(g.mlxWin, 2, 1L << 0, movePress, &g);
    mlx_hook(g.mlxWin, 3, 1L << 1, moveRelease, &g);
    mlx_loop_hook(g.mlx, &game, &g);
    mlx_loop(g.mlx);
    return (0);
}