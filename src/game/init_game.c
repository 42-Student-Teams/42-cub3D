/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:47 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/09 11:17:40 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_direction(t_player *player, t_game *game)
{
	player->dir.x = 0.0;
	player->dir.y = 1.0;
	player->plane.x = 0.66;
	player->plane.y = 0.0;
	if (game->cardinal == PLAYER_N)
	{
		player->dir.x = -1.0;
		player->dir.y = 0.0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	if (game->cardinal == PLAYER_S)
	{
		player->dir.x = 1.0;
		player->dir.y = 0.0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	if (game->cardinal == PLAYER_W)
	{
		player->dir.x = 0.0;
		player->dir.y = -1.0;
		player->plane.x = -0.66;
		player->plane.y = 0.0;
	}
}

void	init_player(t_player *player, t_game *game)
{
	player->game = game;
	player->pos.x = game->playerpos.x;
	player->pos.y = game->playerpos.y;
	player_direction(player, game);
}

t_canvas	*init_texture(t_game *game)
{
	t_canvas	*t;

	t = ft_calloc(5, sizeof(t_canvas));
	if (!t)
		error("malloc error");
	t[0].img = mlx_xpm_file_to_image(game->window.win, game->xpm.no,
			&t[0].width, &t[0].height);
	t[0].addr = (int *)mlx_get_data_addr(t[0].img,
			&t[0].pixel_bits, &t[0].line_length, &t[0].endian);
	t[1].img = mlx_xpm_file_to_image(game->window.win, game->xpm.so,
			&t[1].width, &t[1].height);
	t[1].addr = (int *)mlx_get_data_addr(t[1].img, &t[1].pixel_bits,
			&t[1].line_length, &t[1].endian);
	t[2].img = mlx_xpm_file_to_image(game->window.win, game->xpm.we,
			&t[2].width, &t[2].height);
	t[2].addr = (int *)mlx_get_data_addr(t[2].img, &t[2].pixel_bits,
			&t[2].line_length, &t[0].endian);
	t[3].img = mlx_xpm_file_to_image(game->window.win, game->xpm.ea,
			&t[3].width, &t[3].height);
	t[3].addr = (int *)mlx_get_data_addr(t[3].img, &t[3].pixel_bits,
			&t[3].line_length, &t[3].endian);
	return (t);
}

int	rgb_to_int(t_rgb rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb.r;
	g = rgb.g;
	b = rgb.b;
	return (((r & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (b & 0x0ff));
}

int	init_game(t_game *game)
{
	t_player	player;

	ft_bzero(&player, sizeof(t_player));
	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, SCREEN_W,
			SCREEN_H, "Cube3D");
	game->image.img = mlx_new_image(game->window.mlx, SCREEN_W, SCREEN_H);
	game->image.addr = (int *)mlx_get_data_addr(game->image.img,
			&game->image.pixel_bits,
			&game->image.line_length, &game->image.endian);
	player.texture = init_texture(game);
	game->floor = rgb_to_int(game->xpm.rgbf);
	game->ceiling = rgb_to_int(game->xpm.rgbc);
	init_player(&player, game);
	draw_map(&player);
	mlx_hook(game->window.win, ON_DESTROY, 0, close_window, game);
	mlx_hook(game->window.win, ON_KEYDOWN, 0, key_press, &player);
	mlx_loop_hook(game->window.mlx, draw_map, &player);
	mlx_hook(game->window.win, ON_KEYUP, 0, key_release, &player);
	mlx_loop(game->window.mlx);
	exit (0);
}
