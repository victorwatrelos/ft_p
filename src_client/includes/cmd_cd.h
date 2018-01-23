#ifndef CMD_CD_H
# define CMD_CD_H

# include "recv_data.h"
# include "send_data.h"
# include "shared_struct.h"
# include "str_utils.h"
# include "client_struct.h"
# include "get_param.h"

# include <libft.h>

# include <stdio.h>
# include <stdint.h>

int		cmd_cd(int sockfd, char *line, uint32_t cmd, t_param *param);

#endif
