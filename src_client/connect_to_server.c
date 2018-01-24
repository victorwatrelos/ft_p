#include "connect_to_server.h"
#include "netdb.h"

static int			init_client(int sockfd, int port, const char *host)
{
	struct sockaddr_in  to;
	struct hostent		*server;

	server = gethostbyname(host);		
	ft_bzero(&to, sizeof(to));
	to.sin_family = AF_INET;
	to.sin_port = htons(port);
	ft_memmove(server->h_addr, &to.sin_addr.s_addr, server->h_length);
	if (connect(sockfd, (struct sockaddr *)&to, sizeof(struct sockaddr_in)) < 0)
		return (0);
	return (1);
}

static int			log_in(int sockfd)
{
	char	command[4096];

	command[4095] = '\0';
	if (!send_data(sockfd, CMD_CONNECT "\n", ft_strlen(CMD_CONNECT "\n")))
		return (0);
	if (recv_cmd(sockfd, &command, 4095) < 0)
		return (0);
	printf("Recv: %s\n", command);
	if (ft_strncmp(command, CMD_CONNECT_RESPONSE, 4095) != 0)
		return (0);
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
	{
		printf("Unable to log in\n");
		return (0);
	}
	loop_cmd(sockfd, param);
	printf("Good bye\n");
	return (1);
}
