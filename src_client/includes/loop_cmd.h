#ifndef LOOP_CMD_H
# define LOOP_CMD_H

# include <stdio.h>
# include <libft.h>

# define MAX_LINE_SIZE 4095
# include "str_utils.h"
# include "cmd_ls.h"
# include "cmd_cd.h"
# include "cmd_pwd.h"
# include "cmd_quit.h"
# include "cmd_get.h"
# include "cmd_put.h"
# include "client_struct.h"

# define NB_CMD 6

int		loop_cmd(int sockfd, t_param *param);

static const t_cmd	LIST_CMD[NB_CMD] = {{1, "ls", &cmd_ls},
										{2, "cd", &cmd_cd},
										{3, "pwd", &cmd_pwd},
										{4, "quit", &cmd_quit},
										{5, "get", &cmd_get},
										{6, "put", &cmd_put}};

#endif
