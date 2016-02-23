/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:40:54 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/25 15:54:26 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	ptr = (unsigned char *)s;
	value = (unsigned char) c;
	while (i < n && ptr[i] != value)
		i++;
	if (ptr[i] == value)
		return ((void *)(s + i));
	return (NULL);
}
