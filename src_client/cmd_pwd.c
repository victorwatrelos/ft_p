#include "cmd_pwd.h"

static int	get_response(int sockfd)
{
	uint32_t	magic;
	uint64_t	str_size;
	char		*str;

	if (!(recv_data(sockfd, &magic, sizeof(magic))))
		return (0);
	if (magic != MAGIC_CONF_SUCCESS)
		return (0);
	if (!(str = recv_string(sockfd, &str_size)))
		return (0);
	printf("Server directory: %s\n", str);
	free(str);
	return (1);
}

int			cmd_pwd(int sockfd, char *line, uint32_t cmd)
{
	t_command		command;

	(void)line;
	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!send_data(sockfd, &command, sizeof(t_command)))
		return (0);
	if (!(get_response(sockfd)))
		return (0);
	return (1);
}
