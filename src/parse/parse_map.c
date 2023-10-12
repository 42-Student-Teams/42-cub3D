/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:07:59 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/12 18:18:34 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	parse_map(char *path, t_game *game)
{
//	int		fd;
//	char	*temp;

	check_extension(path);
	game->size.y = init_map_size(path);
	printf("size.y = %d\n", game->size.y);
	game->map = ft_allok(game->size.y, sizeof(int *), 1);
	(path, game);

//
//	if (game->size.y < 4 || game->size.x < 4)
//		error("Map can't be generated");
//	generate_map(game, fd, temp);
//	check_min_amount(game);
//	check_wall(game);
//	game->exit = 0;
//	check_is_solvable(game->playerpos.x, game->playerpos.y, game);
//	check_valid_path(game);
}

static char  *check_fd(int fd, char *tmp)
{
	tmp = ft_get_next_line(fd);
	if (!tmp)
		error("File is empty");
	return (tmp);
}

int (char *path, t_game *game)
{
	int		fd;
	char	*tmp;
	int		cpt;
	int		i;

	cpt = 0;
	i = 0;
	tmp = NULL;
	fd = open(path, O_RDONLY);
	tmp = check_fd(fd, tmp);
	while (tmp != 0)
	{
		if (tmp[0] == '1' || tmp[0] == '0' || tmp[0] == '2' || tmp[0] == ' ')
		{
			cpt = ft_strlen(tmp) - 1;
			game->map[i] = ft_allok(cpt, sizeof(int *), 1);
			i ++;
		}
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	if(tmp)
		free(tmp);
	close(fd);
	return (cpt);
}

int	init_map_size(char *path)
{
	int		fd;
	char	*tmp;
	int		cpt;

	tmp = NULL;
	fd = open(path, O_RDONLY);
	tmp = check_fd(fd, tmp);
	cpt = 0;
	while (tmp)
	{
		if (tmp[0] == '1' || tmp[0] == '0' || tmp[0] == '2' || tmp[0] == ' ')
			cpt++;
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	close(fd);
//	printf("cpt = %d\n", cpt);
	return (cpt);
}
