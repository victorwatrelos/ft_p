/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:14:29 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 14:39:55 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	*ptr;

	ptr = (unsigned int *)malloc(size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (size > 0)
	{
		ptr[size - 1] = 0;
		size--;
	}
	return (ptr);
}
