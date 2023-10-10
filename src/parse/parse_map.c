/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:07:59 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/10 17:11:24 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	parse_map(char *path, t_game *game)
{
	int		fd;
	char	*temp;

	check_extension(path);
	game->size = init_map_size(path);
	// recup map size et map position
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("No such file or directory");
	// recup la premiere partie

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

t_vector	init_map_size(char *path)
{
	t_vector	res;
	int			fd;
	char		buffer[1000];
	int			size;
//	int			i;

	res.x = 0;
	res.y = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("No such file or directory");
	size = read(fd, buffer, 999);
	printf("size = %d\n", size);
//	while (size != 0)
//	{
//		buffer[size] = 0;
//		i = -1;
//		while (buffer[++i])
//		{
//			if (buffer[i] == '\n')
//				res.y ++;
//		}
//		size = read(fd, buffer, 999);
//	}
//	fd = close(fd);
	return (res);
}
