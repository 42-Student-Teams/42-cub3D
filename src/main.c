/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/08 12:26:20 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_debug(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	printf("no :\t%s\n", game->xpm.no);
	printf("so :\t%s\n", game->xpm.so);
	printf("we :\t%s\n", game->xpm.we);
	printf("ea :\t%s\n", game->xpm.ea);
	printf("rgb ceiling :\t%i, %i, %i\n", game->xpm.rgbc.r, game->xpm.rgbc.g, game->xpm.rgbc.b);
	printf("rgb floor :\t\t%i, %i, %i\n\n", game->xpm.rgbf.r, game->xpm.rgbf.g, game->xpm.rgbf.b);
	printf("MAP :\n");
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x - 1)
		{
			printf("%i", game->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}


}

int	main(int ac, char **av)
{
	t_game		game;

	// sleep(40);
	game = (t_game){};
	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
		arg_error(ac);
	parse_map(av[1], &game);
	parse_texture(av[1], &game);
	print_debug(&game);
//	init_game(&game);
	return (0);
}
