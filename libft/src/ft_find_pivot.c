/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:33:51 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/27 01:09:16 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_pivot(int *tab, int size)
{
	int	min;
	int	max;
	int	pivot;
	int	i;

	i = -1;
	pivot = 0;
	min = ft_find_min(tab, size);
	max = ft_find_max(tab, size);
	while (++i < size)
	{
		if (min != tab[i] && max != tab[i])
			pivot = tab[i];
	}
	return (pivot);
}
