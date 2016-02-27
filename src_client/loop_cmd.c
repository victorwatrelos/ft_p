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

static int			process_line(char *line, int sockfd, t_log *log)
{
	char			*end;
	char			*tmp;
	size_t			size;
	int				(*fn)(int, char *, uint32_t, t_log *);
	const t_cmd		*cmd;

	line = jump_after_space(line);
	end = jump_to_space(line);
	size = end - line;
	tmp = ft_strnew(size);
	ft_memcpy(tmp, line, size);
	if (!(cmd = get_cmd(tmp)))
	{
		add_line(log, INVALID_CMD);
		return (0);
	}
	fn = cmd->fn;
	return fn(sockfd, end, cmd->cmd, log);
}

int					loop_cmd(int sockfd)
{
	char		line[MAX_LINE_SIZE + 1];
	int			ret;
	t_log		*log;

	if (!(log = get_log_struct()))
		return (0);
	while (1)
	{
		ft_putstr("=>");
		if ((ret = read(0, line, MAX_LINE_SIZE)) <= 0)
			return (0);
		if (ret == 1)
			continue ;
		if (ret == MAX_LINE_SIZE)
		{
			printf("Command line too long (max: %d)\n", MAX_LINE_SIZE - 1);
			continue ;
		}
		line[ret - 1] = '\0';
		process_line(line, sockfd, log);
		if (!log->size_lst_event)
			add_line(log, SUCCESS_MSG);
		else
			add_line(log, FAILURE_MSG);
		display_log(log);
		if (log->to_deco)
			return (1);
		free_log(log);
	}
}
