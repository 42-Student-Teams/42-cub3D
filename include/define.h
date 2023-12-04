/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:24:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/04 13:26:08 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//---- CONSTANTS ----
# define SCREEN_W 1920
# define SCREEN_H 1080
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF
# define COLOR_Y 0x0000FF00

# define mapWidth 24
# define mapHeight 24
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
	int		*addr;
	int		pixel_bits;
	int		line_length;
	int		endian;
	int		height;
	int		width;
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

typedef struct s_vector_d
{
	double	x;
	double	y;
}	t_vector_d;

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
	t_canvas	image;
	int			**map;
	int			players;
	t_texture	xpm;
}	t_game;

/* player position
 * player direction (la direction dans laquelle il regarde)
 * player plane == camera (ce qu'il voit) 
 * oldtime et time pour le compteur de fps et pour les mouvements */
typedef struct s_player
{
	t_vector_d	pos;
	t_vector_d	dir;
	t_vector_d	plane;
	t_game		*game;
	t_canvas	*texture;
}	t_player;

typedef	struct s_ray 
{
	t_vector_d	dir;
	t_vector_d	side_dist;
	t_vector_d	delta_dist;
	t_vector	square;
	t_vector	step;
}	t_ray;

typedef struct s_cam
{
	int			start;
	int			end;
	double		camera_x;
	double		wall_dist;
}	t_cam;

typedef struct 
{
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		line_length;
	int		endian;
}	t_tex;

#endif
