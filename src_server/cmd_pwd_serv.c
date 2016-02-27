#include "cmd_pwd_serv.h"

static char	*remove_base_dir(char *path, char *basedir)
{
	size_t	size_base;
	size_t	size_path;

	size_base = ft_strlen(basedir);
	size_path = ft_strlen(path);
	if (ft_strlen(path) < size_base)
		return (path);
	path[size_path] = '/';
	path[size_path + 1] = '\0';
	return (path + size_base);
}

int			cmd_pwd_serv(int sockfd, t_serv_fs *serv_fs)
{
	char			buff[MAX_PATH_SIZE + 4];
	char			*path;
	uint32_t		conf;

	(void)serv_fs;
	conf = MAGIC_CONF_FAIL;
	if (!getcwd(buff, MAX_PATH_SIZE))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	buff[MAX_PATH_SIZE] = '\0';
	path = remove_base_dir(buff, serv_fs->base_dir);
	conf = MAGIC_CONF_SUCCESS;
	if (!send_data(sockfd, &conf, sizeof(conf)))
		return (0);
	if (!send_string(sockfd, path, ft_strlen(path)))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	return (1);
}
