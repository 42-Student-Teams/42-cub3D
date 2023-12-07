/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:53:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/07 13:27:51 by bverdeci         ###   ########.fr       */
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
		my_mlx_pixel_put(img, x, i, color);
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
