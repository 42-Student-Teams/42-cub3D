/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:47 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/07 14:10:57 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	
							:: TODO ::
	
	1. Plane x,y et dir x,y changent par rapport à la direction.
	-> pour ça il me faut la direction de départ donc la lettre du joueur
	-> N, S, W ou E 

	2. La poition du joueur n'est pas gardé en mémoire.	
	-> checker le moment ou les variables game.playerspos.x,y ont été initialisées.
	
*/

void	init_player(t_player *player, t_game *game)
{
	player->game = game;
	player->pos.x = game->playerpos.x;
	player->pos.y = game->playerpos.y;
	player->dir.x = -1.0;
	player->dir.y = 0.0;
	player->plane.x = 0;
	player->plane.y = 0.66;
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

void	draw_map(t_game *game, t_player *p)
{
	int	x;
	int	side;		

	x = -1;
	x = 0;
	side = 0;
	while (++x < SCREEN_W)
	{
		p->cam.camera_x = 2 * x / (double)(SCREEN_W) - 1;
		p->ray.dir.x = p->dir.x + p->plane.x * p->cam.camera_x;
		p->ray.dir.y = p->dir.y + p->plane.y * p->cam.camera_x;
		p->ray.square.x = (int)p->pos.x;
		p->ray.square.y = (int)p->pos.y;
		p->ray.delta_dist.x = fabs(1 / p->ray.dir.x);
		p->ray.delta_dist.y = fabs(1 / p->ray.dir.y);
		evaluate_ray(*p, &p->ray);
		dda_algorithme(game, &p->ray, &side);
		p->cam.wall_dist = find_wall_dist(p->ray, side);
		calculate_wall(&p->cam);
		draw_ceiling(&game->image, p->cam.start, x, game->ceiling);
		draw_walls(side, p, game, x);
		draw_floor(&game->image, p->cam.end, x, game->floor);
	}
	mlx_put_image_to_window(game->window.mlx, game->window.win,
		game->image.img, 0, 0);
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
	printf("cam vals : %f %d\n", player.cam.camera_x, player.cam.start);
	player.texture = init_texture(game);
	game->floor = rgb_to_int(game->xpm.rgbf);
	game->ceiling = rgb_to_int(game->xpm.rgbc);
	init_player(&player, game);
	draw_map(game, &player);
	mlx_key_hook(game->window.win, key_event, &player);
	mlx_hook(game->window.win, ON_DESTROY, 0, close_window, game);
	mlx_hook(game->window.win, ON_KEYDOWN, 0, key_event, &player);
	mlx_loop(game->window.mlx);
	exit (0);
}
