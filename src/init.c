/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/11/01 19:50:36 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	is_player(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'N'
		|| game->map[y][x] == 'S'
		|| game->map[y][x] == 'E'
		|| game->map[y][x] == 'W')
	{
		game->playerpos.x = y;
		game->playerpos.y = x;
	}
}


static void	fill_start_line(char *new)
{
	int		i;

	i = -1;
	while (new[++i] == ' ')
		new[i] = ' ';
}

static void fill_end_line(t_game *game, char *new, int i)
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
	new = ft_calloc(game->size.x, sizeof(char));
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
	char *new_line;

	new_line = NULL;
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

	y = 0;
	new_line = NULL;
	while (temp)
	{
		if (temp[0] == '\n')
			error("Empty line in map");
		x = -1;
		game->map[y] = ft_calloc(game->size.x, sizeof(int));
		if (!game->map[y])
			error("Malloc map failed");
		new_line = fill_line(temp, game);
		while (++x < game->size.x -1)
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

