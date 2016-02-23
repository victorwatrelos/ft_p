/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:20:36 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 16:32:16 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	value;

	value = (char)c;
	i = ft_strlen(s);
	while (s[i] != value && i > 0)
		i--;
	if (s[i] == value)
		return ((char *)(s + i));
	return (NULL);
}
