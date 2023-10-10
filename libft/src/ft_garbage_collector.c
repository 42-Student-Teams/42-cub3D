/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:37:50 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/05 18:31:48 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_garbage_collector(void *ptr, int mode, int _exit)
{
	static t_list	*garbage;
	t_list			*element;

	if (mode == 0)
	{
		if (ptr == 0 && _exit)
			ft_garbage_collector(0, 1, _exit);
		element = ft_lstnew(ptr);
		if (element == 0 && _exit)
			ft_garbage_collector(0, 1, _exit);
		if (element == 0)
			return ;
		ft_lstadd_back(&garbage, element);
	}
	else
	{
		ft_lstclear(&garbage, free);
		if (_exit)
		{
			exit(_exit);
		}
	}
}
