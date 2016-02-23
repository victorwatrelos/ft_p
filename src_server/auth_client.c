#include "auth_client.h"

int 	auth_client(int sockfd)
{
	t_connect			connect_in;
	t_connect_response	resp;

	if (!recv_data(sockfd, &connect_in, sizeof(connect_in)))
		return (0);
	if (connect_in.magic != MAGIC_CONNECT_CLIENT)
		return (0);
	resp.magic = MAGIC_CONNECT_RESPONSE_SERVER;
	if (!send_data(sockfd, &resp, sizeof(resp)))
		return (0);
	return (1);
}
