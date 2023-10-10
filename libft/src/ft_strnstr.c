/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:59 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/14 15:20:50 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle != NULL && needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] && haystack[i + j] == needle[j])
			{
				if (needle[j + 1] == 0 && (ft_strlen(needle) + i) <= len)
					return ((char *)&haystack[i]);
				j ++;
			}
		}
		i ++;
	}
	return (NULL);
}
/*
#include "stdio.h"
int main ()
{
	char *res = NULL;
	
	res = ft_strnstr("lorem ipsum dolor sit amet","lorem",15);
	printf("res : %s", res);
}
*/
