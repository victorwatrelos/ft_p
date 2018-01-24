#include "cmd_ls.h"

static int  extract_port(char *str)
{
	int		port;

	if (ft_strncmp(str, "SEND_DATA:", 10) != 0)
		return (-1);
	port = ft_atoi(str + 10);
	if (port <= 0 || port > 65535)
		return (-1);
	return (port);
}

static int	get_response(int sockfd, t_param *param)
{
	char		buff[4096];
	int			port;
	char		*resp;
	int			size_resp;

	(void)param;
	buff[4095] = '\0';
	if (recv_cmd(sockfd, buff, 4095) < 0)
		return (-1);
	if ((port = extract_port(buff)) < 0)
		return (-1);
	resp = get_data_from_socket(port, &size_resp);
	return (1);
}

int			cmd_ls(int sockfd, char *line, uint32_t cmd, t_param *param)
{
	char			*cmd_to_serv;
	char			*cmd_args[2];

	printf("LS line: %s\n", line);
	(void)cmd;
	if (!get_param(line, cmd_args + 1))
		cmd_args[1] = ".";
	cmd_args[0] = CMD_LS;
	if ((cmd_to_serv = create_str_from_args(cmd_args, 2)) == NULL)
	{
		ft_putstr("Malloc fail\n");
		exit(1);
	}
	printf("Cmd: |%s|\n", cmd_to_serv);
	if (!send_data(sockfd, cmd_to_serv, ft_strlen(cmd_to_serv)))
	{
		param->to_deco = 1;
		printf(SEND_CMD_FAIL "\n");
		free(cmd_to_serv);
		return (0);
	}
	if (get_response(sockfd, param) < 0)
		return (0);
	return (1);
}
