/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:16:31 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/19 00:03:43 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_stock(const char *s1, const char *s2)
{
	int		i;
	char	*dst;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i ++;
	}
	len = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		dst[len + i] = s2[i];
		i ++;
	}
	dst[len + i] = '\0';
	return (dst);
}

int	ft_gnl_strchr(const char *s, char c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (c);
		i++;
	}
	return (0);
}
