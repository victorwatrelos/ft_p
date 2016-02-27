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

#include <errno.h>
static uint64_t	ft_min(uint64_t p1, uint64_t p2)
{
	if (p1 < p2)
		return (p1);
	return (p2);
}

int				recv_file(int sockfd, char *pathname)
{
	int			filefd;
	uint64_t	size;
	char		buff[SIZE_BUF];
	int			ret;

	if ((filefd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, 0700)) < 0)
		return (0);
	if (!(recv_data(sockfd, &size, sizeof(size))))
	{
		close(filefd);
		return (0);
	}
	while (size > 0 && (ret = read(sockfd, buff, ft_min(size, SIZE_BUF))) > 0)
	{
		size -= ret;
		if ((write(filefd, buff, ret)) < 0)
		{
			close(filefd);
			return (0);
		}
	}
	close(filefd);
	return (1);
}
