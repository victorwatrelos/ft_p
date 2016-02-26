#ifndef CMD_PWD_SERV_H
# define CMD_PWD_SERV_H

# include <libft.h>
# include <dirent.h>

# include "recv_data.h"
# include "send_data.h"
# include "server_struct.h"
# include "shared_struct.h"
# include "test_path.h"
# include <stddef.h>
# include <stdint.h>

int			cmd_pwd_serv(int sockfd, t_serv_fs *serv_fs);

#endif
