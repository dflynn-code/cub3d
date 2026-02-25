/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:32:52 by daflynn           #+#    #+#             */
/*   Updated: 2026/02/24 18:32:54 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->screen_height)
	{
		x = 0;
		while (x < game->screen_width)
		{
			if (y < game->screen_height / 2)
				mlx_pixel_put(game->mlx, game->win, x, y, 0x87CEEB);
			else
				mlx_pixel_put(game->mlx, game->win, x, y, 0x228B22);
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *game)
{
	int		x;
	int		map_x;
	int		map_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;
	int		color;

	draw_background(game);
	x = 0;
	while (x < game->screen_width)
	{
		camera_x = 2 * x / (double)game->screen_width - 1;
		ray_dir_x = game->dir_x + game->plane_x * camera_x;
		ray_dir_y = game->dir_y + game->plane_y * camera_x;
		map_x = (int)game->pos_x;
		map_y = (int)game->pos_y;
		delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
		delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);
		step_x = (ray_dir_x < 0) ? -1 : 1;
		step_y = (ray_dir_y < 0) ? -1 : 1;
		side_dist_x = (ray_dir_x < 0) * (game->pos_x - map_x) * delta_dist_x
			+ (ray_dir_x >= 0) * (map_x + 1.0 - game->pos_x) * delta_dist_x;
		side_dist_y = (ray_dir_y < 0) * (game->pos_y - map_y) * delta_dist_y
			+ (ray_dir_y >= 0) * (map_y + 1.0 - game->pos_y) * delta_dist_y;
		hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (game->world_map[map_x][map_y] > 0)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - game->pos_x + (1 - step_x) / 2)
				/ ray_dir_x;
		else
			perp_wall_dist = (map_y - game->pos_y + (1 - step_y) / 2)
				/ ray_dir_y;
		line_height = (int)(game->screen_height / perp_wall_dist);
		draw_start = -line_height / 2 + game->screen_height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + game->screen_height / 2;
		if (draw_end >= game->screen_height)
			draw_end = game->screen_height - 1;
		color = 0xFF0000;
		if (side == 1)
			color /= 2;
		y = draw_start;
		while (y < draw_end)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, color);
			y++;
		}
		x++;
	}
}
