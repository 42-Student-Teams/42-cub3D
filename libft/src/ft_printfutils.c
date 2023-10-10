/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:10:08 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/01/18 12:06:28 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printchar(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_printstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i])
	{
		ft_printchar(str[i], len);
		i ++;
	}
}

void	ft_print_unsigned(unsigned int num, int *len)
{
	if (num >= 10)
		ft_print_unsigned(num / 10, len);
	ft_printchar(num % 10 + '0', len);
}

void	ft_putptr(size_t num, int *len)
{
	if (num >= 16)
	{
		ft_putptr(num / 16, len);
		ft_putptr(num % 16, len);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0', len);
		else
			ft_printchar(num - 10 + 'a', len);
	}
}

void	ft_printptr(size_t num, int *len)
{
	ft_printstr("0x", len);
	if (num == 0)
		ft_printchar('0', len);
	else
		ft_putptr(num, len);
}
