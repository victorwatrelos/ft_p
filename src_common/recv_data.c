#include "recv_data.h"

int recv_data(int sockfd, void *buf, ssize_t size)
{
	ssize_t		ret;

	while (size)
	{
		if ((ret = recv(sockfd, buf, size, 0)) < 0)
			return (0);
		size -= ret;
		buf += ret;
	}
	return (1);
}
