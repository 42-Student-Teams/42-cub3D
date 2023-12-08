/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:14:01 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/08 12:26:55 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	is_player(t_game *game, int y, int x)
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

static void	fill_start_line(char *new)
{
	int		i;

	i = -1;
	while (new[++i] == ' ')
		new[i] = ' ';
}

static void	fill_end_line(t_game *game, char *new, int i)
{
	while (i < game->size.x)
	{
		new[i] = ' ';
		i++;
	}
}

static char	*line_fill_wall(t_game *game, char **temp)
{
	char	*new;
	int		len;
	int		i;

	new = NULL;
	i = 0;
	len = 0;
	new = ft_calloc(game->size.x + 1, sizeof(char));
	if (!*temp)
		error("Malloc line failed");
	len = (int)ft_strlen(*temp);
	ft_strlcpy(new, *temp, len + 1);
	new[len - 1] = ' ';
	i = len;
	fill_start_line(new);
	fill_end_line(game, new, i);
	free(*temp);
	return (new);
}

static char	*fill_line(char *temp, t_game *game)
{
	char	*new_line;
	int 	len;

	new_line = NULL;
	len = (int)ft_strlen(temp);
	if (temp[len-1] != '\n')
		temp[len] = '\n';
	if ((int)ft_strlen(temp) < game->size.x)
		new_line = line_fill_wall(game, &temp);
	else
		new_line = temp;
	return (new_line);
}

void	generate_map(t_game *game, int fd, char *temp)
{
	int		x;
	int		y;
	char	*new_line;

	x = 0;
	y = 0;
	new_line = NULL;
	while (temp)
	{
		x = -1;
		game->map[y] = ft_calloc(game->size.x, sizeof(int));
		if (!game->map[y])
			error("Malloc map failed");
		new_line = fill_line(temp, game);
		while (++x < game->size.x - 1)
		{
			if (new_line[x] != '\n')
				game->map[y][x] = check_elements(new_line[x], game);
			is_player(game, y, x);
		}
		free(new_line);
		y ++;
		temp = ft_get_next_line(fd);
	}
	close(fd);
}
