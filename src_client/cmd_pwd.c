#include "cmd_pwd.h"

static int	get_response(int sockfd, t_param *param)
{
	uint32_t	magic;
	uint64_t	str_size;
	char		*str;

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
	if (!(str = recv_string(sockfd, &str_size)))
	{
		param->to_deco = 1;
		printf(RECV_STRING_FAIL "\n");
		return (0);
	}
	printf("Server directory: %s\n", str);
	free(str);
	return (1);
}

int			cmd_pwd(int sockfd, char *line, uint32_t cmd, t_param *param)
{
	t_command		command;

	(void)line;
	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		param->to_deco = 1;
		printf(SEND_CMD_FAIL "\n");
		return (0);
	}
	if (!(get_response(sockfd, param)))
		return (0);
	return (1);
}
