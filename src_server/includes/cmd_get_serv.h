#ifndef CMD_GET_SERV_H
# define CMD_GET_SERV_H

# include <libft.h>
# include <dirent.h>

# include "recv_data.h"
# include "send_data.h"
# include "server_struct.h"
# include "shared_struct.h"
# include "test_path.h"
# include "str_utils.h"
# include <stddef.h>
# include <stdint.h>
# include <sys/stat.h>
# include <fcntl.h>

int			cmd_get_serv(int sockfd, t_serv_fs *serv_fs);

#endif
