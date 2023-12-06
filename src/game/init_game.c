/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:47 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/06 01:26:47 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void init_player(t_player *player, t_game *game, t_canvas *texture)
{
	player->texture = texture;
	player->game = game;
	player->pos.x = 22; //(double)game->playerpos.x;	
	player->pos.y = 12; //(double)game->playerpos.y;	
	player->dir.x = -1.0;
	player->dir.y = 0.0;
	player->plane.x = 0;
	player->plane.y = 0.66; // for the player FOV (field of view)
}

void	my_mlx_pixel_put(t_canvas *data, int x, int y, int color)
{
	data->addr[y * data->line_length / 4 + x] = color;
}

void	evaluate_ray(t_player player, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player.pos.x - ray->square.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->square.x + 1 - player.pos.x) * ray->delta_dist.x; // + 1 parce que le mur est a droite
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player.pos.y - ray->square.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->square.y + 1 - player.pos.y) * ray->delta_dist.y; // + 1 parce que le mur est en haut
	}
}

void	dda_algorithme(t_game *game, t_ray *ray, int *side)
{
	int	hit;

	hit = 0;
	(void)game;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->square.x += ray->step.x;
			*side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->square.y += ray->step.y;
			*side = 1;
		}
		// if (game->map[ray->square.y][ray->square.x] > 0)
		if (worldMap[ray->square.x][ray->square.y] > 0)
			hit = 1;
	}
}

int	find_wall_dist(t_ray ray, int side)
{
	if (side == 0)
		return ray.side_dist.x - ray.delta_dist.x;
	return ray.side_dist.y - ray.delta_dist.y;
}

void	calculate_wall(t_cam *cam)
{
	int	line_height;

	line_height = (int)((double)SCREEN_H / cam->wall_dist);
	cam->start = (-1 * line_height) + (SCREEN_H / 2);
	if (cam->start < 0)
		cam->start = 0;
	cam->end = line_height + SCREEN_H / 2;
	if (cam->end >= SCREEN_H)
		cam->end = SCREEN_H - 1;
}

void	draw_line(t_canvas *img, t_cam	*cam, int x, int color)
{
	int	start;
	int	end;

	start = cam->start;
	end = cam->end;
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

void	draw_map(t_canvas *img, t_game *game, t_player player, t_canvas	texture)
{
	int			x;
	t_ray		ray;
	t_cam		cam;
	int			side;

	x = -1;
	while (++x < SCREEN_W)
	{
		cam.camera_x =  2 * x / (double)(SCREEN_W) - 1; // x coordinate on the camera plane, so we have -1 on the left of the screen , 0 in the middle and 1 on the right.
		// ray vector calculation
		ray.dir.x = player.dir.x + player.plane.x * cam.camera_x;
		ray.dir.y = player.dir.y + player.plane.y * cam.camera_x;
		
		// represent the current square of the map the ray is in
		ray.square.x = (int)player.pos.x;
		ray.square.y = (int)player.pos.y;
		
		// length of ray from x-side or y-side to next one
		ray.delta_dist.x =  fabs(1 / ray.dir.x);
		ray.delta_dist.y =  fabs(1 / ray.dir.y);
		
		evaluate_ray(player, &ray); // sert à savoir dans quelle direction le ray va 
		dda_algorithme(game, &ray, &side); // find where a ray hit a wall
		cam.wall_dist = find_wall_dist(ray, side);
		calculate_wall(&cam);
		double wall_x;
		if (side == 0)
			wall_x = player.pos.y + cam.wall_dist * ray.dir.y;
		else
			wall_x = player.pos.x + cam.wall_dist * ray.dir.x;
		wall_x -= (int)wall_x;
		int tex_x;
		tex_x = (int)(wall_x * (double)texture.width);
		if(side == 0 && ray.dir.x > 0) 
			tex_x = texture.width - tex_x - 1;
      	if(side == 1 && ray.dir.y < 0) 
			tex_x = texture.width - tex_x - 1;
		int line_height = (int)((double)SCREEN_H / cam.wall_dist);
		double step = 1.0 * (double)texture.height / line_height;
		double tex_pos = ((double)(cam.start - SCREEN_H / 2 + line_height / 2)) * step;
		while (cam.start <= cam.end)
		{
			int tex_y = (int)tex_pos & texture.height - 1;
			int color =  texture.addr[tex_y * texture.line_length / 4 + tex_x];
			if (side == 0)
				color /= 2;
			tex_pos += step;
			my_mlx_texture_put(img, x, cam.start, color);
			cam.start++;
		} 
		//draw_line(img, &cam, x, color);
	}
	mlx_put_image_to_window(game->window.mlx, game->window.win, game->image.img, 0, 0);
	mlx_string_put(game->window.mlx, game->window.win, 20, 20, WHITE, "Carmi je t'aime");
}

int	init_game(t_game *game)
{
	t_player	player;
	t_canvas	texture;

	init_player(&player, game, &texture);
	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, SCREEN_W,
			SCREEN_H, "Cube3D");
	game->image.img = mlx_new_image(game->window.mlx, SCREEN_W, SCREEN_H);
	game->image.addr = (int *)mlx_get_data_addr(game->image.img, &game->image.pixel_bits,
	 		&game->image.line_length, &game->image.endian);
	texture.img = mlx_xpm_file_to_image(game->window.win, "maps/textures/red.xpm", &texture.width, &texture.height);
	texture.addr = (int *)mlx_get_data_addr(texture.img, &texture.pixel_bits, &texture.line_length, &texture.endian);
	draw_map(&game->image, game, player, texture);
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