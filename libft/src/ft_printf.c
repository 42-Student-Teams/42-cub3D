/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:49:08 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/01/18 12:06:23 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_arg(va_list *args, char arg, int *len)
{
	if (arg == 'i' || arg == 'd')
		ft_printbase(va_arg(*args, int), "0123456789", 10, len);
	else if (arg == 'c' )
		ft_printchar(va_arg(*args, int), len);
	else if (arg == 's')
		ft_printstr(va_arg(*args, char *), len);
	else if (arg == '%')
		ft_printchar('%', len);
	else if (arg == 'p')
		ft_printptr(va_arg(*args, size_t), len);
	else if (arg == 'x')
		ft_printbase(va_arg(*args, unsigned int),
			"0123456789abcdef", 16, len);
	else if (arg == 'X')
		ft_printbase(va_arg(*args, unsigned int),
			"0123456789ABCDEF", 16, len);
	else if (arg == 'u')
		ft_print_unsigned(va_arg(*args, unsigned int), len);
}		

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i ++;
			check_arg(&args, format[i], &len);
			i ++;
		}
		else
		{	
			ft_printchar((char)format[i], &len);
			i ++;
		}
	}
	va_end(args);
	return (len);
}
/*
int main (int ac, char **av) {
	(void) ac;
	//(void) ac;
	//printf("Hello\n");
	//printf("\nLEN %d\n", ft_printf("%d", -200000));
	printf("Carac [%d]", ft_printf("%d", ft_atoi(av[1])));
	//printf("%d\n", ft_printf("%X\n", ft_atoi(av[1])));
	return (0);
}*/
