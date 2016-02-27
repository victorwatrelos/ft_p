#include "cmd_put_serv.h"

static char	*remove_filename(char *path)
{
	char	*end;
	char	*res;

	if (!(res = ft_strdup(path)))
		return (NULL);
	if (!(end = ft_strrchr(res, '/')))
	{
		free(res);
		return (NULL);
	}
	*end = '\0';
	return (res);
}

static int	test_pathname(char *path, t_serv_fs *serv_fs)
{
	char			*pathname;
	char			*tmp;

	if (!(pathname = remove_filename(path)))
		return (0);
	tmp = ft_strdup(pathname);
	if (!(rec_mkdir(tmp, tmp)))
	{
		free(tmp);
		free(pathname);
		return (0);
	}
	free(tmp);
	if (!test_rel_path(pathname, serv_fs->base_dir))
	{
		free(pathname);
		return (0);
	}
	free(pathname);
	return (1);
}

static char	*get_and_test_path(int sockfd, t_serv_fs *serv_fs)
{
	char	*tmp;
	char	*path;

	if (!(path = recv_string(sockfd, NULL)))
		return (NULL);
	tmp = path;
	if (!(path = add_dot_begining(path)))
	{
		recv_file(sockfd, "/dev/null");
		free(tmp);
		return (NULL);
	}
	free(tmp);
	if (!(test_pathname(path, serv_fs)))
	{
		recv_file(sockfd, "/dev/null");
		free(path);
		return (NULL);
	}
	return (path);
}

int			cmd_put_serv(int sockfd, t_serv_fs *serv_fs)
{
	char			*path;
	uint32_t		conf;

	conf = MAGIC_CONF_FAIL;
	if (!(path = get_and_test_path(sockfd, serv_fs)))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	if (!(recv_file(sockfd, path)))
	{
		free(path);
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	free(path);
	conf = MAGIC_CONF_SUCCESS;
	if (!(send_data(sockfd, &conf, sizeof(conf))))
		return (0);
	return (1);
}
