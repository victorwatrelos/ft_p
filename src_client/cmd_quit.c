#include "cmd_quit.h"

int		cmd_quit(int sockfd, char *line, uint32_t cmd)
{
	t_command		command;
	uint32_t		magic;

	(void)line;
	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!send_data(sockfd, &command, sizeof(t_command)))
		return (-2);
	if (!(recv_data(sockfd, &magic, sizeof(magic))))
		return (-2);
	if (magic != MAGIC_CONF_SUCCESS)
		return (-2);
	return (-1);
}
