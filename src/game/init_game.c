/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:47 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/06 18:16:43 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void init_player(t_player *player, t_game *game, t_canvas *texture)
{
	player->texture = texture;
	player->game = game;
	player->pos.x = 4;	
	player->pos.y = 4;	
	player->dir.x = -1.0;
	player->dir.y = 0.0;
	player->plane.x = 0;
	player->plane.y = 0.66; // for the player FOV (field of view)
}

void	my_mlx_pixel_put(t_canvas *data, int x, int y, int color)
{
	data->addr[y * data->line_length / 4 + x] = color;
}

void	draw_line(t_canvas *img, int start, int end, int x, int color)
{

	while (start < end)
	{
		my_mlx_pixel_put(img, x, start, color);
		start++;
	}
}

void	my_mlx_texture_put(t_canvas *data, int x, int y, int color)
{
	data->addr[y * data->line_length / 4 + x] = color;
}

void	draw_walls(int side, t_player player, t_canvas *texture, t_game *game, int x)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		line_height;
	int		color;
	int		tex_dir;

	if (side == 0 && player.ray.dir.x < 0)
		tex_dir = 0;
	if (side == 0 && player.ray.dir.x >= 0)
		tex_dir = 1;
	if (side == 1 && player.ray.dir.y < 0)
		tex_dir = 2;
	if (side == 1 && player.ray.dir.y >= 0)
		tex_dir = 3;
	if (side == 0)
		wall_x = player.pos.y + player.cam.wall_dist * player.ray.dir.y;
	else
		wall_x = player.pos.x + player.cam.wall_dist * player.ray.dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texture[tex_dir].width);
	if(side == 0 && player.ray.dir.x > 0) 
		tex_x = texture[tex_dir].width - tex_x - 1;
	if(side == 1 && player.ray.dir.y < 0) 
		tex_x = texture[tex_dir].width - tex_x - 1;
	line_height = (int)((double)SCREEN_H / player.cam.wall_dist);
	step = 1.0 * (double)texture[tex_dir].height / line_height;
	tex_pos = ((double)(player.cam.start - SCREEN_H / 2 + line_height / 2)) * step;
	while (player.cam.start <= player.cam.end)
	{
		tex_y = (int)tex_pos & texture[tex_dir].height - 1;
		color =  texture[tex_dir].addr[tex_y * texture[tex_dir].line_length / 4 + tex_x];
		if (side == 0)
			color /= 2;
		tex_pos += step;
		my_mlx_texture_put(&game->image, x, player.cam.start, color);
		player.cam.start++;
	} 
}

void	draw_map(t_game *game, t_player player, t_canvas *texture)
{
	int	x;
	int	side;		

	x = -1;
	while (++x < SCREEN_W)
	{
		player.cam.camera_x =  2 * x / (double)(SCREEN_W) - 1; 
		player.ray.dir.x = player.dir.x + player.plane.x * player.cam.camera_x;
		player.ray.dir.y = player.dir.y + player.plane.y * player.cam.camera_x;
		player.ray.square.x = (int)player.pos.x;
		player.ray.square.y = (int)player.pos.y;
		player.ray.delta_dist.x =  fabs(1 / player.ray.dir.x);
		player.ray.delta_dist.y =  fabs(1 / player.ray.dir.y);
		evaluate_ray(player, &player.ray);
		dda_algorithme(game, &player.ray, &side);
		player.cam.wall_dist = find_wall_dist(player.ray, side);
		calculate_wall(&player.cam);
		draw_line(&game->image, 0,player.cam.start, x, game->ceiling);
		draw_walls(side, player, texture, game, x);
		draw_line(&game->image, player.cam.end, SCREEN_H, x, game->floor);
	}
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->image.img, 0, 0);
}

