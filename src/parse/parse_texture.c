/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:50 by leon              #+#    #+#             */
/*   Updated: 2023/12/08 15:34:05 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	set_texture(char *temp, t_game *game, int cpt[4], int i)
{
	if (temp[0] == 'N' && temp[1] == 'O' && ++cpt[0] && ++i)
		game->xpm.no = ft_strdup(temp + 2);
	else if (temp[0] == 'S' && temp[1] == 'O' && ++cpt[1] && ++i)
		game->xpm.so = ft_strdup(temp + 2);
	else if (temp[0] == 'W' && temp[1] == 'E' && ++cpt[2] && ++i)
		game->xpm.we = ft_strdup(temp + 2);
	else if (temp[0] == 'E' && temp[1] == 'A' && ++cpt[3] && ++i)
		game->xpm.ea = ft_strdup(temp + 2);
	else
		i = get_color_file(temp, game, i);
	return (i);
}

t_rgb	get_color_value(char *str)
{
	t_rgb	new_rgb;
	char	**temp;
	int		i;

	new_rgb = (t_rgb){0, 0, 0};
	temp = ft_split(str, ',');
	temp[0] = skip_spaces_safe(temp[0]);
	temp[1] = skip_spaces_safe(temp[1]);
	temp[2] = skip_spaces_safe(temp[2]);
	count_commas(temp);
	new_rgb = big_trim(temp);
	check_color_rgb(new_rgb);
	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		++i;
	}
	free(temp);
	free(str);
	return (new_rgb);
}

void	parse_files(t_game *game)
{
	skip_spaces(&game->xpm.so);
	skip_spaces(&game->xpm.no);
	skip_spaces(&game->xpm.we);
	skip_spaces(&game->xpm.ea);
	skip_spaces(&game->xpm.floor);
	skip_spaces(&game->xpm.ceiling);
	game->xpm.rgbc = get_color_value(game->xpm.floor);
	game->xpm.rgbf = get_color_value(game->xpm.ceiling);
}

void	check_files(t_game *game)
{
	remove_newline(game->xpm.no);
	remove_newline(game->xpm.so);
	remove_newline(game->xpm.we);
	remove_newline(game->xpm.ea);
	check_file_exist(game->xpm.no);
	check_file_exist(game->xpm.so);
	check_file_exist(game->xpm.we);
	check_file_exist(game->xpm.ea);
}

void	parse_texture(char *file, t_game *game)
{
	int		fd;
	char	*temp;

	fd = 0;
	temp = NULL;
	fd = check_open_fd(file, fd);
	temp = check_fd(fd, file);
	get_texture(temp, fd, game);
	parse_files(game);
	check_files(game);
}
