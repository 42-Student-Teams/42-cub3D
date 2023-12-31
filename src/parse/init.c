/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:14:01 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/08 14:45:39 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

	new_line = NULL;
	if ((int)ft_strlen(temp) < game->size.x)
		new_line = line_fill_wall(game, &temp);
	else
		new_line = temp;
	return (new_line);
}

void	generate_map(t_game *game, int fd, char *temp)
{
	t_vector	i;
	char		*new_line;

	ft_bzero(&i, sizeof(t_vector));
	new_line = NULL;
	while (temp)
	{
		if (temp[0] == '\n')
			error("Empty line in map");
		i.x = -1;
		game->map[i.y] = ft_calloc(game->size.x, sizeof(int));
		if (!game->map[i.y])
			error("Malloc map failed");
		new_line = fill_line(temp, game);
		while (++i.x < game->size.x - 1)
		{
			if (new_line[i.x] != '\n')
				game->map[i.y][i.x] = check_elements(new_line[i.x], game);
			is_player(game, i.y, i.x);
		}
		free(new_line);
		i.y ++;
		temp = ft_get_next_line(fd);
	}
	close(fd);
}
