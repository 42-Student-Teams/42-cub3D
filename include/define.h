/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:24:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/11/10 16:48:41 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//---- CONSTANTS ----
# define WIDTH 1920
# define HEIGHT 1080

//EVENTS ENUM
enum e_events {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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
	int	pos;
}	t_vector;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceiling;
	t_rgb	rgbf;
	t_rgb	rgbc;
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
