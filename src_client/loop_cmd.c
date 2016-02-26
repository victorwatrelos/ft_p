#include "loop_cmd.h"

static const t_cmd		*get_cmd(char *cmd)
{
	int								i;

	i = 0;
	while (i < NB_CMD)
	{
		if (!ft_strcmp(cmd, LIST_CMD[i].str))
		{
			return (LIST_CMD + i);
		}
		i++;
	}
	return (NULL);
}

static int			process_line(char *line, int sockfd)
{
	char			*end;
	char			*tmp;
	size_t			size;
	int				(*fn)(int, char *, uint32_t);
	const t_cmd		*cmd;

	line = jump_after_space(line);
	end = jump_to_space(line);
	size = end - line;
	tmp = ft_strnew(size);
	ft_memcpy(tmp, line, size);
	if (!(cmd = get_cmd(tmp)))
		return (0);
	fn = cmd->fn;
	return fn(sockfd, end, cmd->cmd);
}

int					loop_cmd(int sockfd)
{
	char		line[MAX_LINE_SIZE + 1];
	int			ret;

	while (1)
	{
		if ((ret = read(0, line, MAX_LINE_SIZE)) <= 0)
			return (0);
		if (ret == 1)
			continue ;
		if (ret == MAX_LINE_SIZE)
		{
			printf("Command line too long (max: %d)\n", MAX_LINE_SIZE);
			continue ;
		}
		line[ret - 1] = '\0';
		if ((ret = process_line(line, sockfd)))
		{
			if (ret != -2)
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
		else if (!ret)
			printf("FAIL\n");
		if (ret < 0)
			return (0);
	}
}
