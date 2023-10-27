/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/27 11:21:41 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/06 16:16:23 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

//static void fill_map_line(t_game *game, int y)
//{
//	int	x;
//
//	x = 0;
//	while (x < game->size.x)
//	{
//		game->map[y][x] = WALL;
//		x++;
//	}
//}

static char	*line_fill_wall(t_game *game, char **temp)
{
	int i;
	int len;
	char *new;

	i = -1;
	len = (int)ft_strlen(*temp) +  game->size.x;
	new = ft_calloc(len, sizeof(char));
	if (!new)
		error("Malloc error");
	while (++i < (int)ft_strlen(*temp))
		new[i] = *temp[i];
	if (temp)
		free(temp);
	while (i < len)
	{
		new[i] = '1';
		i++;
	}
	return (new);
}

void	generate_map(t_game *game, int fd, char *temp)
{
	int	x;
	int	y;
	char *new_line;

	y = 0;
	new_line = NULL;
	while (temp)
	{
		x = -1;
		game->map[y] = ft_allok(game->size.x, sizeof(int), 1);
		while (++x < game->size.x)
		{
			if ((int)ft_strlen(temp) != game->size.x)
				new_line = line_fill_wall(game, &temp);
			printf("%s\n", new_line);
			if (new_line[x] == '\n')
				break ;
			game->map[y][x] = check_elements(new_line[x], game);
			if (is_player(game->map[y][x]))
			{
				game->playerpos.x = x;
				game->playerpos.y = y;
			}
		}
		if (new_line[x] == '\n')
			break ;
		free(new_line);

		y ++;
		temp = ft_get_next_line(fd);
	}
	if (temp)
		free(temp);
	if (new_line)
		free(new_line);
	close(fd);
}

t_canvas	init_image(void *mlx, char *filepath)
{
	t_canvas	img;

	img.img = mlx_xpm_file_to_image(mlx, filepath, &img.x, &img.y);
	img.addr = mlx_get_data_addr(img.img,
			&img.pixel_bits, &img.line_length, &img.endian);
	return (img);
}

//void	init_sprites(t_game *game)
//{
//	game->sprites[WALL] = init_image(game->window.mlx,
//			"sprites/sprite-wall.xpm");
//	game->sprites[EXIT] = init_image(game->window.mlx,
//			"sprites/sprite-exit.xpm");
//	game->sprites[EMPTY] = init_image(game->window.mlx,
//			"sprites/sprite-empty.xpm");
//	game->sprites[PLAYER] = init_image(game->window.mlx,
//			"sprites/sprite-player-gs-stand.xpm");
//	game->sprites[ITEMS] = init_image(game->window.mlx,
//			"sprites/sprite-items.xpm");
//}

//int	draw_map(t_game *game)
//{
//	int	x;
//	int	y;
//
//	y = -1;
//	while (++y < game->size.y)
//	{
//		x = -1;
//		while (++x < game->size.x)
//		{
//			mlx_put_image_to_window(game->window.mlx, game->window.win,
//				game->sprites[EMPTY].img, x * 96, y * 96);
//			mlx_put_image_to_window(game->window.mlx, game->window.win,
//				game->sprites[game->map[y][x]].img, x * 96, y * 96);
//		}
//	}
//	return (0);
//}

//int init_game(t_game *game)
//{
//	game->window.mlx = mlx_init();
//	if (game->window.mlx == NULL)
//		exit(EXIT_FAILURE);
//	game->window.win = mlx_new_window(game->window.mlx,
//									  game->size.x * 96, game->size.y * 96, "./cube3D");
//	if (!game->window.win)
//		exit(EXIT_FAILURE);
//	init_sprites(game);
//	draw_map(game);
//	return (0);
//}
