/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:49:23 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 13:55:48 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_del_space(const char *str)
{
	while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\v'
				|| *str == '\n' || *str == '\r' || *str == '\f'))
	{
		str++;
	}
	return ((char *)str);
}

int			ft_atoi(const char *str)
{
	int		result;
	int		neg;
	char	*str2;

	result = 0;
	str2 = ft_del_space(str);
	neg = 1;
	if (str2[0] == '-')
	{
		neg = -1;
		str2++;
	}
	else if (str2[0] == '+')
		str2++;
	while (*str2 >= '0' && *str2 <= '9')
	{
		result *= 10;
		result += (*str2++ - '0') * neg;
	}
	return (result);
}
