#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		screen_width;
	int		screen_height;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		world_map[24][24];
}t_game;

void	init_game(t_game *game);
void	init_world_map(t_game *game);
void	render_frame(t_game *game);
void	draw_background(t_game *game);

#endif
