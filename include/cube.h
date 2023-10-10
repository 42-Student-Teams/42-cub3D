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
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_canvas
{
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_canvas;

typedef struct s_window
{
	void		*mlx;
	void		*win;
}	t_window;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_game
{
	t_vector	size;
	t_vector	playerpos;
	t_window	window;
	int			**map;
	int			item;
	int			item_count;
	int			moves;
	int			exit;
	int			players;
	t_canvas	sprites[5];
}	t_game;

t_vector	init_map_size(char *path);
void		parse_map(char *path, t_game *game);
void		check_extension(char *path);
void		error(char *message);
void		arg_error(int ac);
void		generate_map(t_game *game, int fd, char *temp);
int			check_elements(char c, t_game *game);
void		check_min_amount(t_game *game);
void		check_wall(t_game *game);
void		check_is_solvable(int x, int y, t_game *game);
void		check_valid_path(t_game *game);
void		init_sprites(t_game *game);
t_canvas	init_image(void *mlx, char *filepath);
int			draw_map(t_game *game);
int			hook_exit(t_game *game);
int			key_hook(int key, t_game *game);
int			hook_move(t_vector new_pos, t_game *game);
void		end_program(t_game *game);
void		print_msg(char *message, t_game *game);

enum
{
	EMPTY,
	ITEMS,
	EXIT,
	PLAYER,
	WALL,
};

#endif