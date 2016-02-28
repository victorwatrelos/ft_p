#ifndef LAUNCH_SERVER_H
# define LAUNCH_SERVER_H

# include <netinet/in.h>

# include <libft.h>

# include "read_loop.h"
# include "server_struct.h"
# include "auth_client.h"
# include "catch_signal.h"

int			launch_server(t_param *param);

#endif
