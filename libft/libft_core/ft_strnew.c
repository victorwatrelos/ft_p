/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:23:22 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/26 16:31:58 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	size++;
	str = (char*) malloc(sizeof(char*) * size);
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size-- - 1] = '\0';
	return (str);
}
