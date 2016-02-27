#include "cmd_pwd.h"

static int	get_response(int sockfd, t_log *log)
{
	uint32_t	magic;
	uint64_t	str_size;
	char		*str;

	if (!(recv_data(sockfd, &magic, sizeof(magic))))
	{
		add_line(log, RECV_MAGIC_CONF_FAIL);
		return (0);
	}
	if (magic != MAGIC_CONF_SUCCESS)
	{
		add_line(log, MAGIC_CONF_INVALID);
		return (0);
	}
	if (!(str = recv_string(sockfd, &str_size)))
	{
		add_line(log, RECV_STRING_FAIL);
		return (0);
	}
	printf("Server directory: %s\n", str);
	free(str);
	return (1);
}

int			cmd_pwd(int sockfd, char *line, uint32_t cmd, t_log *log)
{
	t_command		command;

	(void)line;
	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		add_line(log, SEND_CMD_FAIL);
		return (0);
	}
	if (!(get_response(sockfd, log)))
		return (0);
	return (1);
}
