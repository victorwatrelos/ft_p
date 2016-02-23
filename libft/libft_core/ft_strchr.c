/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:03:58 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 16:28:40 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	value;

	value = (char)c;
	i = 0;
	while (s[i] != value && s[i] != '\0')
		i++;
	if (s[i] == value)
		return ((char *)(s + i));
	return (NULL);
}
