#ifndef READ_LOOP_H
# define READ_LOOP_H

# define NB_TRY_MAGIC 128
# define NB_CMD 6

# include "server_struct.h"
# include "cmd_ls_serv.h"
# include "cmd_cd_serv.h"
# include "cmd_pwd_serv.h"
# include "cmd_quit_serv.h"
# include "cmd_get_serv.h"
# include "cmd_put_serv.h"

int					read_loop(int sockfd);

static const t_cmd	LIST_CMD[NB_CMD] = {{cmd_ls_serv, 1},
										{cmd_cd_serv, 2},
										{cmd_pwd_serv, 3},
										{cmd_quit_serv, 4},
										{cmd_get_serv, 5},
										{cmd_put_serv, 6}};

#endif
