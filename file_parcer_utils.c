#include "cub3d.h"
#include <stdlib.h>

void	find_textures(t_file *fl, int textures)
{
	
	int	i;
	int	j;
	int k;
	int	m;
	

	k = 0;
	i = 0;
	m = 3 * textures;
	while (fl->lines[i])
	{
		j = 0;
		while (fl->lines[i][j] != '\0')
		{
			if (fl->lines[i][0] == fl->verify[m])
				if (fl->lines[i][1] == fl->verify[m +1])
					if (fl->lines[i][2] == fl->verify[m +2])
					{
						copy_textures(fl, textures, i, j, k);
						k++;
					}
			j++;
		}
		i++;
	}
}

void	copy_textures(t_file *fl, int textures, int i, int j, int k)
{
	if (textures == NO_Texture)
		fl->NO[k] = fl->lines[i][j];
	else if (textures == SO_Texture)
		fl->SO[k] = fl->lines[i][j];
	else if (textures == WE_Texture)
		fl->WE[k] = fl->lines[i][j];
	else if (textures == EA_Texture)
	fl->EA[k] = fl->lines[i][j];
	else
	{
		perror("Wrong, texture path!");
	}
}

