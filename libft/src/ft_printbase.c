/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:05 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/01/18 12:06:19 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbase(long long int num, char *format, int base, int *len)
{
	if (num == -2147483648)
	{
		ft_printstr("-2147483648", len);
		return ;
	}
	if (num == 0)
	{
		ft_printchar('0', len);
		return ;
	}
	if (num < 0)
	{
		ft_printchar('-', len);
		ft_printbase((num * -1), format, base, len);
	}
	else if (num >= (unsigned int)base)
	{
		ft_printbase(num / base, format, base, len);
		ft_printbase(num % base, format, base, len);
	}
	else if (num < (unsigned int)base)
		ft_printchar(format[num], len);
}
