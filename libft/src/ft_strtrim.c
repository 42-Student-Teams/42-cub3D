/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:31:59 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/07 18:06:42 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i ++;
	}
	return (i);
}

static int	gend(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i ++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*tab;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = gstart(s1, set);
	end = gend(s1, set);
	if (end == 0)
		return (ft_strdup(""));
	tab = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!tab)
		return (0);
	ft_strlcpy(tab, s1 + start, end - start + 1);
	return (tab);
}
