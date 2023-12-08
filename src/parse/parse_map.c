/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:07:59 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/08 19:06:29 by lsaba-qu         ###   ########.fr       */
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
		if (tmp[i] != '1' && tmp[i] != '0' && tmp[i] != ' ' && tmp[i] != 'N' && tmp[i] != 'S' && tmp[i] != 'E' && tmp[i] != 'W')
		{
			// printf("Invalid character in map: %c\n", tmp[i]);
			return (1);
		}
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
			printf("%i", game->map[y][x]);
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
		printf("\n");
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
	int		fd;
	char	*tmp;
	int		cpt;

	tmp = NULL;
	fd = 0;
	fd = check_open_fd(path, fd);
	tmp = check_fd(fd, tmp);
	cpt = 0;
	printf("HELL\n");
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
			{
				printf("%s\n", tmp);
				game->size.x = max_line_len(tmp, game->size.x);
				cpt++;

			}
			free(tmp);
			tmp = ft_get_next_line(fd);
		}
	}
	printf("Map size: %d x %d\n", game->size.x, cpt);
	close(fd);
	return (cpt);
}
