/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:50 by leon              #+#    #+#             */
/*   Updated: 2023/11/03 14:23:53 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	skip_spaces(char **temp)
{
	while (**temp == ' ')
		(*temp)++;
}

static void	init_cardinal_cpt(int cpt[4])
{
	cpt[0] = 0;
	cpt[1] = 0;
	cpt[2] = 0;
	cpt[3] = 0;
}

static void	check_min_max_texture(int cpt[4])
{
	if (cpt[0] > 1)
		error("There's more than one texture of NO");
	if (cpt[0] < 1)
		error("There's more less one texture of NO");
	if (cpt[1] > 1)
		error("There's more than one texture of SO");
	if (cpt[1] < 1)
		error("There's more less one texture of SO");
	if (cpt[2] > 1)
		error("There's more than one texture of WE");
	if (cpt[2] < 1)
		error("There's more less one texture of WE");
	if (cpt[3] > 1)
		error("There's more than one texture of EA");
	if (cpt[3] < 1)
		error("There's more less one texture of EA");
}

static void	get_texture(char *temp, int fd, t_game *game)
{
	int	cpt[4];

	init_cardinal_cpt(cpt);
	while (temp && cpt[0] < 2 && cpt[1] < 2 && cpt[2] < 2 && cpt[3] < 2)
	{
		if (temp[0] == '\n')
		{
			free(temp);
			temp = ft_get_next_line(fd);
		}
		skip
		skip_spaces(&temp);
		if (temp[0] == 'N' && temp[1] == 'O' && ++cpt[0])
			game->xpm.no = ft_strdup(temp + 2);
		else if (temp[0] == 'S' && temp[1] == 'O' && ++cpt[1])
			game->xpm.so = ft_strdup(temp + 2);
		else if (temp[0] == 'W' && temp[1] == 'E' && ++cpt[2])
			game->xpm.we = ft_strdup(temp + 2);
		else if (temp[0] == 'E' && temp[1] == 'A' && ++cpt[3])
			game->xpm.ea = ft_strdup(temp + 2);
		else
		{
			printf("HELLO '%c'\n", temp[0]);
			error("Texture is not correct");
		}
		free(temp);
		temp = ft_get_next_line(fd);
	}
	check_min_max_texture(cpt);
	printf("NO: %s\n", game->xpm.no);
	printf("EA: %s\n", game->xpm.ea);
	printf("WE: %s\n", game->xpm.we);
	printf("SO: %s\n", game->xpm.so);
	close(fd);
}

void parse_texture(char *file, t_game *game)
{
	int		fd;
	char 	*temp;

	fd = 0;
	temp = NULL;
	fd = check_open_fd(file, fd);
	temp = check_fd(fd, file);
	get_texture(temp, fd, game);
}