#include "recv_data.h"
#include <stdio.h>

int		recv_cmd(int sockfd, void *buff, ssize_t buff_size)
{
	static char		recv_buff[MAX_CMD_SIZE];
	static ssize_t	recv_buff_index = 0;
	char			tmp_buff[MAX_CMD_SIZE];
	char			*new_line_pos;
	ssize_t			recv_size;

	recv_buff[MAX_CMD_SIZE - 1] = '\0';

	new_line_pos = ft_strchr(recv_buff, (int)'\n');
	if (new_line_pos == NULL)
	{
		if (recv_buff_index >= MAX_CMD_SIZE - 1)
			return (-1);
		printf("READ\n");
		fflush(0);
		recv_size = read(sockfd, recv_buff + recv_buff_index, (MAX_CMD_SIZE - 1) - recv_buff_index);
		printf("Read: %s\n", recv_buff);
		printf("END READ\n");
		fflush(0);
		if (recv_size <= 0)
			return (-1);
		recv_buff_index += recv_size;
		*(recv_buff + recv_buff_index) = '\0';
		return recv_cmd(sockfd, buff, buff_size);
	}
	if (buff_size < new_line_pos - recv_buff - 1)
		return (-1);
	recv_size = new_line_pos - recv_buff;
	ft_strncpy(buff, recv_buff, recv_size);
	((char *)buff)[recv_size] = '\0';
	ft_strncpy(tmp_buff, recv_buff + (new_line_pos + 1 - recv_buff), MAX_CMD_SIZE - 1);
	ft_strncpy(recv_buff, tmp_buff, MAX_CMD_SIZE - 1);
	recv_buff_index -= (new_line_pos + 1 - recv_buff);
	return 0;
}

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

static uint64_t        ft_min(uint64_t p1, uint64_t p2)
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
