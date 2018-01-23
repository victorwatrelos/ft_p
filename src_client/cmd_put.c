#include "cmd_put.h"

static int	send_file_data(int sockfd, char *src, char *dst, t_param *param)
{
	int				filefd;
	t_command		command;

	command.magic = MAGIC_CMD;
	command.command = 6;
	if ((filefd = open(src, O_RDONLY)) < 0)
	{
		printf(FILE_OPENING_FAIL "\n");
		return (0);
	}
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		param->to_deco = 1;
		printf(SEND_CMD_FAIL "\n");
		return (0);
	}
	if  (!send_string(sockfd, dst, ft_strlen(dst)))
	{
		param->to_deco = 1;
		printf(SEND_STRING_FAIL "\n");
		return (0);
	}
	if (!send_file(sockfd, filefd))
	{
		param->to_deco = 1;
		printf(SEND_FILE_FAIL "\n");
		return (0);
	}
	return (1);
}

static int	get_response(int sockfd, t_param *param)
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
	return (1);
}

int			cmd_put(int sockfd, char *line, uint32_t cmd, t_param *param)
{
	char			*src;
	char			*dst;

	(void)cmd;
	if (!get_2_params(line, &src, &dst))
	{
		printf(INVALID_ARG_PUT "\n");
		return (0);
	}
	if (!send_file_data(sockfd, src, dst, param))
		return (0);
	if (!get_response(sockfd, param))
		return (0);
	return (1);
}
