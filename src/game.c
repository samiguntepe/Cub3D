
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




int game(g *g)
{
    movement(g);
    rotate(g);
    raycast(g);

    return (0);
}

int main()
{
    
    
   
    
  
}