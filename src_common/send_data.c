#include "send_data.h"

int		send_data(int sockfd, void *buf, ssize_t size)
{
	ssize_t		ret;
	int			flag;

	flag = 1; 
	while (size > 0)
	{
		if ((ret = write(sockfd, buf, size)) < 0)
			return (0);
		size -= ret;
		buf += ret;
	}
	return (1);
}

int		send_string(int sockfd, char *str, uint64_t size)
{
	if (!(send_data(sockfd, &size, sizeof(uint64_t))))
		return (0);
	if (!(send_data(sockfd, str, size)))
		return (0);
	return (1);
}
