/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:17:41 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 14:59:01 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t				size_s1;
	size_t				size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (size_s2 > n)
	{
		ft_memcpy(s1 + size_s1, s2, n);
		s1[size_s1 + n] = '\0';
	}
	else
	{
		ft_strcat(s1, s2);
	}
	return (s1);
}
