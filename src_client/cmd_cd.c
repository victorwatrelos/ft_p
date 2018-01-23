#include "cmd_cd.h"

static int	get_response(int sockfd, t_param *param)
{
	uint32_t		magic;

	if (!(recv_data(sockfd, &magic, sizeof(magic))))
	{
		param->to_deco = 1;
		printf(RECV_MAGIC_CONF_FAIL "\n");
		return (0);
	}
	if (magic != MAGIC_CONF_SUCCESS)
	{
		printf(MAGIC_CONF_INVALID "\n");
		return (0);
	}
	return (1);
}

int			cmd_cd(int sockfd, char *line, uint32_t cmd, t_param *param)
{
	t_command		command;
	char			*path;

	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!get_param(line, &path))
	{
		printf(INVALID_ARG_CD "\n");
		return (0);
	}
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		param->to_deco = 1;
		printf(SEND_CMD_FAIL "\n");
		return (0);
	}
	if  (!send_string(sockfd, path, ft_strlen(line)))
	{
		printf(SEND_STRING_FAIL "\n");
		return (0);
	}
	if (!(get_response(sockfd, param)))
		return (0);
	return (1);
}
