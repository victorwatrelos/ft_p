#include "connect_to_server.h"

static int			init_client(int sockfd, int port, const char *host)
{
	struct sockaddr_in  to;

	ft_bzero(&to, sizeof(to));
	to.sin_family = AF_INET;
	to.sin_port = htons(port);
	to.sin_addr.s_addr = inet_addr(host);
	if (connect(sockfd, (struct sockaddr *)&to, sizeof(struct sockaddr_in)) < 0)
		return (0);
	return (1);
}

static int			log_in(int sockfd)
{
	t_connect		connect;

	connect.magic = MAGIC_CONNECT_CLIENT;
	if (!send_data(sockfd, &connect, sizeof(connect)))
	{
		printf("Send fail\n");
		return (0);
	}
	return (1);
}

int 				connect_to_server(t_param *param)
{
	int			sockfd;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Socket creation fail\n");
		return (0);
	}
	if (!init_client(sockfd, param->port, param->host))
	{
		printf("Socket initialization fail\n");
		return (0);
	}
	if (!log_in(sockfd))
		return (0);
	loop_cmd(sockfd);
	return (1);
}
