/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:57:11 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/16 10:01:52 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*zdst;
	char	*zsrc;

	i = 0;
	zdst = (char *)dst;
	zsrc = (char *)src;
	if (zsrc > zdst)
	{
		while (i < len)
		{
			zdst[i] = zsrc[i];
			i ++;
		}
	}
	else if (zdst > zsrc)
	{
		i = len;
		while (i--)
			zdst[i] = zsrc[i];
	}
	return (dst);
}
