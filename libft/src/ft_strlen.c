/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:06:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/01 10:46:53 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		i ++;
	}
	return (i);
}

// #include <stdio.h>
// int main ()
// {
// 	int e = 0;
// 	char tab[] = "sadsd";

// 	e = ft_strlen(tab);

// 	printf("%d", e);
// }