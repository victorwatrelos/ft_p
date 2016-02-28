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
	t_command		command;
	char			*path;

	command.magic = MAGIC_CMD;
	command.command = cmd;
	if (!get_param(line, &path))
		path = ".";
	if (!send_data(sockfd, &command, sizeof(t_command)))
	{
		add_line(log, SEND_CMD_FAIL, 1);
		return (0);
	}
	if  (!send_string(sockfd, path, ft_strlen(path)))
	{
		add_line(log, SEND_STRING_FAIL, 1);
		return (0);
	}
	if (!(get_response(sockfd, log)))
		return (0);
	return (1);
}
