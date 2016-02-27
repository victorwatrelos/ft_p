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

	if (!(pathname = remove_filename(path)))
		return (0);
	if (!test_rel_path(pathname, serv_fs->base_dir))
	{
		free(pathname);
		return (0);
	}
	free(pathname);
	return (1);
}

int			cmd_put_serv(int sockfd, t_serv_fs *serv_fs)
{
	char			*path;
	uint32_t		conf;

	conf = MAGIC_CONF_FAIL;
	if (!(path = recv_string(sockfd, NULL)))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	if (!(test_pathname(path, serv_fs)))
	{
		recv_file(sockfd, "/dev/null");
		free(path);
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
