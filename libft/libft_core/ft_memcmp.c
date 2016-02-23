/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:21:27 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/25 15:54:45 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && str1[i] - str2[i] == 0)
	{
		i++;
	}
	if (i >= n)
	{
		return (0);
	}
	return (str1[i] - str2[i]);
}
