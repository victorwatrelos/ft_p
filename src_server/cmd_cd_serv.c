#include "cmd_cd_serv.h"

static int	change_dir(char *path, t_serv_fs *serv_fs)
{
	if (!test_rel_path(path, serv_fs->base_dir))
		return (0);
	if (chdir(path) < 0)
		return (0);
	return (1);
}

int			cmd_cd_serv(int sockfd, t_serv_fs *serv_fs)
{
	char			*path;
	uint32_t		conf;

	conf = MAGIC_CONF_FAIL;
	if (!(path = recv_string(sockfd, NULL)))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	if (!change_dir(path, serv_fs))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	conf = MAGIC_CONF_SUCCESS;
	if (!(send_data(sockfd, &conf, sizeof(conf))))
		return (0);
	return (1);
}
