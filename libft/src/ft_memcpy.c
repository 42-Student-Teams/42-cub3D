/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:17:58 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/10/27 23:23:10 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tabdst;
	char	*tabsrc;

	tabdst = (char *)dst;
	tabsrc = (char *)src;
	if (!tabdst && !tabsrc)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tabdst[i] = tabsrc[i];
		i ++;
	}
	return (dst);
}
