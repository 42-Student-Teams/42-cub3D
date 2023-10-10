/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:08:07 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/03 16:46:33 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*freetab(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static size_t	count_char(const char *tab, char c)
{
	int	i;

	i = 0;
	while (tab[i] && tab[i] != c)
		i ++;
	return (i);
}

static int	count_tab(const char *tab, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (tab[0] == c || tab[0] == '\0')
		j --;
	while (tab[i])
	{
		if (tab[i] == c && tab[i + 1] != '\0' && tab[i + 1] != c)
			j ++;
		i ++;
	}
	return (j + 1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		lentab;
	char	**tab_all;

	i = 0;
	if (!s)
		return (0);
	lentab = count_tab(s, c);
	tab_all = malloc(sizeof(char *) * (lentab + 1));
	if (!tab_all)
		return (NULL);
	while (i < lentab)
	{
		while (*s == c && *s)
			s ++;
		tab_all[i] = ft_substr(s, 0, count_char(s, c));
		if (tab_all[i] == NULL)
			return (freetab(tab_all, i));
		s += count_char(s, c);
		i ++;
	}
	tab_all[i] = 0;
	return (tab_all);
}
