/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/31 15:48:55 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/06 16:16:23 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
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
	ft_strlcpy(new, *temp, len +1);
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
	char 	*new_line;

	y = 0;
	new_line = NULL;
	while (temp)
	{
		x = -1;
		game->map[y] = ft_allok(game->size.x, sizeof(int), 1);
		new_line = fill_line(temp, game);
		while (++x < game->size.x)
		{
			if (new_line[x] != '\n')
				game->map[y][x] = check_elements(new_line[x], game);
			if (is_player(game->map[y][x]))
			{
				game->playerpos.x = x;
				game->playerpos.y = y;
			}
		}
		game->map[y][x - 1] = SPACE;
		free(new_line);
		y ++;
		temp = ft_get_next_line(fd);
	}
	close(fd);
}

