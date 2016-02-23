/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:53:48 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/25 15:53:25 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2,
		int c, size_t n)
{
	size_t			i;
	unsigned char	value;
	unsigned char*	s3;
	const char*		s4;


	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (s1);
	value = (unsigned char) c;
	i = 0;
	s3 = s1;
	s4 = s2;
	while (i < n && s4[i] != value)
	{
		s3[i] = s4[i];
		i++;
	}
	if (s4[i] == value)
	{
		s3[i] = s4[i];
		return (s1 + i + 1);
	}
	return (NULL);
}
