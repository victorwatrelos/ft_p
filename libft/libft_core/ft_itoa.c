/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:04:20 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/12/11 17:16:50 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_i(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*manage_max(void)
{
	char	*str;

	str = ft_strnew(11);
	ft_strcpy(str, "-2147483648");
	return (str);
}


char		*ft_itoa(int n)
{
	int		power;
	int		i;
	int		tmp;
	char	*str;

	if (n == INT_MIN)
		return (manage_max());
	i = calc_i(n);
	str = ft_strnew(i + 1);
	if ((tmp = n) < 0)
		str++[0] = '-';
	if ((tmp = n) < 0)
		tmp *= -1;
	power = 10;
	while (i >= 0)
	{
		str[i--] = (char)((tmp % power) + '0');
		tmp = tmp / 10;
	}
	if (n < 0)
		str--;
	return (str);
}
