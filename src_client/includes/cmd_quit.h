#ifndef CMD_QUIT_H
# define CMD_QUIT_H

# include "send_data.h"
# include "recv_data.h"
# include "shared_struct.h"
# include "client_struct.h"

# include <stdint.h>

int		cmd_quit(int sockfd, char *line, uint32_t cmd, t_param *param);

#endif
