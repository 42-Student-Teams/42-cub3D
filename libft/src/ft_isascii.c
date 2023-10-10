/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:06:04 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/10/27 10:55:11 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>
// int main ()
// {
// 	int i;

// 	i = ft_isascii('@');
// 	printf("%d \n",i);
// 	i = ft_isascii('\'');
// 	printf("%d \n",i);
// 	i = ft_isascii('=');
// 	printf("%d \n",i);
// 	i = ft_isascii('');
// 	printf("%d \n",i);
// 	i = ft_isascii(0x80);
// 	printf("%d \n",i);
// 	i = ft_isascii('a');
// 	printf("%d \n",i);
// 	i = ft_isascii();
// 	printf("%d \n",i);
// }