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

static int			process_line(char *line, int sockfd, t_param *param)
{
	char			*end;
	char			*tmp;
	size_t			size;
	int				(*fn)(int, char *, uint32_t, t_param *);
	const t_cmd		*cmd;

	line = jump_after_space(line);
	end = jump_to_space(line);
	size = end - line;
	tmp = ft_strnew(size);
	ft_memcpy(tmp, line, size);
	if (!(cmd = get_cmd(tmp)))
	{
		free(tmp);
		printf("Invalid cmd\n");
		return (0);
	}
	free(tmp);
	fn = cmd->fn;
	return fn(sockfd, end, cmd->cmd, param);
}

static int			manage_line_log(int sockfd, char *line, t_param *param)
{
	process_line(line, sockfd, param);
	if (param->to_deco)
		return (1);
	return (0);
}

int					loop_cmd(int sockfd, t_param *param)
{
	char		line[MAX_LINE_SIZE + 1];
	int			ret;

	while (1)
	{
		ft_putstr("=>");
		if ((ret = read(0, line, MAX_LINE_SIZE)) <= 0)
		{
			return (0);
		}
		if (ret == 1)
			continue ;
		if (ret == MAX_LINE_SIZE)
		{
			printf("Command line too long (max: %d)\n", MAX_LINE_SIZE - 1);
			continue ;
		}
		line[ret - 1] = '\0';
		if (manage_line_log(sockfd, line, param))
			return (1);
	}
}
