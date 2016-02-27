#include "cmd_get.h"

static int	get_response(int sockfd, char *dst)
{
	uint32_t	magic;

	if (!(recv_data(sockfd, &magic, sizeof(magic))))
		return (0);
	if (magic != MAGIC_CONF_SUCCESS)
		return (0);
	if (!(recv_file(sockfd, dst)))
		return (0);
	return (1);
}

int			cmd_get(int sockfd, char *line, uint32_t cmd)
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
	if  (!send_string(sockfd, src, ft_strlen(src)))
		return (0);
	if (!(get_response(sockfd, dst)))
		return (0);
	return (1);
}
