/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublons_ia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:07:01 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/10 15:11:11 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_doublons_ia(int *tab, int size)
{
	int	x;
	int	y;

	x = -1;
	while (++x < size - 1)
	{
		y = x;
		while (++y < size)
		{
			if (tab[x] == tab[y])
				return (1);
		}	
	}
	return (0);
}
