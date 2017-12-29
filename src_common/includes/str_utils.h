#ifndef STR_UTILS_H
# define STR_UTILS_H

# include <libft.h>
# include <sys/stat.h>

char			*create_str_from_args(char **list_arg, size_t size_arg);
char			*jump_after_space(char *line);
char			*jump_to_space(char *line);
char			*add_dot_begining(char *path);
int				rec_mkdir(char *path, char *start);

#endif
