/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/11/01 19:51:09 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error(char *message)
{
	if (message)
	{
		ft_putstr_fd("Cub3D: Error: ", 2);
		ft_putendl_fd(message, 2);
	}
	exit(1);
}

void	arg_error(int ac)
{
	if (ac < 2)
		error("too few arguments");
	else
		error("too many arguments");
}

void	end_program(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	exit(0);
}
