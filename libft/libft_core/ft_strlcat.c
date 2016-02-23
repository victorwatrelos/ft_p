/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:09:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/25 15:59:02 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int				i;
	unsigned int	start;
	unsigned int	result;

	start = ft_strlen(dst);
	result = ft_strlen(src) + start;
	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (start < size - 1 && src[i] != '\0')
	{
		dst[start] = src[i];
		start++;
		i++;
	}
	dst[start] = '\0';
	if (size < ft_strlen(dst))
	{
		return (size + ft_strlen(src));
	}
	return (result);
}
