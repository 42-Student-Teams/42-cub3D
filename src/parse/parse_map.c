/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:07:59 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/08 15:46:18 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	max_line_len(char *tmp, int max)
{
	if ((int)ft_strlen(tmp) > max)
		max = (int)ft_strlen(tmp);
	return (max);
}

static void	print_map(t_game *game)
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

static char	*skip_to_map(int fd, char *tmp)
{
	while (tmp)
	{
		if (tmp[0] == '1' || tmp[0] == '0' || tmp[0] == '2' || tmp[0] == ' ')
			return (tmp);
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	return (NULL);
}

static int	is_map_filled_walls(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->size.y)
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
	// print_map(game);
}

int	init_map_size(char *path, t_game *game)
{
	int		fd;
	char	*tmp;
	int		cpt;

	tmp = NULL;
	fd = 0;
	fd = check_open_fd(path, fd);
	tmp = check_fd(fd, tmp);
	cpt = 0;
	while (tmp)
	{
		if (tmp[0] == '1' || tmp[0] == '0' || tmp[0] == '2' || tmp[0] == ' ')
		{
			game->size.x = max_line_len(tmp, game->size.x);
			cpt++;
		}
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	close(fd);
	return (cpt);
}
