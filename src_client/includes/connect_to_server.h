#ifndef CONNECT_TO_SERVER_H
# define CONNECT_TO_SERVER_H

# include "client_struct.h"
# include "shared_struct.h"
# include "send_data.h"
# include "recv_data.h"
# include "loop_cmd.h"

# include <libft.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

int 	connect_to_server(t_param *param);

#endif
