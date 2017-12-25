#include "cmd_quit_serv.h"

int			cmd_quit_serv(int sockfd, t_serv_fs *serv_fs)
{
	(void)serv_fs;
	if (!send_data(sockfd, CMD_QUIT_CONFIRMED "\n", ft_strlen(CMD_QUIT_CONFIRMED "\n")))
		return (-2);
	return (-1);
}
