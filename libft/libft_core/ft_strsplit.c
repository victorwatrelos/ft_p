/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:42:49 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/11/27 14:09:22 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_tab(char const *s, char c)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			result++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (result);
}

int			get_size_part(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char		**send_end(char **result, int j)
{
	result[j] = NULL;
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	if ((res = (char **)malloc((get_tab(s, c) + 4) * sizeof(char *))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (send_end(res, j));
		res[j] = ft_strnew(get_size_part(s + i, c) + 4);
		k = 0;
		while (s[i] != '\0' && s[i] != c)
			res[j][k++] = s[i++];
		j++;
	}
	res[j] = NULL;
	return (res);
}

