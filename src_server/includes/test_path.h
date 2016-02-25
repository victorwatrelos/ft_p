#ifndef TEST_PATH_H
# define TEST_PATH_H

# include <libft.h>

int		test_rel_path(char *path, char *base_dir);
int		test_path_valid(char *path, char *base_dir);

# define MAX_PATH_SIZE 4095

#endif
