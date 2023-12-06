/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:24:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/12/06 17:02:11 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//---- CONSTANTS ----
# define SCREEN_W 1080
# define SCREEN_H 720
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF
# define GREEN 0x228B22

# define mapWidth 8
# define mapHeight 8

# define DOUBLE_MAX 1.797693e+308
# define PI 3.1415926535
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
	int			floor;
	int			ceiling;
}	t_game;

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
	t_cam		cam;
	t_ray		ray;
}	t_player;

#endif
