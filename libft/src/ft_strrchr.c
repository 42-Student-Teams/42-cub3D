/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:36:27 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/22 11:38:02 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	search;
	char	*tab;

	i = ft_strlen(s);
	search = c;
	tab = (char *)s;
	while (i >= 0)
	{
		if (tab[i] == search)
			return (&tab[i]);
		i--;
	}
	if (search == 0)
		return (&tab[i]);
	return (NULL);
}
