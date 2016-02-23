#include "send_data.h"

int		send_data(int sockfd, void *buf, ssize_t size)
{
	ssize_t		ret;

	while (size > 0)
	{
		if ((ret = send(sockfd, buf, size, 0)) < 0)
			return (0);
		size -= ret;
		buf += ret;
	}
	return (1);
}
