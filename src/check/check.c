/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/24 19:56:10 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:44 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/31 11:48:47 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5 || ft_strcmp(&path[len - 4], ".cub"))
		error("invalid file extension, use .cub");
}

int	check_player(char c)
{
	if (c == 'N')
		return (PLAYER_N);
	else if (c == 'S')
		return (PLAYER_S);
	else if (c == 'E')
		return (PLAYER_E);
	else if (c == 'W')
		return (PLAYER_W);
	return (-1);
}

int	check_elements(char c, t_game *game)
{
	if (c == '0')
		return (EMPTY);
	if (c == ' ')
		return (SPACE);
	else if (c == '1')
		return (WALL);
	else if (c == 'C' && ++game->item)
		return (ITEMS);
	else if (c == 'E' && ++game->exit)
		return (EXIT);
	else if ((c == 'N' | c == 'S' | c == 'E' | c == 'W') && ++game->players)
		return (check_player(c));
	else
		error("invalid character or characters");
	return (-1);
}

void	check_min_amount(t_game *game)
{
	if (game->item < 1)
		error("you need at least 1 item");
	if (game->exit != 1)
	{
		if (game->exit > 1)
			error("too many exits");
		else
			error("you need at least 1 exit");
	}
	if (game->players != 1)
	{
		if (game->players > 1)
			error("too many players");
		else
			error("you need at least 1 player");
	}
}

void	check_wall(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->size.x)
	{
		if (game->map[0][i] != WALL)
			error("not a wall");
		if (game->map[game->size.y - 1][i] != WALL)
			error("not a wall");
	}
	i = -1;
	while (++i < game->size.y)
	{
		if (game->map[i][0] != WALL)
			error("not a wall");
		if (game->map[i][game->size.x -1] != WALL)
			error("not a wall");
	}
}

void	check_is_solvable(int x, int y, t_game *game)
{
	if (game->map[y][x] == WALL || game->map[y][x] >= 10)
		return ;
	if (game->map[y][x] == ITEMS)
		game->item_count ++;
	if (game->map[y][x] == EXIT)
		game->exit ++;
	game->map[y][x] += 10;
	check_is_solvable(x + 1, y, game);
	check_is_solvable(x - 1, y, game);
	check_is_solvable(x, y + 1, game);
	check_is_solvable(x, y - 1, game);
}
