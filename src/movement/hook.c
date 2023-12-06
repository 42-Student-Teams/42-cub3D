/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/06 01:26:25 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int world[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	go_straight(t_player *player)
{
	double	movspeed;

	movspeed = 0.2;
	if (world[(int)(player->pos.x + player->dir.x * movspeed)][(int)player->pos.y] == 0)
		player->pos.x += player->dir.x * movspeed;
	if (world[(int)player->pos.x][(int)(player->pos.y + player->dir.y * movspeed)] == 0)
		player->pos.y += player->dir.y * movspeed;
}

void	go_back(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (world[(int)(player->pos.x - player->dir.x * movspeed)][(int)player->pos.y] == 0)
		player->pos.x -= player->dir.x * movspeed;
	if (world[(int)player->pos.x][(int)(player->pos.y - player->dir.y * movspeed)] == 0)
		player->pos.y -= player->dir.y * movspeed;
}

void	rotate_right(t_player *player)
{
	double old_dir_x;
	double old_plane_x;
	double	rotspeed;
	
	rotspeed =  0.033 * 1.8;
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

	rotspeed = 0.033 * 1.8;
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
	if (world[(int)(player->pos.x - player->dir.y * movspeed)][(int)player->pos.y] == 0)
		player->pos.x -= player->dir.y * movspeed;
	if (world[(int)player->pos.x][(int)(player->pos.y + player->dir.x * movspeed)] == 0)
		player->pos.y += player->dir.x * movspeed;
}

void	go_right(t_player *player)
{
	double	movspeed;

	movspeed = 0.1;
	if (world[(int)(player->pos.x + player->dir.y * movspeed)][(int)player->pos.y] == 0)
		player->pos.x += player->dir.y * movspeed;
	if (world[(int)player->pos.x][(int)(player->pos.y - player->dir.x * movspeed)] == 0)
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
	draw_map(&(player)->game->image, player->game, *player, *(player)->texture);
	return (0);
}


int	close_window(t_game *game)
{
	mlx_destroy_image(game->window.mlx, game->window.win);
	exit(0);
}

//int	hook_exit(t_game *game)
//{
//	end_program(game);
//	return (0);
//}
//
//int	key_hook(int key, t_game *game)
//{
//	t_vector	new_pos;
//
//	new_pos = player->pos;
//	if (key == KEYCODE_ESC)
//	{
//		end_program(game);
//	}
//	else if (key == KEYCODE_A)
//		new_pos.x -= 1;
//	else if (key == KEYCODE_S)
//		new_pos.y += 1;
//	else if (key == KEYCODE_D)
//		new_pos.x += 1;
//	else if (key == KEYCODE_W)
//		new_pos.y -= 1;
//	else
//		return (0);
//	hook_move(new_pos, game);
//	return (0);
//}
//
//int	hook_move(t_vector new_pos, t_game *game)
//{
//	if (game->map[new_pos.y][new_pos.x] == WALL
//		|| (game->map[new_pos.y][new_pos.x] == EXIT &&
//			game->item != game->item_count))
//		return (0);
//	game->map[player->pos.y][player->pos.x] = 0;
//	if (game->map[new_pos.y][new_pos.x] == ITEMS)
//		game->item_count++;
//	if (game->map[new_pos.y][new_pos.x] == EXIT)
//	{
//		player->pos = new_pos;
////		print_msg("You won !", game);
//		draw_map(game);
//		end_program(game);
//	}
//	game->map[new_pos.y][new_pos.x] = PLAYER;
//	player->pos = new_pos;
//	draw_map(game);
//	game->moves++;
////	print_msg("Number of steps: ", game);
//	return (0);
//}
