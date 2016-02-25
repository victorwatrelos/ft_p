#ifndef LOOP_CMD_H
# define LOOP_CMD_H

# include <stdio.h>
# include <libft.h>

# define MAX_LINE_SIZE 4095
# include "str_utils.h"
# include "cmd_ls.h"
# include "cmd_cd.h"
# include "client_struct.h"

# define NB_CMD 2

int		loop_cmd(int sockfd);

static const t_cmd	LIST_CMD[NB_CMD] = {{1, "ls", &cmd_ls},
										{2, "cd", &cmd_cd}};

#endif
