/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:52 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/05 18:44:04 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_exit(t_game *game)
{	
	end_program(game);
	return (0);
}

int	key_hook(int key, t_game *game)
{
	t_vector	new_pos;

	new_pos = game->playerpos;
	if (key == KEYCODE_ESC)
	{
		end_program(game);
	}
	else if (key == KEYCODE_A)
		new_pos.x -= 1;
	else if (key == KEYCODE_S)
		new_pos.y += 1;
	else if (key == KEYCODE_D)
		new_pos.x += 1;
	else if (key == KEYCODE_W)
		new_pos.y -= 1;
	else
		return (0);
	hook_move(new_pos, game);
	return (0);
}

int	hook_move(t_vector new_pos, t_game *game)
{
	if (game->map[new_pos.y][new_pos.x] == WALL
		|| (game->map[new_pos.y][new_pos.x] == EXIT &&
			game->item != game->item_count))
		return (0);
	game->map[game->playerpos.y][game->playerpos.x] = 0;
	if (game->map[new_pos.y][new_pos.x] == ITEMS)
		game->item_count++;
	if (game->map[new_pos.y][new_pos.x] == EXIT)
	{
		game->playerpos = new_pos;
		print_msg("You won !", game);
		draw_map(game);
		end_program(game);
	}
	game->map[new_pos.y][new_pos.x] = PLAYER;
	game->playerpos = new_pos;
	draw_map(game);
	game->moves++;
	print_msg("Number of steps: ", game);
	return (0);
}
