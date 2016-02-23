/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:09:54 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 11:07:16 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > 0 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
		n--;
	}
	if (n == 0)
		i--;
	return (s1[i] - s2[i]);
}
