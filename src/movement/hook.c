/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/06 16:53:24 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	go_straight(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (player->game->map[(int)(player->pos.x + player->dir.x * movspeed * 2)][(int)player->pos.y] == 0)
		player->pos.x += player->dir.x * movspeed;
	if (player->game->map[(int)player->pos.x][(int)(player->pos.y + player->dir.y * movspeed)] == 0)
		player->pos.y += player->dir.y * movspeed;
}

void	go_back(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (player->game->map[(int)(player->pos.x - player->dir.x * movspeed * 2)][(int)player->pos.y] == 0)
		player->pos.x -= player->dir.x * movspeed;
	if (player->game->map[(int)player->pos.x][(int)(player->pos.y - player->dir.y * movspeed)] == 0)
		player->pos.y -= player->dir.y * movspeed;
}

void	rotate_right(t_player *player)
{
	double old_dir_x;
	double old_plane_x;
	double	rotspeed;
	
	rotspeed =  0.033 * 0.9;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-rotspeed) - player->dir.y * sin(-rotspeed);
	player->dir.y = old_dir_x * sin(-rotspeed) + player->dir.y * cos(-rotspeed);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(-rotspeed) - player->plane.y * sin(-rotspeed);
	player->plane.y = old_plane_x * sin(-rotspeed) + player->plane.y * cos(-rotspeed);
}

void	rotate_left(t_player *player)
{
	double old_dir_x;
	double old_plane_x;
	double	rotspeed;

	rotspeed = 0.033 * 0.9;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(rotspeed) - player->dir.y * sin(rotspeed);
	player->dir.y = old_dir_x * sin(rotspeed) + player->dir.y * cos(rotspeed);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(rotspeed) - player->plane.y * sin(rotspeed);
	player->plane.y = old_plane_x * sin(rotspeed) + player->plane.y * cos(rotspeed);
}

void	go_left(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (player->game->map[(int)(player->pos.x - player->dir.y * movspeed * 2)][(int)player->pos.y] == 0)
		player->pos.x -= player->dir.y * movspeed;
	if (player->game->map[(int)player->pos.x][(int)(player->pos.y + player->dir.x * movspeed * 2)] == 0)
		player->pos.y += player->dir.x * movspeed;
}

void	go_right(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (player->game->map[(int)(player->pos.x + player->dir.y * movspeed * 2)][(int)player->pos.y] == 0)
		player->pos.x += player->dir.y * movspeed;
	if (player->game->map[(int)player->pos.x][(int)(player->pos.y - player->dir.x * movspeed * 2)] == 0)
		player->pos.y -= player->dir.x * movspeed;
}


int	key_event(int keycode, t_player *player)
{	
	mlx_destroy_image(player->game->window.mlx, player->game->image.img);
	player->game->image.img = mlx_new_image(player->game->window.mlx, SCREEN_W, SCREEN_H);
	player->game->image.addr = (int *)mlx_get_data_addr(player->game->image.img, &player->game->image.pixel_bits,
			&player->game->image.line_length, &player->game->image.endian);	
	if (keycode == KEYCODE_ESC)
		close_window(player->game);
	if (keycode == KEYCODE_W)
		go_straight(player);
	if (keycode == KEYCODE_S)
		go_back(player);
	if (keycode == KEYCODE_A)
		go_left(player);
	if (keycode == KEYCODE_D)
		go_right(player);
	if (keycode == KEYCODE_RIGHT_ARROW)
		rotate_right(player);
	if (keycode == KEYCODE_LEFT_ARROW)
		rotate_left(player);
	draw_map(player->game, *player, *(player)->texture);
	return (0);
}


int	close_window(t_game *game)
{
	mlx_destroy_image(game->window.mlx, game->window.win);
	exit(0);
}
