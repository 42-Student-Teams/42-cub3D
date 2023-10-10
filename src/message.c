/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:48 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/11 15:21:59 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	if (message)
	{
		ft_putstr_fd("So_long: Error: ", 2);
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

void	print_msg(char *message, t_game *game)
{
	if (message)
	{
		ft_putstr_fd("So_long: : ", 2);
		if (game->item == game->item_count
			&& game->map[game->playerpos.y][game->playerpos.x] == EXIT)
			ft_putendl_fd(message, 2);
		else
		{
			ft_putstr_fd(message, 2);
			ft_putnbrendl_fd(game->moves, 1);
		}
	}
}

void	end_program(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	exit(0);
}
