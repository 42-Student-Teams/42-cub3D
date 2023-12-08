/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:53:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/08 15:41:39 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_canvas *data, int x, int y, int color)
{
	data->addr[y * data->line_length / 4 + x] = color;
}

void	draw_ceiling(t_canvas *img, int val, int x, int color)
{
	int	i;

	i = -1;
	while (++i < val)
	{
		my_mlx_pixel_put(img, x, i, color);
	}
}

void	draw_floor(t_canvas *img, int val, int x, int color)
{
	while (++val < SCREEN_H)
		my_mlx_pixel_put(img, x, val, color);
}

void	draw_walls(int side, t_player *p, t_game *game, int x)
{
	int		color;

	walls_calculs(p, side);
	color = 0;
	while (p->cam.start <= p->cam.end)
	{
		p->tex_y = (int)p->tex_pos & p->texture[p->tex_dir].height - 1;
		color = p->texture[p->tex_dir].addr[p->tex_y
			* p->texture[p->tex_dir].line_length / 4 + p->tex_x];
		if (side == 0)
			color /= 2;
		p->tex_pos += p->step;
		my_mlx_pixel_put(&game->image, x, p->cam.start, color);
		p->cam.start++;
	}
}

void	draw_map(t_game *game, t_player *p)
{
	int	x;
	int	side;		

	x = -1;
	x = 0;
	side = 0;
	while (++x < SCREEN_W)
	{
		p->cam.camera_x = 2 * x / (double)(SCREEN_W) - 1;
		p->ray.dir.x = p->dir.x + p->plane.x * p->cam.camera_x;
		p->ray.dir.y = p->dir.y + p->plane.y * p->cam.camera_x;
		p->ray.square.x = (int)p->pos.x;
		p->ray.square.y = (int)p->pos.y;
		p->ray.delta_dist.x = fabs(1 / p->ray.dir.x);
		p->ray.delta_dist.y = fabs(1 / p->ray.dir.y);
		evaluate_ray(*p, &p->ray);
		dda_algorithme(game, &p->ray, &side);
		p->cam.wall_dist = find_wall_dist(p->ray, side);
		calculate_wall(&p->cam);
		draw_ceiling(&game->image, p->cam.start, x, game->ceiling);
		draw_walls(side, p, game, x);
		draw_floor(&game->image, p->cam.end, x, game->floor);
	}
	mlx_put_image_to_window(game->window.mlx, game->window.win,
		game->image.img, 0, 0);
}
