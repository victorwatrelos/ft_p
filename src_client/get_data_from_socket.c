#include "get_data_from_socket.h"

static int			init_server(int sockfd, int port)
{
	struct sockaddr_in  this;

	ft_bzero(&this, sizeof(this));
	this.sin_family = AF_INET;
	this.sin_port = htons(port);
	this.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr *)&this, sizeof(this)) < 0)
	{
		printf("Data server could not init the connection\n");
		return (-1);
	}
	if (listen(sockfd, 1) < 0)
	{
		printf("Data server could not listen\n");
		return (-1);
	}
	return (0);
}

static char			*read_all_data_from_socket(int fd, int *size)
{
	char	*res;
	size_t	idx;
	int		ret;
	size_t	res_size;

	if ((res = malloc(BUFF_SIZE_SOCKET * sizeof(char))) == NULL)
		return (NULL);
	idx = 0;
	res_size = BUFF_SIZE_SOCKET;
	while ((ret = recv(fd, res + idx, res_size - idx, 0)) > 0)
	{
		idx += ret;
		if (idx == res_size)
		{
			if ((res = reallocf(res, res_size + BUFF_SIZE_SOCKET)) == NULL)
				return (NULL);
			res_size += BUFF_SIZE_SOCKET;
		}
	}
	if (ret < 0)
	{
		free(res);
		return (NULL);
	}
	*size = idx;
	return (res);
}

char	*get_data_from_socket(int port, int *size)
{
	
	int                 sockfd_client;
	socklen_t           lg;
	struct sockaddr_in  that;
	char				*res;
	int					sockfd_server;

	if ((sockfd_server = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (NULL);
	if (init_server(sockfd_server, port) < 0)
		return (NULL);
	sockfd_client = accept(sockfd_server, (struct sockaddr *)(&that), &lg);
	if (sockfd_client < 0)
	{
		printf("Fail to accept data connection\n");
		return (NULL);
	}
	res = read_all_data_from_socket(sockfd_client, size);
	close(sockfd_client);
	close(sockfd_server);
	return (res);
}
