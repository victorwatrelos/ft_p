#include "cmd_quit.h"

int		cmd_quit(int sockfd, char *line, uint32_t cmd, t_log *log)
{
	t_command		command;
	uint32_t		magic;

	(void)line;
	log->to_deco = 1;
	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		add_line(log, SEND_CMD_FAIL, 1);
		return (0);
	}
	if (!(recv_data(sockfd, &magic, sizeof(magic))))
	{
		add_line(log, RECV_MAGIC_CONF_FAIL, 1);
		return (0);
	}
	if (magic != MAGIC_CONF_SUCCESS)
	{
		add_line(log, MAGIC_CONF_INVALID, 1);
		return (0);
	}
	return (1);
}
