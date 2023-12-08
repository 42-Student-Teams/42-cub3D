/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:50 by leon              #+#    #+#             */
/*   Updated: 2023/12/08 20:23:00 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_file_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error("Invalid texture");
	close(fd);
}

void	remove_newline(char *str)
{
	size_t	len;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

void	skip_spaces(char **temp)
{
	while (**temp == ' ')
		(*temp)++;
}

void	check_color_rgb(t_rgb new_rgb)
{
	if (new_rgb.r < 0 || new_rgb.r > 255)
		error("Invalid color value");
	if (new_rgb.g < 0 || new_rgb.g > 255)
		error("Invalid color value");
	if (new_rgb.b < 0 || new_rgb.b > 255)
		error("Invalid color value");
}

int	get_color_file(char *temp, t_game *game, int i)
{
	if (temp[0] == 'F' && temp[1] == ' ' && ++i && ++game->xpm.cptcolors)
		game->xpm.floor = ft_strdup(temp + 2);
	else if (temp[0] == 'C' && temp[1] == ' ' && ++i && ++game->xpm.cptcolors)
		game->xpm.ceiling = ft_strdup(temp + 2);
	return (i);
}
