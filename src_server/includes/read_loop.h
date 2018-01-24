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
# include "get_args.h"

int					read_loop(int sockfd, struct in_addr *client_addr);

static const t_cmd	LIST_CMD[NB_CMD] = {{cmd_ls_serv, CMD_LS},
										{NULL, ""},//CD
										{NULL, ""},//PWD
										{cmd_quit_serv, CMD_QUIT},
										{NULL, ""},//GET
										{NULL, ""}};//PUT

#endif
