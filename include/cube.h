/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:16 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/11/09 10:38:25 by leon             ###   ########.fr       */
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
void		print_debug(t_game *game);
void		check_wall(t_game *game);
void		check_is_solvable(int x, int y, t_game *game);
void		check_valid_path(t_game *game);
void		init_sprites(t_game *game);
int			init_game(t_game *game);

#endif