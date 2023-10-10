/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:47:47 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/17 09:17:20 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i = 1;
	while (num != 0)
	{
		i ++;
		num /= 10;
	}
	return (i);
}

static char	*ft_change(unsigned int num, long int len, char *t)
{
	while (num > 0)
	{
		t[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	char		*tab;
	long int	i;

	i = ft_len(n);
	tab = malloc((sizeof(char) * i) + 1);
	if (!tab)
		return (0);
	tab[i--] = 0;
	if (n == 0)
		tab[0] = '0';
	if (n < 0)
	{
		n *= -1;
		tab[0] = '-';
	}
	ft_change(n, i, tab);
	return (tab);
}
