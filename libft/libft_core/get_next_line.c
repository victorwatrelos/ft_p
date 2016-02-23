/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:38:56 by vwatrelo          #+#    #+#             */
/*   Updated: 2013/12/27 20:59:03 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_join(char **line, int i, int index, char *str)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strnew(ft_strlen(*line) + i);
	if (*line == NULL)
		return (-1);
	ft_strcpy(*line, tmp);
	ft_memcpy(*line + ft_strlen(tmp), str + index, i);
	free(tmp);
	return (0);
}

static int	ft_init_var(int *i, char **ln)
{
	*i = 0;
	*ln = ft_strnew(1);
	if (*ln == NULL)
		return (-1);
	return (0);
}

static void	ft_test_index(int *index, int *ret, int fd, char *str)
{
	if (*index == -1)
	{
		*ret = read(fd, str, BUFF_SIZE);
		*index = 0;
	}
}

static int	test_loop(int *ret, char *str, int fd)
{
	*ret = read(fd, str, BUFF_SIZE);
	if (*ret == 0)
		return (1);
	return (0);
}


int			get_next_line(int const fd, char **line)
{
	static int		index = -1;
	static char		str[BUFF_SIZE + 4];
	static int		ret;
	int				i;

	ft_init_var(&i, line);
	ft_test_index(&index, &ret, fd, str);
	while (ret != -1 && str[i + index] != '\n' && str[i + index] != EOF)
	{
		if (i + index == ret)
		{
			if (ft_join(line, i, index, str) != -1
					&& (i = test_loop(&ret, str, fd)) == 1)
				return (0);
			if (i == -1)
				return (-1);
			index = 0;
		}
		else
			i++;
	}
	if (ret == -1 || ft_join(line, i, index, str) == -1)
		return (-1);
	index = i + index + 1;
	return (1);
}
