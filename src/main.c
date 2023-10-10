/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:32:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/10 14:54:39 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	init_map_size(char *path)
{
	t_vector	res;
	int			fd;
	char		buffer[1000];
	int			size;
	int			i;

	res.x = 0;
	res.y = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("No such file or directory");
	size = read(fd, buffer, 999);
	while (size != 0)
	{
		buffer[size] = 0;
		i = -1;
		while (buffer[++i])
		{
			if (buffer[i] == '\n')
				res.y ++;
		}
		size = read(fd, buffer, 999);
	}
	return (res);
}

void	check_valid_path(t_game *game)
{
	int	i;
	int	j;

	if (game->item_count != game->item)
		error("Can't reach all the items");
	if (game->exit != 1)
		error("Can't reach the exit");
	i = -1;
	while (++i < game->size.y)
	{
		j = -1;
		while (++j < game->size.x)
		{
			if (game->map[i][j] >= 10)
				game->map[i][j] -= 10;
		}
	}
}

void	parse_map(char *path, t_game *game)
{
	int		fd;
	char	*temp;

	check_extension(path);
	game->size = init_map_size(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("No such file or directory");
	temp = ft_get_next_line(fd);
	if (!temp)
		error("File is empty");
	game->size.x = ft_strlen(temp) - 1;
	if (game->size.y < 4 || game->size.x < 4)
		error("Map can't be generated");
	game->map = ft_allok(game->size.y, sizeof(int *), 1);
	generate_map(game, fd, temp);
	check_min_amount(game);
	check_wall(game);
	game->exit = 0;
	check_is_solvable(game->playerpos.x, game->playerpos.y, game);
	check_valid_path(game);
}

int	main(int argc, char **argv)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		arg_error(argc);
	parse_map(argv[1], &game);
	game.window.mlx = mlx_init();
	if (game.window.mlx == NULL)
		return (EXIT_FAILURE);
	game.window.win = mlx_new_window(game.window.mlx,
			game.size.x * 96, game.size.y * 96, "./Cube3D");
	if (!game.window.win)
		return (EXIT_FAILURE);
	init_sprites(&game);
	draw_map(&game);
	game.item_count = 0;

	return (0);
}
