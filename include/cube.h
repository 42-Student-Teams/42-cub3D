/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:16 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/08 14:51:26 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/10 15:04:19 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "libft.h"
# include "mlx.h"
# include "hook.h"
# include "define.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>

int			init_map_size(char *path, t_game *game);
int			get_nb_cols_map(char *path, t_game *game);
void		parse_map(char *path, t_game *game);
void		check_extension(char *path);
void		error(char *message);
void		arg_error(int ac);
void		generate_map(t_game *game, int fd, char *temp);
int			check_elements(char c, t_game *game);
void		check_min_amount(t_game *game);
void		parse_texture(char *file, t_game *game);
int			check_open_fd(char *path, int fd);
char		*check_fd(int fd, char *tmp);
void		check_wall(t_game *game);
void		check_is_solvable(int x, int y, t_game *game);
void		check_valid_path(t_game *game);
void		init_sprites(t_game *game);
t_canvas	init_image(void *mlx, char *filepath);
int			hook_exit(t_game *game);
int			key_hook(int key, t_game *game);
int			hook_move(t_vector new_pos, t_game *game);
void		end_program(t_game *game);

//	PARSE UTILS
void		is_player(t_game *game, int y, int x);
void		fill_start_line(char *new);
int			max_line_len(char *tmp, int max);
void		print_map(t_game *game);



//--- GAME ---

// INIT
int			init_game(t_game *game);
void		init_player(t_player *player, t_game *game);
void		player_direction(t_player *player, t_game *game);
t_canvas	*init_texture(t_game *game);

// HOOK
int			key_event(int keycode, t_player *player);
int			close_window(t_game *game);

// MOVE
void		go_straight(t_player *player);
void		go_back(t_player *player);
void		rotate_right(t_player *player);
void		rotate_left(t_player *player);
void		go_left(t_player *player);
void		go_right(t_player *player);

// DRAW
void		my_mlx_pixel_put(t_canvas *data, int x, int y, int color);
void		draw_map(t_game *game, t_player *p);
void		draw_floor(t_canvas *img, int val, int x, int color);
void		draw_ceiling(t_canvas *img, int val, int x, int color);
void		draw_walls(int side, t_player *p, t_game *game, int x);
int			rgb_to_int(t_rgb rgb);

// CALCULS
void		evaluate_ray(t_player player, t_ray *ray);
void		dda_algorithme(t_game *game, t_ray *ray, int *side);
double		find_wall_dist(t_ray ray, int side);
void		calculate_wall(t_cam *cam);
void		walls_calculs(t_player *p, int side);

#endif