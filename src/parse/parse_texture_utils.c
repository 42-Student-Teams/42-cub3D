/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:50 by leon              #+#    #+#             */
/*   Updated: 2023/12/08 15:00:11 by lsaba-qu         ###   ########.fr       */
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

	str = ft_calloc(5, sizeof(char));
	if (!str)
		error("malloc error");
	i = 0;
	j = 0;
	while (ft_isspace(temp[i]))
		i++;
	while (temp[i])
		str[j++] = temp[i++];
	free(temp);
	printf("len : %lu\n", strlen(str));
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
	if (*temp[0] == '\n')
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
	if (ft_strcmp("NO", str)
		&& (ft_strcmp("SO", str))
		&& (ft_strcmp("WE", str))
		&& (ft_strcmp("EA", str))
		&& (ft_strcmp("F ", str))
		&& (ft_strcmp("C ", str)))
		error("Invalid texture");
	free(str);
}
