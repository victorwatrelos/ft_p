#include "auth_client.h"

int 	auth_client(int sockfd)
{
	char	command[4096];

	command[4095] = '\0';
	if (recv_cmd(sockfd, command, 4095) < 0)
		return (0);
	if (ft_strncmp(command, CMD_CONNECT, 4095) != 0)
		return (0);
	if (!send_data(sockfd, CMD_CONNECT_RESPONSE "\n", ft_strlen(CMD_CONNECT_RESPONSE "\n")))
		return (0);
	return (1);
}
