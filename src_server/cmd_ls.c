#include "cmd_ls_serv.h"

static char		*str_realloc_cat(char *s1, char *s2, uint64_t *size)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	final_size;
	char	*res;

	size_s1 = *size;
	size_s2 = ft_strlen(s2);
	final_size = size_s1 + size_s2 + 2;
	if (!(res = ft_strnew(final_size)))
		return (NULL);
	if (*s1 == '\0')
		ft_strcpy(res, s2);
	else
	{
		ft_strcpy(res + size_s1 + 1, s2);
		res[size_s1] = '\0';
	}
	ft_memcpy(res, s1, size_s1);
	*size = final_size;
	free(s1);
	return (res);
}

static char		*get_name(char *name, char *path)
{
	char			*full_pathname;
	char			*final_name;
	size_t			size_path;
	struct stat		st;

	size_path = ft_strlen(path);
	if (!(full_pathname = malloc(sizeof(char) * (ft_strlen(name) + size_path + 2))))
		return (NULL);
	ft_strcpy(full_pathname, path);
	if (path[size_path - 1] != '/')
		ft_strcat(full_pathname, "/");
	ft_strcat(full_pathname, name);
	if (lstat(full_pathname, &st) < 0)
	{
		free(full_pathname);
		return (NULL);
	}
	free(full_pathname);
	if (!(final_name = ft_strnew(ft_strlen(name) + 16)))
		return (NULL);
	if (S_ISDIR(st.st_mode))
		ft_strcpy(final_name, "\e[34m");
	ft_strcat(final_name, name);
	ft_strcat(final_name, "\e[0m");
	return (final_name);
}

static char		*get_str_ls(char *path, uint64_t *size)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*str;
	char			*name;

	*size = 0;
	if (!(str = ft_strnew(1)))
		return (NULL);
	if (!(dir = opendir(path)))
	{
		free(str);
		return (NULL);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (!(name = get_name(entry->d_name, path)))
		{
			closedir(dir);
			free(str);
			return (NULL);
		}
		if (!(str = str_realloc_cat(str, name, size)))
		{
			free(name);
			free(str);
			closedir(dir);
			return (NULL);
		}
		free(name);
	}
	closedir(dir);
	return (str);
}

static char		*get_resp(t_string *resp, char *path, t_serv_fs *serv_fs)
{
	char		*str;

	if (!test_rel_path(path, serv_fs->base_dir))
		return (NULL);
	if (!(str = get_str_ls(path, &(resp->size))))
		return (NULL);
	return (str);
}

int			cmd_ls_serv(int fd, t_serv_fs *serv_fs, char **args, int nb_args)
{
	char			*path;
	t_string		resp;
	char			*str;
	uint32_t		conf;

	conf = MAGIC_CONF_FAIL;
	if (!(path = recv_string(fd, NULL)))
	{
		send_data(fd, &conf, sizeof(conf));
		return (0);
	}
	if (!(str = get_resp(&resp, path, serv_fs)))
	{
		free(path);
		send_data(fd, &conf, sizeof(conf));
		return (0);
	}
	free(path);
	conf = MAGIC_CONF_SUCCESS;
	if (!(send_data(fd, &conf, sizeof(conf))))
	{
		free(str);
		return (0);
	}
	if (!(send_string(fd, str, resp.size)))
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
