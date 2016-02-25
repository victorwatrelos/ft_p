#include "test_path.h"

int		test_path_valid(char *path, char *base_dir)
{
	if (ft_strncmp(path, base_dir, ft_strlen(base_dir)))
		return (0);
	return (1);
}

int		test_rel_path(char *path, char *base_dir)
{
	char		buff[MAX_PATH_SIZE + 1];
	char		cur_dir[MAX_PATH_SIZE + 1];

	if (!getcwd(cur_dir, MAX_PATH_SIZE))
		return (0);
	if (chdir(path) < 0)
		return (0);
	if (!getcwd(buff, MAX_PATH_SIZE))
	{
		chdir(cur_dir);
		return (0);
	}
	if (chdir(cur_dir) < 0)
		return (0);
	return (test_path_valid(buff, base_dir));
}
