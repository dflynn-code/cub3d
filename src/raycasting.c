/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:32:52 by daflynn           #+#    #+#             */
/*   Updated: 2026/02/28 14:12:46 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

<<<<<<< HEAD
int	is_wall(t_game *game, int x, int y)
=======
typedef struct s_ray
{
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
	int		color;
}	t_ray;

void	draw_background(t_game *game)
>>>>>>> 550d5f60007a8949cee11e61a67c713c4c998634
{
	if (x < 0 || y < 0 || y >= game->map_height)
		return (1);
	if (x >= (int)ft_strlen(game->map[y]))
		return (1);
	return (game->map[y][x] == '1' || game->map[y][x] == ' ');
}

static void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)game->screen_width - 1;
	ray->ray_dir_x = game->dir_x + game->plane_x * ray->camera_x;
	ray->ray_dir_y = game->dir_y + game->plane_y * ray->camera_x;
	ray->map_x = (int)game->pos_x;
	ray->map_y = (int)game->pos_y;
	ray->delta_dist_x = (ray->ray_dir_x == 0) * 1e30
		+ (ray->ray_dir_x != 0) * fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = (ray->ray_dir_y == 0) * 1e30
		+ (ray->ray_dir_y != 0) * fabs(1 / ray->ray_dir_y);
	ray->step_x = (ray->ray_dir_x < 0) * -1 + (ray->ray_dir_x > 0);
	ray->step_y = (ray->ray_dir_y < 0) * -1 + (ray->ray_dir_y > 0);
	ray->side_dist_x = (ray->ray_dir_x < 0) * (game->pos_x - ray->map_x)
		* ray->delta_dist_x + (ray->ray_dir_x >= 0)
		* (ray->map_x + 1.0 - game->pos_x) * ray->delta_dist_x;
	ray->side_dist_y = (ray->ray_dir_y < 0) * (game->pos_y - ray->map_y)
		* ray->delta_dist_y + (ray->ray_dir_y >= 0)
		* (ray->map_y + 1.0 - game->pos_y) * ray->delta_dist_y;
	ray->hit = 0;
}

static void	cast_ray_until_hit(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_wall(game, ray->map_x, ray->map_y))
			ray->hit = 1;
	}
}

<<<<<<< HEAD
static void	compute_wall_slice(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
=======
static void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)game->screen_width - 1;
	ray->ray_dir_x = game->dir_x + game->plane_x * ray->camera_x;
	ray->ray_dir_y = game->dir_y + game->plane_y * ray->camera_x;
	ray->map_x = (int)game->pos_x;
	ray->map_y = (int)game->pos_y;
	ray->delta_dist_x = (ray->ray_dir_x == 0) * 1e30 +
		(ray->ray_dir_x != 0) * fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = (ray->ray_dir_y == 0) * 1e30 +
		(ray->ray_dir_y != 0) * fabs(1 / ray->ray_dir_y);
	ray->step_x = (ray->ray_dir_x < 0) * -1 + (ray->ray_dir_x >= 0);
	ray->step_y = (ray->ray_dir_y < 0) * -1 + (ray->ray_dir_y >= 0);
	ray->side_dist_x = (ray->ray_dir_x < 0) * (game->pos_x - ray->map_x)
		* ray->delta_dist_x + (ray->ray_dir_x >= 0)
		* (ray->map_x + 1.0 - game->pos_x) * ray->delta_dist_x;
	ray->side_dist_y = (ray->ray_dir_y < 0) * (game->pos_y - ray->map_y)
		* ray->delta_dist_y + (ray->ray_dir_y >= 0)
		* (ray->map_y + 1.0 - game->pos_y) * ray->delta_dist_y;
	ray->hit = 0;
}

static void	cast_ray_until_hit(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->world_map[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

static void	compute_wall_slice(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->pos_x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->pos_y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
>>>>>>> 550d5f60007a8949cee11e61a67c713c4c998634
	ray->line_height = (int)(game->screen_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->screen_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->screen_height / 2;
	if (ray->draw_end >= game->screen_height)
		ray->draw_end = game->screen_height - 1;
<<<<<<< HEAD
=======
	ray->color = 0xFF0000;
	if (ray->side == 1)
		ray->color /= 2;
}

static void	draw_wall_column(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, ray->color);
		y++;
	}
>>>>>>> 550d5f60007a8949cee11e61a67c713c4c998634
}

void	render_frame(t_game *game)
{
	t_ray	ray;
	int		x;
<<<<<<< HEAD
=======
	t_ray	ray;
>>>>>>> 550d5f60007a8949cee11e61a67c713c4c998634

	draw_background(game);
	x = 0;
	while (x < game->screen_width)
	{
		init_ray(game, &ray, x);
		cast_ray_until_hit(game, &ray);
		compute_wall_slice(game, &ray);
		draw_wall_column(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
