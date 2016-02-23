/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:40:56 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 14:52:25 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_s2;

	size_s2 = ft_strlen(s2);
	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			if (ft_strlen(s1 + i) < size_s2)
				return (NULL);
			j = 0;
			while (s1[i + j] == s2[j] && s2[j] != '\0' && s1[i + j] != '\0')
				j++;
			if (s2[j] == '\0')
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
