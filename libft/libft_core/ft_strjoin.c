/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:30:28 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 14:44:08 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size_s1;
	int		size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = ft_strnew(size_s1 + size_s2);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
