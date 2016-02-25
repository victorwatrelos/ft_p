#ifndef CMD_CD_SERV
# define CMD_CD_SERV

# include "server_struct.h"
# include "test_path.h"
# include "shared_struct.h"
# include "recv_data.h"
# include "send_data.h"

int			cmd_cd_serv(int sockfd, t_serv_fs *serv_fs);

#endif
