/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:38:26 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/25 16:44:33 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (s1);
}
