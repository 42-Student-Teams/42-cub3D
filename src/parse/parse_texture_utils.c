/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:50 by leon              #+#    #+#             */
/*   Updated: 2023/12/08 21:12:28 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

char	*skip_spaces_safe(char *temp)
{
	int		i;
	int		j;
	char	*str;

	str = ft_calloc(4, sizeof(char));
	if (!str)
		error("malloc error");
	i = 0;
	j = 0;
	while (ft_isspace(temp[i]))
		i++;
	while (temp[i] && !ft_isspace(temp[i]))
		str[j++] = temp[i++];
	if (str[0] == 'F' || str[0] == 'C')
		str[1] = ' ';
	free(temp);
	return (str);
}

void	init_cardinal_cpt(int cpt[4])
{
	cpt[0] = 0;
	cpt[1] = 0;
	cpt[2] = 0;
	cpt[3] = 0;
}

void	skip_line(char **temp, int fd)
{
	while (*temp && *temp[0] == '\n')
	{
		free(*temp);
		*temp = ft_get_next_line(fd);
	}
}

void	check_texture(char *temp)
{
	char	*str;

	str = ft_calloc(3, sizeof(char *));
	str[0] = temp[0];
	str[1] = temp[1];
	if (ft_strcmp("\n", str) == 0)
	{
		free(str);
		return ;
	}
	if (ft_strcmp("NO", str)
		&& (ft_strcmp("SO", str))
		&& (ft_strcmp("WE", str))
		&& (ft_strcmp("EA", str))
		&& (ft_strcmp("F ", str))
		&& (ft_strcmp("C ", str)))
	{
		free(str);
		error("Invalid texture");
	}
	free(str);
}
