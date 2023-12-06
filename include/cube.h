/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:16 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/06 15:23:55 by bverdeci         ###   ########.fr       */
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

//--- GAME ---

// INIT
int			init_game(t_game *game);
void 		init_player(t_player *player, t_game *game, t_canvas *texture);

// HOOK
int			key_event(int keycode, t_player *player);
int			close_window(t_game *game);

// DRAW
void		my_mlx_pixel_put(t_canvas *data, int x, int y, int color);
void		draw_map(t_canvas *img, t_game *game, t_player player, t_canvas texture);

// CALCULS
void		evaluate_ray(t_player player, t_ray *ray);
void		dda_algorithme(t_game *game, t_ray *ray, int *side);
double		find_wall_dist(t_ray ray, int side);
void		calculate_wall(t_cam *cam);

#endif