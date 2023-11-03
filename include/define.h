/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:24:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/11/03 18:51:02 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

enum e_elements
{
	FLOOR,
	WALL,
	SPACE,
	PLAYER_N,
	PLAYER_E,
	PLAYER_S,
	PLAYER_W,
};

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
	int pos;
}	t_vector;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceiling;
	int 	f;
	int		c;
	int		cptcolors;
}	t_texture;

typedef struct s_game
{
	t_vector	size;
	t_vector	playerpos;
	t_window	window;
	int			**map;
	int			players;
	t_texture	xpm;

}	t_game;

#endif
