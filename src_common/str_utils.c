#include "str_utils.h"

char			*jump_after_space(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

char			*jump_to_space(char *line)
{
	while (*line != ' ' && *line != '\t' && *line != '\0')
		line++;
	return (line);
}

int				rec_mkdir(char *path, char *start)
{
	struct stat	st;

	while (*path != '\0' && *path != '/')
		path++;
	if (*path == '/')
		*path = '\0';
	else
	{
		mkdir(start, 0700);
		return (1);
	}
	if (!lstat(start, &st))
	{
		if (S_ISDIR(st.st_mode))
		{
			*path = '/';
			return (rec_mkdir(path + 1, start));
		}
		return (0);
	}
	if (mkdir(start, 0700) < 0)
		return (0);
	*path = '/';
	return (rec_mkdir(path + 1, start));
}

char			*add_dot_begining(char *path)
{
	char		*res;

	if (!ft_strncmp(path, "./", 2))
		return (path);
	if (!(res = ft_strnew(ft_strlen(path) + 2)))
		return (NULL);
	if (*path == '/')
		ft_strcpy(res, ".");
	else
		ft_strcpy(res, "./");
	ft_strcat(res, path);
	return (res);
}
