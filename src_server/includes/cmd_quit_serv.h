#ifndef CMD_QUIT_SERV_H
# define CMD_QUIT_SERV_H

# include "server_struct.h"
# include "send_data.h"
# include "shared_struct.h"
# include <libft.h>

int			cmd_quit_serv(int sockfd, t_serv_fs *serv_fs, char **args, int nb_args);

#endif
