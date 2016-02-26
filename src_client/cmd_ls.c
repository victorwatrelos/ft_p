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
	display_str(str, str_size);
	free(str);
	return (1);
}

int			cmd_ls(int sockfd, char *line, uint32_t cmd)
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
