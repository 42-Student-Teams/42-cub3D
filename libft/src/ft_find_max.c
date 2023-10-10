/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:13:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/26 21:37:29 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_max(int *tab, int size)
{
	int	max;
	int	i;

	i = -1;
	max = MININT;
	while (++i < size)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	return (max);
}

// int main(void)
// {
// 	int tab[5] = {2,4,3,2,10};
// 	printf("min : %i", ft_find_max(tab, 5));
// 	return (0);
// }