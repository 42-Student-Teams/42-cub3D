/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:15:12 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/14 23:55:04 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_free(char *stock, char *buff)
{
	char	*temp;

	temp = ft_add_stock(stock, buff);
	free(stock);
	return (temp);
}

char	*read_file(int fd, char *res)
{
	char	*temp;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[byte_read] = 0;
		res = ft_add_free(res, temp);
		if (ft_gnl_strchr(res, '\n'))
			break ;
	}
	free (temp);
	return (res);
}

char	*ft_line(char *buffer)
{
	int		len;
	char	*line;
	int		i;

	len = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len ++;
	if (buffer[len] == '\n')
		len ++;
	line = ft_calloc(len + 1, sizeof(char));
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n' && buffer[i])
		line[i++] = '\n';
	return (line);
}

char	*ft_update(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i ++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_update(buffer);
	return (line);
}
