/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:40:03 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/12/11 17:23:38 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_while(unsigned int i, unsigned int j, char *s1, char *s2)
{
	if (s2[j] != '\0' && s1[i + j] != '\0' && s1[i + j] == s2[j])
		return (1);
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			while (i + j < n && test_while(i, j, (char *)s1, (char *)s2))
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
