/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42l>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:24 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/10 15:33:29 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:32:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/10/10 14:54:39 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



void	check_valid_path(t_game *game)
{
	int	i;
	int	j;

	if (game->item_count != game->item)
		error("Can't reach all the items");
	if (game->exit != 1)
		error("Can't reach the exit");
	i = -1;
	while (++i < game->size.y)
	{
		j = -1;
		while (++j < game->size.x)
		{
			if (game->map[i][j] >= 10)
				game->map[i][j] -= 10;
		}
	}
}


int	main(int argc, char **argv)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		arg_error(argc);
	parse_map(argv[1], &game);
	init_game(&game);
	return (0);
}
