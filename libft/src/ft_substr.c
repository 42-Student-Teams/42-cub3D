/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:23:35 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/19 18:16:46 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;

	if (start >= ft_strlen(s) || !s || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	tab = (char *)malloc((sizeof(char) * len) + 1);
	if (!tab)
		return (NULL);
	if (tab)
	{
		ft_strlcpy(tab, s + start, len + 1);
		return (tab);
	}
	return (0);
}
