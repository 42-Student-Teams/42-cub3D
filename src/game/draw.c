/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:53:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/06 23:54:51 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_canvas *data, int x, int y, int color)
{
	data->addr[y * data->line_length / 4 + x] = color;
}

void	draw_line(t_canvas *img, int start, int end, int x, int color)
{

	while (start < end)
	{
		my_mlx_pixel_put(img, x, start, color);
		start++;
	}
}

void	draw_walls(int side, t_player *p, t_game *game, int x)
{
	int		color;

	walls_calculs(p, side);
	while (p->cam.start <= p->cam.end)
	{
		p->tex_y = (int)p->tex_pos & p->texture[p->tex_dir].height - 1;
		color =  p->texture[p->tex_dir].addr[p->tex_y * p->texture[p->tex_dir].line_length / 4 + p->tex_x];
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
	while (++x < SCREEN_W)
	{
		p->cam.camera_x =  2 * x / (double)(SCREEN_W) - 1; 
		p->ray.dir.x = p->dir.x + p->plane.x * p->cam.camera_x;
		p->ray.dir.y = p->dir.y + p->plane.y * p->cam.camera_x;
		p->ray.square.x = (int)p->pos.x;
		p->ray.square.y = (int)p->pos.y;
		p->ray.delta_dist.x =  fabs(1 / p->ray.dir.x);
		p->ray.delta_dist.y =  fabs(1 / p->ray.dir.y);
		evaluate_ray(*p, &p->ray);
		dda_algorithme(game, &p->ray, &side);
		p->cam.wall_dist = find_wall_dist(p->ray, side);
		calculate_wall(&p->cam);
		draw_line(&game->image, 0,p->cam.start, x, game->ceiling);
		draw_walls(side, p, game, x);
		draw_line(&game->image, p->cam.end, SCREEN_H, x, game->floor);
	}
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->image.img, 0, 0);
}
