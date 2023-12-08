/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:50 by leon              #+#    #+#             */
/*   Updated: 2023/12/08 16:02:09 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_min_max_colors(t_game *game)
{
	if (game->xpm.cptcolors > 2)
		error("Too many color textures");
	if (game->xpm.cptcolors < 2)
		error("Need 2 color textures");
}

void	get_texture(char *temp, int fd, t_game *game)
{
	int	cpt[4];
	int	i;

	i = 0;
	init_cardinal_cpt(cpt);
	while (temp && cpt[0] < 2 && cpt[1] < 2 && cpt[2] < 2 && cpt[3] < 2)
	{
		skip_line(&temp, fd);
		skip_spaces(&temp);
		i = set_texture(temp, game, cpt, i);
		if (i < 6)
			check_texture(temp);
		temp = ft_get_next_line(fd);
	}
	check_min_max_texture(cpt);
	check_min_max_colors(game);
	close(fd);
}

void	count_commas(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		error("Only 3 values are allowed for RGB");
}

char	*remove_all_spaces(char *str)
{
	int			count;
	char		*temp;
	char		*result;
	int			j;

	count = 0;
	j = -1;
	if (str == NULL)
		return (NULL);
	temp = str;
	while (temp[++j])
	{
		if (temp[j] != ' ')
			++count;
	}
	result = ft_calloc(count + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	j = 0;
	count = 0;
	copy_result(str, result, count, j);
	return (result);
}

t_rgb	big_trim(char **str)
{
	t_rgb	rgb;
	char	*temp;

	temp = NULL;
	temp = remove_all_spaces(str[0]);
	rgb.r = ft_atoi(temp);
	free(temp);
	temp = remove_all_spaces(str[1]);
	rgb.g = ft_atoi(temp);
	free(temp);
	temp = remove_all_spaces(str[2]);
	rgb.b = ft_atoi(temp);
	free(temp);
	return (rgb);
}
