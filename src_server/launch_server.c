#include "launch_server.h"

static int			init_server(int sockfd, int port)
{
	struct sockaddr_in  this;

	printf("port: %d\n", port);
	ft_bzero(&this, sizeof(this));
	this.sin_family = AF_INET;
	this.sin_port = htons(port);
	this.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr *)&this, sizeof(this)) < 0)
	{
		printf("Server could not init the connection\n");
		return (-1);
	}
	if (listen(sockfd, 10) < 0)
	{
		printf("Server could not listen\n");
		return (-1);
	}
	return (0);
}

static int			child(int sockfd)
{
	if (!auth_client(sockfd))
	{
		printf("Auth fail\n");
		return (1);
	}
	printf("Auth succeed\n");
	if (!read_loop(sockfd))
		printf("Client disconected\n");
	else
		printf("end loop end\n");
	close(sockfd);
	return (0);
}

static int			listen_loop(socklen_t lg, int sockfd)
{
	int                 newsockfd;
	struct sockaddr_in  that;
	pid_t               pid;
	int					ret;

	while (1)
	{
		newsockfd = accept(sockfd, (struct sockaddr *)(&that), &lg);
		if (newsockfd < 0)
			printf("Fail to accept a new connection\n");
		else
		{
			if ((pid = fork()) < 0)
				printf("fork error\n");
			if (pid == 0)
				child(newsockfd);
			else
			{
				close(newsockfd);
			}
		}
	}
}

int				launch_server(t_param *param)
{
	int                 sockfd;
	socklen_t           lg;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		printf("Server could not init socket\n");
		return (0);
	}
	if (init_server(sockfd, param->port) < 0)
		return (0);
	lg = (socklen_t)sizeof(struct sockaddr_in);
	listen_loop(lg, sockfd);
	return (1);
}
