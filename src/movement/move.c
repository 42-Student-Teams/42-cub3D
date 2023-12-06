/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:51 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/07 00:28:27 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	go_back(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (player->game->map[(int)(player->pos.x - player->dir.x
			* movspeed * 2)][(int)player->pos.y] == 0)
		player->pos.x -= player->dir.x * movspeed;
	if (player->game->map[(int)player->pos.x][(int)(player->pos.y
		- player->dir.y * movspeed)] == 0)
		player->pos.y -= player->dir.y * movspeed;
}

void	rotate_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rotspeed;

	rotspeed = 0.033 * 0.9;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-rotspeed)
		- player->dir.y * sin(-rotspeed);
	player->dir.y = old_dir_x * sin(-rotspeed) + player->dir.y * cos(-rotspeed);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(-rotspeed)
		- player->plane.y * sin(-rotspeed);
	player->plane.y = old_plane_x * sin(-rotspeed)
		+ player->plane.y * cos(-rotspeed);
}

void	rotate_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rotspeed;

	rotspeed = 0.033 * 0.9;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(rotspeed)
		- player->dir.y * sin(rotspeed);
	player->dir.y = old_dir_x * sin(rotspeed) + player->dir.y * cos(rotspeed);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(rotspeed)
		- player->plane.y * sin(rotspeed);
	player->plane.y = old_plane_x * sin(rotspeed)
		+ player->plane.y * cos(rotspeed);
}

void	go_left(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (player->game->map[(int)(player->pos.x - player->dir.y
			* movspeed * 2)][(int)player->pos.y] == 0)
		player->pos.x -= player->dir.y * movspeed;
	if (player->game->map[(int)player->pos.x][(int)(player->pos.y
		+ player->dir.x * movspeed * 2)] == 0)
		player->pos.y += player->dir.x * movspeed;
}

void	go_right(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (player->game->map[(int)(player->pos.x + player->dir.y 
			* movspeed * 2)][(int)player->pos.y] == 0)
		player->pos.x += player->dir.y * movspeed;
	if (player->game->map[(int)player->pos.x][(int)(player->pos.y
		- player->dir.x * movspeed * 2)] == 0)
		player->pos.y -= player->dir.x * movspeed;
}
