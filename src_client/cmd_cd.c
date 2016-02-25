#include "cmd_cd.h"

static int	get_response(int sockfd)
{
	uint32_t		magic;

	if (!(recv_data(sockfd, &magic, sizeof(magic))))
		return (0);
	if (magic != MAGIC_CONF_SUCCESS)
		return (0);
	return (1);
}

int		cmd_cd(int sockfd, char *line, uint32_t cmd)
{
	t_command		command;
	char			*end;
	uint64_t		size;

	command.magic = MAGIC_CMD;
	command.command = cmd;
	line = jump_after_space(line);
	if (*line == '\0')
		return (0);
	end = jump_to_space(line);
	if (*(jump_after_space(end)) != '\0')
		return (0);
	size = end - line;
	*end = '\0';
	if (!send_data(sockfd, &command, sizeof(t_command)))
		return (0);
	if  (!send_string(sockfd, line, size))
		return (0);
	if (!(get_response(sockfd)))
		return (0);
	return (1);
}
