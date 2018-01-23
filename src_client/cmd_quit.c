#include "cmd_quit.h"

int		cmd_quit(int sockfd, char *line, uint32_t cmd, t_param *param)
{
	char	command[4096];

	printf("cmd quit\n");
	command[4095] = '\0';
	(void)line;
	(void)cmd;
	param->to_deco = 1;
	if (!send_data(sockfd, ADD_QUOTE(CMD_QUIT) "\n", ft_strlen(ADD_QUOTE(CMD_QUIT) "\n")))
	{
		printf(SEND_CMD_FAIL "\n");
		return (0);
	}
	if (recv_cmd(sockfd, command, 4095) < 0)
	{
		printf(RECV_CMD_FAIL "\n");
		return (0);
	}
	printf("Cmd quit confirmed: |%s|\n", command);
	if (ft_strncmp(command, ADD_QUOTE(CMD_QUIT_CONFIRMED), 4096) != 0)
	{
		printf(RECV_CONF_FAIL "\n");
		return (0);
	}
	return (1);
}
