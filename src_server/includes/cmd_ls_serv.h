#ifndef CMD_SERV_LS_H
# define CMD_SERV_LS_H

# include <libft.h>
# include <dirent.h>

# include "recv_data.h"
# include "send_data.h"
# include "server_struct.h"
# include "shared_struct.h"
# include "test_path.h"
# include <stddef.h>
# include <stdint.h>
# include <sys/stat.h>

int			cmd_ls_serv(int fd, t_serv_fs *serv_fs, char **args, int nb_args);

#endif
