/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:07:59 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/08 20:52:50 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	check_valid_line(char *tmp)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(tmp);
	while (ft_isspace(tmp[i]))
		i++;
	while (i < len - 1)
	{
		if (tmp[i] != '1' && tmp[i] != '0' && tmp[i] != ' '
			&& tmp[i] != 'N' && tmp[i] != 'S' && tmp[i] != 'E' && tmp[i] != 'W')
			return (1);
		i++;
	}
	return (0);
}

static char	*skip_to_map(int fd, char *tmp)
{
	while (tmp)
	{
		if (tmp[0] == '\n')
		{
			free(tmp);
			tmp = ft_get_next_line(fd);
		}
		else
		{
			if (check_valid_line(tmp) == 0)
				return (tmp);
			free(tmp);
			tmp = ft_get_next_line(fd);
		}
	}
	return (NULL);
}

static int	is_map_filled_walls(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->size.y -1)
	{
		x = -1;
		while (++x < game->size.x - 1)
		{
			if (game->map[y][x] == FLOOR)
			{
				if (y == 0 || y == game->size.y
					|| x == 0
					|| x == game->size.x)
					return (-1);
				if (game->map[y][x - 1] == SPACE
					|| game->map[y][x + 1] == SPACE
					|| game->map[y - 1][x] == SPACE
					|| game->map[y + 1][x] == SPACE)
					return (-1);
			}
		}
	}
	return (0);
}

void	parse_map(char *path, t_game *game)
{
	int		fd;
	char	*temp;

	fd = 0;
	temp = NULL;
	check_extension(path);
	game->size.y = init_map_size(path, game);
	game->map = ft_allok(game->size.y + 2, sizeof(int *), 1);
	fd = check_open_fd(path, fd);
	temp = check_fd(fd, temp);
	temp = skip_to_map(fd, temp);
	generate_map(game, fd, temp);
	check_min_amount(game);
	if (is_map_filled_walls(game))
		error("Map is not surrounded by walls");
}

int	init_map_size(char *path, t_game *game)
{
	t_garb	g;

	ft_bzero(&g, sizeof(t_garb));
	g.fd = check_open_fd(path, g.fd);
	g.tmp = check_fd(g.fd, g.tmp);
	while (g.tmp)
	{
		if (g.tmp[0] == '\n')
		{
			free(g.tmp);
			g.tmp = ft_get_next_line(g.fd);
		}
		else
		{
			if (check_valid_line(g.tmp) == 0)
			{
				game->size.x = max_line_len(g.tmp, game->size.x);
				g.cpt++;
			}
			free(g.tmp);
			g.tmp = ft_get_next_line(g.fd);
		}
	}
	close(g.fd);
	return (g.cpt);
}
