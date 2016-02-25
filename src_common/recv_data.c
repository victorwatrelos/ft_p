#include "recv_data.h"

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

char	*recv_string(int sockfd)
{
	t_string		string;
	char			*str;

	if (!(recv_data(sockfd, &string, sizeof(t_string))))
		return (NULL);
	if (!(str = malloc(string.size + 1)))
		return (NULL);
	if (!(recv_data(sockfd, str, string.size)))
	{
		free(str);
		return (NULL);
	}
	str[string.size] = '\0';
	return (str);
}
