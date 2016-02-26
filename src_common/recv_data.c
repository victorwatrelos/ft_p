#include "recv_data.h"
#include <stdio.h>

int		recv_data(int sockfd, void *buf, ssize_t size)
{
	ssize_t		ret;

	while (size)
	{
		if ((ret = read(sockfd, buf, size)) < 0)
			return (0);
		size -= ret;
		buf += ret;
	}
	return (1);
}

char	*recv_string(int sockfd, uint64_t *size)
{
	char			*str;
	uint64_t		str_size;

	if (!(recv_data(sockfd, &str_size, sizeof(str_size))))
		return (0);
	if (!(str = malloc(sizeof(char) * (str_size + 1))))
		return (0);
	if (!(recv_data(sockfd, str, str_size)))
	{
		free(str);
		return (0);
	}
	str[str_size] = '\0';
	if (size)
		*size = str_size;
	return (str);
}
