/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:50 by leon              #+#    #+#             */
/*   Updated: 2023/12/08 15:24:49 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_min_max_texture(int cpt[4])
{
	if (cpt[0] > 1)
		error("There's more than one texture of NO");
	if (cpt[0] < 1)
		error("There's more less one texture of NO");
	if (cpt[1] > 1)
		error("There's more than one texture of SO");
	if (cpt[1] < 1)
		error("There's more less one texture of SO");
	if (cpt[2] > 1)
		error("There's more than one texture of WE");
	if (cpt[2] < 1)
		error("There's more less one texture of WE");
	if (cpt[3] > 1)
		error("There's more than one texture of EA");
	if (cpt[3] < 1)
		error("There's more less one texture of EA");
}

void	copy_result(char *str, char *result, int count, int j)
{
	while (str[count])
	{
		if (str[count] != ' ')
			result[j++] = str[count];
		++count;
	}
	result[j] = '\0';
}
