/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:51:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/22 11:37:27 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;
	char	*tab;

	i = 0;
	find = c;
	tab = (char *)s;
	while (tab[i])
	{
		if (tab[i] == find)
			return (&tab[i]);
		i++;
	}
	if (find == 0)
		return (&tab[i]);
	return (NULL);
}
