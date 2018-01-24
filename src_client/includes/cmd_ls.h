#ifndef CMD_LS_H
# define CMD_LS_H

# include "shared_struct.h"
# include "str_utils.h"
# include "send_data.h"
# include "recv_data.h"
# include "client_struct.h"
# include "get_param.h"
# include "get_data_from_socket.h"

# include <libft.h>

# include <stdio.h>
# include <stdint.h>

int			cmd_ls(int sockfd, char *line, uint32_t cmd, t_param *param);

#endif
