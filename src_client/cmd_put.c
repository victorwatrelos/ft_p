#include "cmd_put.h"

static int	send_file_data(int sockfd, char *src, char *dst)
{
	int		filefd;

	if ((filefd = open(src, O_RDONLY)) < 0)
		return (0);
	if  (!send_string(sockfd, dst, ft_strlen(dst)))
		return (0);
	if (!send_file(sockfd, filefd))
		return (0);
	return (1);
}

static int	get_response(int sockfd)
{
	uint32_t	magic;

	if (!(recv_data(sockfd, &magic, sizeof(magic))))
		return (0);
	if (magic != MAGIC_CONF_SUCCESS)
		return (0);
	return (1);
}

int			cmd_put(int sockfd, char *line, uint32_t cmd)
{
	t_command		command;
	char			*src;
	char			*dst;

	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!get_2_params(line, &src, &dst))
		return (0);
	if (!send_data(sockfd, &command, sizeof(t_command)))
		return (0);
	if (!send_file_data(sockfd, src, dst))
		return (0);
	if (!get_response(sockfd))
		return (0);
	return (1);
}
