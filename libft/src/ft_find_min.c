/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:45:15 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/27 01:10:21 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_min(int *tab, int size)
{
	int	min;
	int	i;

	i = -1;
	min = MAXINT;
	while (++i < size)
	{
		if (tab[i] < min)
			min = tab[i];
	}
	return (min);
}

// int main(void)
// {
// 	int tab[5] = {5,4,3,2,-1};
// 	printf("min : %i", ft_find_min(tab, 5));
// 	return (0);
// }