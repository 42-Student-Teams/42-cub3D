/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/11/01 14:57:42 by lsaba-qu         ###   ########.fr       */
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
	return (SPACE);
}

int	check_elements(char c, t_game *game)
{
	if (c == '0')
		return (FLOOR);
	else if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && ++game->players)
	{
		game->playerpos.pos = check_player(c);
		return (check_player(c));
	}
	else if (c == '1')
		return (WALL);
	if (c == ' ')
		return (SPACE);
	error("Invalid characters in map");
	return (-1);
}

void	check_min_amount(t_game *game)
{
	if (game->players != 1)
	{
		if (game->players > 1)
			error("too many players");
		else
			error("you need at least 1 player");
	}
}
