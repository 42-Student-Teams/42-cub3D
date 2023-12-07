/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/07 13:04:52 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_game		game;

	// sleep(20);
	game = (t_game){};
	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
		arg_error(ac);
	parse_map(av[1], &game);
	parse_texture(av[1], &game);
	init_game(&game);
	return (0);
}
