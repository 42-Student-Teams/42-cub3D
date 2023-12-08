/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:42:32 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/08 14:48:46 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	is_player(t_game *game, int y, int x)
{
	if (game->map[y][x] == PLAYER_N
		|| game->map[y][x] == PLAYER_S
		|| game->map[y][x] == PLAYER_W
		|| game->map[y][x] == PLAYER_E)
	{
		game->playerpos.x = y;
		game->playerpos.y = x;
		game->cardinal = game->map[y][x];
		game->map[y][x] = 0;
	}
}

void	fill_start_line(char *new)
{
	int		i;

	i = -1;
	while (new[++i] == ' ')
		new[i] = ' ';
}

int	max_line_len(char *tmp, int max)
{
	if ((int)ft_strlen(tmp) > max)
		max = (int)ft_strlen(tmp);
	return (max);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x - 1)
		{
			printf("%i", game->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
