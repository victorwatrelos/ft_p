#ifndef CMD_PUT_SERV
# define CMD_PUT_SERV

# include <libft.h>

# include "recv_data.h"
# include "send_data.h"
# include "server_struct.h"
# include "shared_struct.h"
# include "test_path.h"
# include <stddef.h>
# include <stdint.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "str_utils.h"

int			cmd_put_serv(int sockfd, t_serv_fs *serv_fs);

#endif
