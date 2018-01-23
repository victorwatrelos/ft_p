#ifndef CMD_PWD_H
# define CMD_PWD_H

# include "shared_struct.h"
# include "str_utils.h"
# include "send_data.h"
# include "recv_data.h"
# include "client_struct.h"

# include <libft.h>

# include <stdio.h>
# include <stdint.h>

int			cmd_pwd(int sockfd, char *line, uint32_t cmd, t_param *param);

#endif
