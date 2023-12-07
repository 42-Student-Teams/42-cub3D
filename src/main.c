/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/07 13:04:28 by lsaba-qu         ###   ########.fr       */
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

	// sleep(20);
	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
		arg_error(ac);
	parse_map(av[1], &game);
	parse_texture(av[1], &game);
	print_debug(&game);
//	init_game(&game);
	return (0);
}
/*
// tout le boulot
void init_player(t_player *player, t_game *game, t_canvas *texture)
{
	player->texture = texture;
	player->game = game;
	player->pos.x = 22; //(double)game->playerpos.x;	
	player->pos.y = 12; //(double)game->playerpos.y;	
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 3.14159 / 4.0; // for the player FOV (field of view)
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

	line_height = (int)(SCREEN_H / cam->wall_dist);
	cam->start = (-1 * line_height / 2) + (SCREEN_H / 2);
	if (cam->start < 0)
		cam->start = 0;
	cam->end = line_height / 2 + SCREEN_H / 2;
	if (cam->end >= SCREEN_H)
		cam->end = SCREEN_H - 1;
}

void	draw_line(t_canvas *img, t_cam	*cam, int x, int color)
{
	int	start;
	int	end;

	start = cam->start;
	end = cam->end;
	while (start <= end)
	{
		my_mlx_pixel_put(img, x, start, color);
		start++;
	}
}

void	my_mlx_texture_put(t_canvas *data, int x, int y, t_canvas *tex, int tex_x, int tex_y)
{
	data->addr[y * data->line_length / 4 + x] = tex->addr[tex_y * tex->line_length / 4 + tex_x];
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
		int line_height = (int)(SCREEN_H / cam.wall_dist);
		double step = 1.0 * texture.height / line_height;
		double tex_pos = (cam.start - SCREEN_H / 2 + line_height / 2) * step;
		while (cam.start < cam.end)
		{
			int tex_y = (int)tex_pos & (texture.height - 1);
			tex_pos += step;
			my_mlx_texture_put(img, x, cam.start, &texture, tex_x, tex_y);
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
*/