t_canvas	*init_texture(t_game *game)
{
	t_canvas *texture;

	texture = ft_calloc(5, sizeof(t_canvas));
	if (!texture)
		error("malloc error");
	texture[0].img = mlx_xpm_file_to_image(game->window.win, game->xpm.no, &texture[0].width, &texture[0].height);
	texture[0].addr = (int *)mlx_get_data_addr(texture[0].img, &texture[0].pixel_bits, &texture[0].line_length, &texture[0].endian);
	texture[1].img = mlx_xpm_file_to_image(game->window.win, game->xpm.so, &texture[1].width, &texture[1].height);
	texture[1].addr = (int *)mlx_get_data_addr(texture[1].img, &texture[1].pixel_bits, &texture[1].line_length, &texture[1].endian);
	texture[2].img = mlx_xpm_file_to_image(game->window.win, game->xpm.we, &texture[2].width, &texture[2].height);
	texture[2].addr = (int *)mlx_get_data_addr(texture[2].img, &texture[2].pixel_bits, &texture[2].line_length, &texture[0].endian);
	texture[3].img = mlx_xpm_file_to_image(game->window.win, game->xpm.ea, &texture[3].width, &texture[3].height);
	texture[3].addr = (int *)mlx_get_data_addr(texture[3].img, &texture[3].pixel_bits, &texture[3].line_length, &texture[3].endian);
	return texture;
}

int	rgb_to_int(t_rgb rgb)
{
	int r;
	int g;
	int	b;
	
	r = rgb.r;
	g = rgb.g;
	b = rgb.b;
	return ((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff);
}

int	init_game(t_game *game)
{
	t_player	player;
	t_canvas	*texture;

	ft_bzero(&player, sizeof(t_player));
	ft_bzero(&texture, sizeof(t_texture *));
	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, SCREEN_W,
			SCREEN_H, "Cube3D");
	game->image.img = mlx_new_image(game->window.mlx, SCREEN_W, SCREEN_H);
	game->image.addr = (int *)mlx_get_data_addr(game->image.img, &game->image.pixel_bits,
	 		&game->image.line_length, &game->image.endian);
	texture = init_texture(game);
	
	game->floor = rgb_to_int(game->xpm.rgbf);
	game->ceiling = rgb_to_int(game->xpm.rgbc);
	init_player(&player, game, texture);
	draw_map(game, player, texture);
	mlx_key_hook(game->window.win, key_event, &player);
	mlx_hook(game->window.win, ON_DESTROY, 0, close_window, game);
	mlx_hook(game->window.win, ON_KEYDOWN, 0, key_event, &player);
	mlx_loop(game->window.mlx);
	exit (0);
}
 /*
void	draw_2Dmap(t_game *game, t_player *player)
{
	int i;
	int j;
	int side;
	int color;
	
	i = -1;
	while(++i < SCREEN_W)
	{
		j = -1;
		while(++j < SCREEN_H)
			my_mlx_pixel_put(&game->image, i, j, WHITE / 3);
	}
	i = -1;
	side = 50;
	while(++i < 8)
	{
		j = -1;
		while(++j < 12)
		{
			printf("%d ", worldMap[i][j]);
			if (worldMap[i][j] == 1)
				color = RED;
			else
				color = WHITE;
			draw_square(j * side, i * side, &game->image, color, side - 1);
		}
		printf("\n");
	}
	draw_square(player->pos.x * side, player->pos.y * side, &game->image, GREEN, 25);
	i = -1;
	while (++i < 20)
	{
		my_mlx_pixel_put(&game->image, player->pos.x * side + 99, player->pos.y * side + 99, GREEN);
	}
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->image.img, 0, 0);
	
}

int	event(int keycode, t_player *player)
{
	mlx_destroy_image(player->game->window.mlx, player->game->image.img);
	player->game->image.img = mlx_new_image(player->game->window.mlx, SCREEN_W, SCREEN_H);
	player->game->image.addr = (int *)mlx_get_data_addr(player->game->image.img, &player->game->image.pixel_bits,
			&player->game->image.line_length, &player->game->image.endian);	
	if (keycode == KEYCODE_ESC)
		close_window(player->game);
	if (keycode == KEYCODE_W)
	{
		player->pos.x -= sin(player->plane.x);
		player->pos.y -= cos(player->plane.x);
	}
	if (keycode == KEYCODE_S)
	{
		player->pos.x += sin(player->plane.x);
		player->pos.y += cos(player->plane.x);
	}
	if (keycode == KEYCODE_D)
	{
		player->plane.x -= 0.1;
	}
	if (keycode == KEYCODE_A)
	{
		player->plane.x += 0.1;
	}
	draw_2Dmap(player->game, player);
	return 0;
}
*/