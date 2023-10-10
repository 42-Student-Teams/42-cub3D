/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allok.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:30:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/05 14:42:17 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_allok(int num, int size, int exit_on_null)
{
	void	*res;

	res = ft_calloc(num, size);
	if (res == 0 && exit_on_null)
		ft_garbage_collector(res, 1, 1);
	else
		ft_garbage_collector(res, 0, 0);
	return (res);
}
