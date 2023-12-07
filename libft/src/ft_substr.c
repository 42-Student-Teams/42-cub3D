/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <lsaba-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:32:55 by bverdeci          #+#    #+#             */
/*   Updated: 2023/12/07 14:20:51 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_ch(char const *s, char *s2, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = s2;
	while (s[i] && j < len)
	{
		if (i >= start)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		slen;
	long long	possible;

	possible = ft_strlen(s) - start;
	if (possible > 0)
		slen = ft_strlen(s + start);
	if (possible <= 0)
		slen = 0;
	if (len > slen)
		len = slen;
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	str = add_ch(s, str, start, len);
	return (str);
}
