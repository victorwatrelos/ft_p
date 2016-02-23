/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:49:23 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/25 15:57:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	size;
	unsigned int	i;

	size = ft_strlen(s2);
	i = 0;
	while (i < n)
	{
		if (i >= size)
		{
			s1[i] = '\0';
		}
		else
		{
			s1[i] = s2[i];
		}
		i++;
	}
	return (s1);
}
