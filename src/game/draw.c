/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:53:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/09 11:26:14 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

static void	set_evaluation_values(t_player *p, int x)
{
	p->cam.camera_x = 2 * x / (double)(SCREEN_W) - 1;
	p->ray.dir.x = p->dir.x + p->plane.x * p->cam.camera_x;
	p->ray.dir.y = p->dir.y + p->plane.y * p->cam.camera_x;
	p->ray.square.x = (int)p->pos.x;
	p->ray.square.y = (int)p->pos.y;
	p->ray.delta_dist.x = fabs(1 / p->ray.dir.x);
	p->ray.delta_dist.y = fabs(1 / p->ray.dir.y);
}

int	draw_map(t_player *p)
{
	int	x;
	int	side;		

	x = -1;
	side = 0;
	while (++x < SCREEN_W)
	{
		set_evaluation_values(p, x);
		evaluate_ray(*p, &p->ray);
		dda_algorithme(p->game, &p->ray, &side);
		p->cam.wall_dist = find_wall_dist(p->ray, side);
		calculate_wall(&p->cam);
		draw_ceiling(&p->game->image, p->cam.start, x, p->game->ceiling);
		draw_walls(side, p, p->game, x);
		draw_floor(&p->game->image, p->cam.end, x, p->game->floor);
	}
	mlx_put_image_to_window(p->game->window.mlx, p->game->window.win,
		p->game->image.img, 0, 0);
	move(p);
	return (0);
}
