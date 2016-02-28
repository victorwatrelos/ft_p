#include "cmd_put.h"

static int	send_file_data(int sockfd, char *src, char *dst, t_log *log)
{
	int				filefd;
	t_command		command;

	command.magic = MAGIC_CMD;
	command.command = 6;
	if ((filefd = open(src, O_RDONLY)) < 0)
	{
		add_line(log, FILE_OPENING_FAIL, 0);
		return (0);
	}
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		add_line(log, SEND_CMD_FAIL, 1);
		return (0);
	}
	if  (!send_string(sockfd, dst, ft_strlen(dst)))
	{
		add_line(log, SEND_STRING_FAIL, 1);
		return (0);
	}
	if (!send_file(sockfd, filefd))
	{
		add_line(log, SEND_FILE_FAIL, 1);
		return (0);
	}
	return (1);
}

static int	get_response(int sockfd, t_log *log)
{
	uint32_t	magic;

	if (!(recv_data(sockfd, &magic, sizeof(magic))))
	{
		add_line(log, RECV_MAGIC_CONF_FAIL, 1);
		return (0);
	}
	if (magic != MAGIC_CONF_SUCCESS)
	{
		add_line(log, MAGIC_CONF_INVALID, 0);
		return (0);
	}
	return (1);
}

int			cmd_put(int sockfd, char *line, uint32_t cmd, t_log *log)
{
	char			*src;
	char			*dst;

	(void)cmd;
	if (!get_2_params(line, &src, &dst))
	{
		add_line(log, INVALID_ARG_PUT, 0);
		return (0);
	}
	if (!send_file_data(sockfd, src, dst, log))
		return (0);
	if (!get_response(sockfd, log))
		return (0);
	return (1);
}
