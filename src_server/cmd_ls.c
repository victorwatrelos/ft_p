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
	if (!(res = malloc(final_size)))
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

static char		*get_str_ls(char *path, uint64_t *size)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*str;

	*size = 0;
	if (!(str = malloc(sizeof(char))))
		return (NULL);
	if (!(dir = opendir(path)))
	{
		free(str);
		return (NULL);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (!(str = str_realloc_cat(str, entry->d_name, size)))
		{
			closedir(dir);
			return (NULL);
		}
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

int			cmd_ls_serv(int sockfd, t_serv_fs *serv_fs)
{
	char			*path;
	t_string		resp;
	char			*str;
	uint32_t		conf;

	conf = MAGIC_CONF_FAIL;
	if (!(path = recv_string(sockfd)))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	if (!(str = get_resp(&resp, path, serv_fs)))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	conf = MAGIC_CONF_SUCCESS;
	if (!(send_data(sockfd, &conf, sizeof(conf))))
		return (0);
	if (!(send_string(sockfd, str, resp.size)))
		return (0);
	return (1);
}
