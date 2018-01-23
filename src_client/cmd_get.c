#include "cmd_get.h"

static int	get_response(int sockfd, char *dst, t_param *param)
{
	uint32_t	magic;

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
	if (!(recv_file(sockfd, dst)))
	{
		printf(RECV_FILE_FAIL "\n");
		return (0);
	}
	return (1);
}

int			cmd_get(int sockfd, char *line, uint32_t cmd, t_param *param)
{
	t_command		command;
	char			*src;
	char			*dst;

	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!get_2_params(line, &src, &dst))
	{
		printf(INVALID_ARG_GET "\n");
		return (0);
	}
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		param->to_deco = 1;
		printf(SEND_CMD_FAIL "\n");
		return (0);
	}
	if  (!send_string(sockfd, src, ft_strlen(src)))
	{
		printf(SEND_STRING_FAIL "\n");
		return (0);
	}
	if (!(get_response(sockfd, dst, param)))
		return (0);
	return (1);
}
