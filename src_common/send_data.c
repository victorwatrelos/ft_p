#include "send_data.h"

int		send_data(int sockfd, void *buf, ssize_t size)
{
	ssize_t		ret;

	printf("Send: %s|\n", buf);
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

int		send_file(int sockfd, int filefd)
{
	char		buff[BUF_FILE_SIZE];
	int			ret;
	off_t		size_file;
	uint64_t	size;
	uint64_t	tot_size = 0;

	if ((size_file = lseek(filefd, 0, SEEK_END)) < 0)
		return (0);
	if (lseek(filefd, 0, SEEK_SET) < 0)
		return (0);
	size = (uint64_t)size_file;
	if (!(send_data(sockfd, &size, sizeof(size))))
		return (0);
	while ((ret = read(filefd, buff, BUF_FILE_SIZE)) > 0)
	{
		tot_size += ret;
		if (!(send_data(sockfd, buff, ret)))
			return (0);
	}
	if (ret < 0)
		return (0);
	return (1);
}
