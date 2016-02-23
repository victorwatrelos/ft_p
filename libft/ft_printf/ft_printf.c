/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 11:33:23 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/01/23 14:29:58 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char		*get_next(char *str, int *res, int fd)
{
	int		i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	write(fd, str, i);
	*res += i;
	return (str + i);
}

static void		ft_num(int nb, int *res, int fd)
{
	int		size;

	size = 0;
	ft_putnbr_fd(nb, fd);
	if (nb == 0)
		return ;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	*res += size;
}

static void		ft_applied(va_list ap, char c, int *nb_char, int fd)
{
	char	*res;

	if (c == 'd')
		ft_num(va_arg(ap, int), nb_char, fd);
	else if (c == 's')
	{
		if ((res = va_arg(ap, char *)) == NULL)
		{
			nb_char += 6;
			ft_putstr_fd("(null)", fd);
			return ;
		}
		*nb_char += ft_strlen(res);
		ft_putstr_fd(res, fd);
	}
	else if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(ap, int), fd);
		(*nb_char)++;
	}
	else if (c == '%')
	{
		ft_putchar_fd('%', fd);
		(*nb_char)++;
	}
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*tmp;
	int			res;
	int			fd;

	res = 0;
	if (ft_strncmp(str, "%r", 2) == 0)
	{
		str += 2;
		fd = 2;
	}
	else
		fd = 1;
	va_start(ap, str);
	tmp = get_next((char *)str, &res, fd);
	while (*tmp != '\0')
	{
		ft_applied(ap, *(tmp + 1), &res, fd);
		tmp = get_next(tmp + 2, &res, fd);
	}
	va_end(ap);
	return (res);
}
