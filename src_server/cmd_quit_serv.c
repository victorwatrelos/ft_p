#include "cmd_quit_serv.h"

int			cmd_quit_serv(int sockfd, t_serv_fs *serv_fs)
{
	uint32_t		conf;

	(void)serv_fs;
	conf = MAGIC_CONF_SUCCESS;
	if (!send_data(sockfd, &conf, sizeof(conf)))
		return (-2);
	return (-1);
}
