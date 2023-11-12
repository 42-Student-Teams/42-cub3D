/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:47 by bverdeci          #+#    #+#             */
/*   Updated: 2023/11/10 16:48:47 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_game(t_game *game)
{
	t_canvas	image;

	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, WIDTH,
			HEIGHT, "Cube3D");
	image.img = mlx_new_image(game->window.mlx, WIDTH, HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.pixel_bits,
			&image.line_length, &image.endian);
	mlx_key_hook(game->window.win, key_event, game);
	mlx_hook(game->window.win, ON_DESTROY, 0, close_window, game);
	mlx_loop(game->window.mlx);
	exit (0);
}