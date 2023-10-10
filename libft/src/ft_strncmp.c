/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:53:02 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/10/27 23:19:31 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i ++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {  
// 	char str1[] = "abcd";
// 	char str2[] = "abCd";
// 	char str3[] = "abcd";
// 	int result;
// 	result = ft_strncmp(str1, str2, 2);
// 	printf("strcmp(str1, str2) = %d\n", result);
// 	result = ft_strncmp(str1, str3, 3);
// 	printf("strcmp(str1, str3) = %d\n", result);
// }