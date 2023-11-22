/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/11/22 19:22:50 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int world[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	go_straight(t_player *player)
{
	if (!world[(int)(player->pos.x + player->dir.x * 0.2)][(int)player->pos.y])
		player->pos.x += player->dir.x * 0.2;
	if (!world[(int)player->pos.x][(int)(player->pos.y + player->dir.y * 0.2)])
		player->pos.y += player->dir.y * 0.2;
}

int	key_event(int keycode, t_player *player)
{
	double old_dir_x;
	double old_plane_x;
	
	player->game->image.img = mlx_new_image(player->game->window.mlx, SCREEN_W, SCREEN_H);
	player->game->image.addr = mlx_get_data_addr(player->game->image.img, &player->game->image.pixel_bits,
			&player->game->image.line_length, &player->game->image.endian);
			
	if (keycode == KEYCODE_ESC)
		close_window(player->game);
	if (keycode == KEYCODE_W)
		go_straight(player);
	if (keycode == KEYCODE_S)
	{
		if (!world[(int)(player->pos.x - player->dir.x * 0.2)][(int)player->pos.y])
			player->pos.x -= player->dir.x * 0.1;
		if (!world[(int)player->pos.x][(int)(player->pos.y - player->dir.y * 0.2)])
			player->pos.y -= player->dir.y * 0.2;
	}
	if (keycode == KEYCODE_D)
	{
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos(-0.1) - player->dir.y * sin(-0.1);
		player->dir.y = old_dir_x * sin(-0.1) + player->dir.y * cos(-0.1);
		old_plane_x = player->plane.x;
		player->plane.x = player->plane.x * cos(-0.1) - player->plane.y * sin(-0.1);
		player->plane.y = old_plane_x * sin(-0.1) + player->plane.y * cos(-0.1);
	}
	if (keycode == KEYCODE_A)
	{
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos(0.1) - player->dir.y * sin(0.1);
		player->dir.y = old_dir_x * sin(0.1) + player->dir.y * cos(0.1);
		old_plane_x = player->plane.x;
		player->plane.x = player->plane.x * cos(0.1) - player->plane.y * sin(0.1);
		player->plane.y = old_plane_x * sin(0.1) + player->plane.y * cos(0.1);
	}
	draw_map(&(player)->game->image, player->game, *player);
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
