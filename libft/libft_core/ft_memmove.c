/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:04:40 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 14:43:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (n + 4));
	if (temp == NULL)
	{
		return (NULL);
	}
	ft_memcpy(temp, s2, n);
	ft_memcpy(s1, temp, n);
	free(temp);
	return (s1);
}
