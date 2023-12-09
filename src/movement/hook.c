/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/09 11:14:03 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move(t_player *p)
{
	if (p->front == 1)
		go_straight(p);
	if (p->back == 1)
		go_back(p);
	if (p->left == 1)
		go_left(p);
	if (p->right == 1)
		go_right(p);
	if (p->r_left == 1)
		rotate_left(p);
	if (p->r_right == 1)
		rotate_right(p);
}

void	go_straight(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (player->game->map[(int)(player->pos.x + player->dir.x
			* movspeed * 2)][(int)player->pos.y] == 0)
		player->pos.x += player->dir.x * movspeed;
	if (player->game->map[(int)player->pos.x][(int)(player->pos.y
		+ player->dir.y * movspeed)] == 0)
		player->pos.y += player->dir.y * movspeed;
}



int	key_event(int keycode, t_player *player)
{	
	mlx_destroy_image(player->game->window.mlx, player->game->image.img);
	player->game->image.img = mlx_new_image(player->game->window.mlx,
			SCREEN_W, SCREEN_H);
	player->game->image.addr = (int *)mlx_get_data_addr
		(player->game->image.img, &player->game->image.pixel_bits,
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
	draw_map(player);
	return (0);
}

int	key_press(int keycode, t_player *player)
{	
	if (keycode == KEYCODE_ESC)
		close_window(player->game);
	if (keycode == KEYCODE_W)
		player->front = 1;
	if (keycode == KEYCODE_S)
		player->back = 1;
	if (keycode == KEYCODE_A)
		player->left = 1;
	if (keycode == KEYCODE_D)
		player->right = 1;
	if (keycode == KEYCODE_RIGHT_ARROW)
		player->r_right = 1;
	if (keycode == KEYCODE_LEFT_ARROW)
		player->r_left = 1;
	return (0);
}

int	key_release(int keycode, t_player *player)
{	
	if (keycode == KEYCODE_ESC)
		close_window(player->game);
	if (keycode == KEYCODE_W)
		player->front = 0;
	if (keycode == KEYCODE_S)
		player->back = 0;
	if (keycode == KEYCODE_A)
		player->left = 0;
	if (keycode == KEYCODE_D)
		player->right = 0;
	if (keycode == KEYCODE_RIGHT_ARROW)
		player->r_right = 0;
	if (keycode == KEYCODE_LEFT_ARROW)
		player->r_left = 0;
	return (0);
}

int	close_window(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->size.y)
		free(game->map[i]);
	free(game->map);
	mlx_destroy_window(game->window.mlx, game->window.win);
	exit(1);
}
