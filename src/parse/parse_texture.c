/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:50 by leon              #+#    #+#             */
/*   Updated: 2023/12/07 12:18:57 by lsaba-qu         ###   ########.fr       */
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

static void	skip_line(char **temp, int fd)
{
	if (*temp[0] == '\n')
	{
		free(*temp);
		*temp = ft_get_next_line(fd);
	}
}

static int	get_color_file(char *temp, t_game *game, int i)
{
	if (temp[0] == 'F' && temp[1] == ' ' &&  ++i && ++game->xpm.cptcolors)
		game->xpm.floor = ft_strdup(temp + 2);
	else if (temp[0] == 'C' && temp[1] == ' ' && ++i && ++game->xpm.cptcolors)
		game->xpm.ceiling = ft_strdup(temp + 2);
	return (i);
}

static int set_texture(char *temp, t_game *game, int cpt[4], int i)
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

static void	check_texture(char *temp)
{
	char	*str;

	str = ft_calloc(3, sizeof(char *));
	str[0] = temp[0];
	str[1] = temp[1];
	if (ft_strcmp("NO", str)
		&& (ft_strcmp("SO", str))
		&& (ft_strcmp("WE", str))
		&& (ft_strcmp("EA", str))
		&& (ft_strcmp("F ", str))
		&& (ft_strcmp("C ", str)))
		error("Invalid texture");
	free(str);
}

static void	check_min_max_colors(t_game *game)
{
	if (game->xpm.cptcolors > 2)
		error("Too many color textures");
	if (game->xpm.cptcolors < 2)
		error("Need 2 color textures");
}

static void	get_texture(char *temp, int fd, t_game *game)
{
	int	cpt[4];
	int i;

	i = 0;
	init_cardinal_cpt(cpt);
	while (temp && cpt[0] < 2 && cpt[1] < 2 && cpt[2] < 2 && cpt[3] < 2)
	{
		skip_line(&temp, fd);
		skip_spaces(&temp);
		i = set_texture(temp, game, cpt, i);
		if (i <  6)
			check_texture(temp);
		free(temp);
		temp = ft_get_next_line(fd);
	}
	check_min_max_texture(cpt);
	check_min_max_colors(game);
	close(fd);
}

static void	count_commas(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		error("Only 3 values are allowed for RGB");
}

static char	*remove_all_spaces(const char *str)
{
	int			count;
	const char	*temp;
	char 		*result;

	count = 0;
	if (str == NULL)
		return NULL;
	temp = str;
	while (*temp)
	{
		if (*temp != ' ')
			++count;
		++temp;
	}
	result = (char *)malloc(count + 1);
	if (result == NULL)
		return NULL;
	int j = 0;
	while (*str)
	{
		if (*str != ' ')
			result[j++] = *str;
		++str;
	}
	result[j] = '\0';
	return (result);
}

static t_rgb	big_trim(char **str)
{
	t_rgb rgb;

	rgb.r = ft_atoi(remove_all_spaces(str[0]));
	rgb.g = ft_atoi(remove_all_spaces(str[1]));
	rgb.b = ft_atoi(remove_all_spaces(str[2]));
	return (rgb);
}

static void	check_color_rgb(t_rgb new_rgb)
{
	if (new_rgb.r < 0 || new_rgb.r > 255)
		error("Invalid color value");
	if (new_rgb.g < 0 || new_rgb.g > 255)
		error("Invalid color value");
	if (new_rgb.b < 0 || new_rgb.b > 255)
		error("Invalid color value");
}

static t_rgb get_color_value(char *str)
{
	t_rgb	new_rgb;
	char	**temp;

	new_rgb = (t_rgb){0, 0, 0};
	temp = ft_split(str, ',');
	skip_spaces(&temp[0]);
	skip_spaces(&temp[1]);
	skip_spaces(&temp[2]);
	count_commas(temp);
	new_rgb = big_trim(temp);
	check_color_rgb(new_rgb);
	free(temp);
	return (new_rgb);
}

static void	parse_files(t_game *game)
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

static void	check_file_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error("Invalid texture");
	close(fd);
}

static void	remove_newline(char *str)
{
	size_t	len;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0'; // Replace newline with null terminator
	}
}

static void	check_files(t_game *game)
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

void parse_texture(char *file, t_game *game)
{
	int		fd;
	char 	*temp;

	fd = 0;
	temp = NULL;
	fd = check_open_fd(file, fd);
	temp = check_fd(fd, file);
	get_texture(temp, fd, game);
	parse_files(game);
	check_files(game);
}