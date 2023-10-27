/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:07:59 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/27 16:22:10 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char	*check_fd(int fd, char *tmp)
{
	tmp = ft_get_next_line(fd);
	if (!tmp)
		error("File is empty");
	return (tmp);
}

static int	max_line_len(char *tmp, int max)
{
	if ((int)ft_strlen(tmp) > max)
		max = ft_strlen(tmp);
	return (max);
}

static int	check_open_fd(char *path, int fd)
{
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("File not found");
	return (fd);
}


static void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
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

static void isMapFilledWithWalls(int x, int y, t_game *game)
{
	if (x < 0 || x >= game->size.y || y < 0 || y >= game->size.x)
		return ; // Out of bounds
	if (game->map[y][x] == WALL || game->map[y][x] >= 10)
		return ; // Wall or already visited
	game->map[y][x] += 10;

	isMapFilledWithWalls(x + 1, y, game);
	isMapFilledWithWalls(x - 1, y, game);
	isMapFilledWithWalls(x, y + 1, game);
	isMapFilledWithWalls(x, y - 1, game);
}

void	parse_map(char *path, t_game *game)
{
	int fd;
	char *temp;

	fd = 0;
	temp = NULL;
	check_extension(path);
	game->size.y = init_map_size(path, game);
	game->map = ft_allok(game->size.y, sizeof(int *), 1);
	fd = check_open_fd(path, fd);
	temp = check_fd(fd, temp);
	temp = skip_to_map(fd, temp);
	generate_map(game, fd, temp);
	print_map(game);
	check_min_amount(game);
	isMapFilledWithWalls(game->playerpos.x, game->playerpos.y,game);

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
