/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:16 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/09 11:14:37 by bverdeci         ###   ########.fr       */
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
void		fill_start_line(char *new_el);
int			max_line_len(char *tmp, int max);
void		print_map(t_game *game);

// INIT
int			init_game(t_game *game);
void		init_player(t_player *player, t_game *game);
void		player_direction(t_player *player, t_game *game);
t_canvas	*init_texture(t_game *game);

// HOOK
int			key_event(int keycode, t_player *player);
int			close_window(t_game *game);
int			key_press(int keycode, t_player *player);
int			key_release(int keycode, t_player *player);


// MOVE
void		go_straight(t_player *player);
void		go_back(t_player *player);
void		rotate_right(t_player *player);
void		rotate_left(t_player *player);
void		go_left(t_player *player);
void		go_right(t_player *player);
void		move(t_player *p);


// DRAW
void		my_mlx_pixel_put(t_canvas *data, int x, int y, int color);
int			draw_map(t_player *p);
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

// PARSE
int			set_texture(char *temp, t_game *game, int cpt[4], int i);
t_rgb		get_color_value(char *str);
void		parse_files(t_game *game);
void		check_files(t_game *game);
void		parse_texture(char *file, t_game *game);
void		check_min_max_texture(int cpt[4]);
void		get_texture(char *temp, int fd, t_game *game);
void		check_file_exist(char *path);
void		remove_newline(char *str);
void		skip_spaces(char **temp);
char		*skip_spaces_safe(char *temp);
void		check_color_rgb(t_rgb new_rgb);
int			get_color_file(char *temp, t_game *game, int i);
void		check_min_max_texture(int cpt[4]);
void		check_min_max_colors(t_game *game);
void		get_texture(char *temp, int fd, t_game *game);
void		count_commas(char **rgb);
char		*remove_all_spaces(char *str);
t_rgb		big_trim(char **str);
void		init_cardinal_cpt(int cpt[4]);
void		skip_line(char **temp, int fd);
void		check_texture(char *temp);
void		copy_result(char *str, char *result, int count, int j);
int			ft_isspace(char c);
char		*skip_spaces_safe2(char *temp);

#endif