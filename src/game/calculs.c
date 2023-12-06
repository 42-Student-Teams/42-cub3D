/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:54:52 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/06 15:23:36 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	evaluate_ray(t_player player, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player.pos.x - ray->square.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->square.x + 1.0 - player.pos.x) * ray->delta_dist.x; // + 1 parce que le mur est a droite
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player.pos.y - ray->square.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->square.y + 1.0 - player.pos.y) * ray->delta_dist.y; // + 1 parce que le mur est en haut
	}
}

void	dda_algorithme(t_game *game, t_ray *ray, int *side)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->square.x += ray->step.x;
			*side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->square.y += ray->step.y;
			*side = 1;
		}
		if (game->map[ray->square.x][ray->square.y] > 0)
			hit = 1;
	}
}

double	find_wall_dist(t_ray ray, int side)
{
	if (side == 0)
		return ray.side_dist.x - ray.delta_dist.x;
	return ray.side_dist.y - ray.delta_dist.y;
}

void	calculate_wall(t_cam *cam)
{
	int	line_height;

	line_height = (int)((double)SCREEN_H / cam->wall_dist);
	cam->start = -line_height / 2 + SCREEN_H / 2;
	if (cam->start < 0)
		cam->start = 0;
	cam->end = line_height / 2 + SCREEN_H / 2;
	if (cam->end >= SCREEN_H)
		cam->end = SCREEN_H - 1;
}
