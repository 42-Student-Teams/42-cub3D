/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:31:28 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/27 01:09:52 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *tab, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (tab[0] == c || tab[0] == '\0')
		j --;
	while (tab[i])
	{
		if (tab[i] == c && tab[i + 1] != '\0' && tab[i + 1] != c)
			j ++;
		i ++;
	}
	return (j + 1);
}
