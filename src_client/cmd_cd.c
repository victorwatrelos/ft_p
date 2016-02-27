#include "cmd_cd.h"

static int	get_response(int sockfd, t_log *log)
{
	uint32_t		magic;

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
	return (1);
}

int			cmd_cd(int sockfd, char *line, uint32_t cmd, t_log *log)
{
	t_command		command;
	char			*path;

	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!get_param(line, &path))
	{
		add_line(log, INVALID_ARG_CD);
		return (0);
	}
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		add_line(log, SEND_CMD_FAIL);
		return (0);
	}
	if  (!send_string(sockfd, path, ft_strlen(line)))
	{
		add_line(log, SEND_STRING_FAIL);
		return (0);
	}
	if (!(get_response(sockfd, log)))
		return (0);
	return (1);
}
