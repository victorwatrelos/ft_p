#include "cmd_quit.h"

int		cmd_quit(int sockfd, char *line, uint32_t cmd, t_log *log)
{
	char	command[4096];

	printf("cmd quit\n");
	command[4095] = '\0';
	(void)line;
	(void)cmd;
	log->to_deco = 1;
	if (!send_data(sockfd, CMD_QUIT "\n", ft_strlen(CMD_QUIT "\n")))
	{
		add_line(log, SEND_CMD_FAIL, 1);
		return (0);
	}
	if (recv_cmd(sockfd, command, 4095) < 0)
	{
		add_line(log, RECV_CMD_FAIL, 1);
		return (0);
	}
	printf("Cmd quit confirmed: |%s|\n", command);
	if (ft_strncmp(command, CMD_QUIT_CONFIRMED, 4096) != 0)
	{
		add_line(log, RECV_CONF_FAIL, 1);
		return (0);
	}
	return (1);
}
