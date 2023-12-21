#ifndef CUB3D_H
# define CUB3D_H

# define SW 640
# define SH 480


#include "minilibx/mlx.h"
#include <stdbool.h>

typedef struct s_image
{
	void *i;
	int  *addr;
	int  nbr;
} t_image;

typedef struct s_texture
{
	double      step;
	double      texPos;
	int         lineH;
	int         floor;
    int         ceiling;
    int         drawStart;
    int         drawEnd;
    int    		texX;
    int   		texY;
	int         texWidth;
	int         texHeight;
	t_image     *NO;
	t_image     *SO;
	t_image     *WE;
	t_image     *EA;
}	t_texture;

typedef struct s_raycast
{
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
	double		rayDirX;
	double		rayDirY;
	double      cameraX;
	double      planeX;
    double      planeY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpwalldist;
	double      wallX;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
}   t_raycast;

typedef struct s_game
{
	void        *mlx;
	void        *mlxWin;
 	bool   w;
    bool   s;
    bool   a;
    bool   d;
    bool   left;
    bool   right;
	float  speed;
    float  rspeed;
	t_image     *img;
	t_texture   t;
	t_raycast   r;

    char        **map;
} t_game;







int movePress(int keyCode, t_game *g);
int moveRelease(int keyCode, t_game *g);
int game(t_game *g);


#endif 