/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/27 19:00:36 by lsaba-qu         ###   ########.fr       */
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
		new[i] = '0';
}

static void fill_end_line(t_game *game, char *new, int i)
{
	while (i < game->size.x)
	{
		new[i - 1] = new[i - 2];
		i++;
	}
	new[i - 1] = new[i - 2];
}


static char	*line_fill_wall(t_game *game, char **temp)
{
	char	*new;
	int		len;
	int		i;

	new = NULL;
	i = 0;
	new = ft_calloc(game->size.x + 1, sizeof(char));
	if (!*temp)
		error("Malloc line failed");
	len = (int)ft_strlen(*temp);
	ft_strlcpy(new, *temp, len + 2);
	i = len;
	fill_start_line(new);
	fill_end_line(game, new, i);
	// Fills end of line with the character before the last one

	free(*temp);
	return (new);
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
		if ((int)ft_strlen(temp) < game->size.x)
			new_line = line_fill_wall(game, &temp);
		else
			new_line = temp;
		while (++x < game->size.x)
		{
//			printf("%c", new_line[x]);
			game->map[y][x] = check_elements(new_line[x], game);
			if (is_player(game->map[y][x]))
			{
				game->playerpos.x = x;
				game->playerpos.y = y;
			}
		}
		free(new_line);
		y ++;
		temp = ft_get_next_line(fd);
	}
	close(fd);
}

