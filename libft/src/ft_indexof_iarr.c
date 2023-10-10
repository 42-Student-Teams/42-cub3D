/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof_iarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:25:46 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/17 16:53:25 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_indexof_iarr(int *tab, int size, int find)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[i] == find)
			return (i);
	}
	return (-1);
}
