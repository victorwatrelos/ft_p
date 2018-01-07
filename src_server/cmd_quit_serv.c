#include "cmd_quit_serv.h"

int			cmd_quit_serv(int sockfd, t_serv_fs *serv_fs, char **args, int nb_args)
{
	(void)serv_fs;
	(void)args;
	(void)nb_args;
	if (!send_data(sockfd, ADD_QUOTE(CMD_QUIT_CONFIRMED) "\n", ft_strlen(CMD_QUIT_CONFIRMED "\n")))
		return (-2);
	return (-1);
}
