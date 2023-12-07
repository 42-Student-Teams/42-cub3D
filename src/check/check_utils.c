/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:00:59 by leon              #+#    #+#             */
/*   Updated: 2023/12/07 11:35:01 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_open_fd(char *path, int fd)
{
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("File not found");
	return (fd);
}

char	*check_fd(int fd, char *tmp)
{
	tmp = ft_get_next_line(fd);
	if (!tmp)
		error("File is empty");
	return (tmp);
}
