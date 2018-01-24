#include "get_args.h"

static int		count_args(char *str)
{
	size_t		i;
	char		*arg_pos[2];
	size_t		nb_args;

	i = ~0lu;
	nb_args = 0;
	ft_bzero(arg_pos, sizeof(char *) * 2);
	while (str[++i] != '\0')
	{
		if (str[i] != '"' || ((i > 0 && str[i - 1] == '\\')))
			continue ;
		if (arg_pos[START] == NULL)
			arg_pos[START] = str + i;
		else
			arg_pos[END] = str + i;
		if (arg_pos[START] != NULL && arg_pos[END] != NULL)
		{
			++nb_args;
			ft_bzero(arg_pos, sizeof(char *) * 2);
		}
	}
	if (arg_pos[START] != NULL || arg_pos[END] != NULL)
		return (-1);
	return nb_args;
}

static int		set_arg(char **dst_arg, char *arg, size_t arg_len)
{
	size_t		i;
	char		*dst;

	if ((dst = malloc(arg_len + 1)) == NULL)
		return (-1);
	*dst_arg = dst;
	i = ~0lu;
	while (++i < arg_len)
	{
		if (arg[i] == '\\')
			++i;
		if (i >= arg_len)
			break ;
		*(dst++) = arg[i];
	}
	*dst = '\0';
	return (0);
}

static int		fill_args(char **args, char *str)
{
	size_t		i;
	size_t		arg_nb;
	char		*pos[2];

	i = ~0lu;
	arg_nb = 0;
	ft_bzero(pos, sizeof(char *) * 2);
	while (str[++i] != '\0')
	{
		if (str[i] != '"' || ((i > 0 && str[i - 1] == '\\')))
			continue ;
		if (pos[START] == NULL)
			pos[START] = str + i + 1;
		else
			pos[END] = str + i;
		if (pos[START] == NULL || pos[END] == NULL)
			continue ;
		if (set_arg(&args[arg_nb++], pos[START], pos[END] - pos[START]) < 0)
			return arg_nb - 1;
		ft_bzero(pos, sizeof(char *) * 2);
	}
	return arg_nb;
}

void			free_args(char ***args, int nb_args)
{
	while (nb_args-- > 0)
		free((*args)[nb_args]);
	free(*args);
}

int				get_args(char *src_str, char ***dest_args)
{
	int		nb_args;
	int		nb_allocated_args;

	nb_args = count_args(src_str);
	if (nb_args < 0)
		return (-1);
	if ((*dest_args = malloc(sizeof(char *) * nb_args + 1)) == NULL)
		return (-1);
	(*dest_args)[nb_args] = NULL;
	if ((nb_allocated_args = fill_args(*dest_args, src_str)) != nb_args)
	{
		free_args(dest_args, nb_allocated_args);
		return (-1);
	}
	return (nb_args);
}
