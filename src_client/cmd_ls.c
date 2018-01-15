#include "cmd_ls.h"

static void	display_str(char *str, uint64_t str_size)
{
	uint64_t		i;
	size_t			size;

	i = 0;
	while (i < str_size)
	{
		size = ft_strlen(str);
		if (*str != '\0')
		{
			write(1, str, size);
			write(1, "\n", 1);
		}
		size++;
		str += size;
		i += size;
	}
}

static int	get_response(int sockfd, t_log *log)
{
	uint32_t	magic;
	uint64_t	str_size;
	char		*str;

	if (!(recv_data(sockfd, &magic, sizeof(magic))))
	{
		add_line(log, RECV_MAGIC_CONF_FAIL, 1);
		return (0);
	}
	if (magic != MAGIC_CONF_SUCCESS)
	{
		add_line(log, MAGIC_CONF_INVALID, 0);
		return (0);
	}
	if (!(str = recv_string(sockfd, &str_size)))
	{
		add_line(log, RECV_STRING_FAIL, 1);
		return (0);
	}
	display_str(str, str_size);
	free(str);
	return (1);
}

int			cmd_ls(int sockfd, char *line, uint32_t cmd, t_log *log)
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
		add_line(log, SEND_CMD_FAIL, 1);
		free(cmd_to_serv);
		return (0);
	}
	if (!(get_response(sockfd, log)))
		return (0);
	return (1);
}
