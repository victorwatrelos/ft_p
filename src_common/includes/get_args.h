#ifndef GET_ARGS_H
# define GET_ARGS_H

# include <stdio.h>
# include <stdlib.h>
# include <libft.h>

# define START 0
# define END 1

int				get_args(char *src_str, char ***dest_args);
void			free_args(char ***args, int nb_args);

#endif
