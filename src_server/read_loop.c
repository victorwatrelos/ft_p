#include "read_loop.h"

static int			extract_cmd(char *full_command, char *dest, size_t size)
{
	char	*end_cmd;
	size_t	size_to_cpy;

	if ((end_cmd = ft_strchr(full_command, (int)" ")) == NULL)
	{
		ft_strncpy(dest, full_command, size);
		return (1);
	}
	size_to_cpy = end_cmd - full_command;
	if (size_to_cpy > size - 1)
		return (-1);
	ft_strncpy(dest, full_command, size_to_cpy);
	dest[size_to_cpy] = '\0';
	return (1);
}

static int		execute_cmd(int sockfd, t_serv_fs *serv_fs)
{
	char	command[MAX_CMD_SIZE];
	char	cmd[4096];
	int		(*fn_cmd)(int, t_serv_fs *);
	int		i;
	int		ret;

	cmd[4095] = '\0';
	if (recv_cmd(sockfd, command, MAX_CMD_SIZE - 1) < 0)
		return (0);
	if (extract_cmd(command, cmd, 4095) < 0)
		return (0);
	i = NB_CMD;
	while (--i)
	{
		if (ft_strncmp(cmd, LIST_CMD[i].cmd, 4096) != 0)
			continue;
		fn_cmd = LIST_CMD[i].fn;
		ret = fn_cmd(sockfd, serv_fs);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			return (0);
	}
	printf("Unable to find cmd %s\n", cmd);
	return (1);
}

static int		init_serv_fs(t_serv_fs *serv_fs)
{
	if (!getcwd(serv_fs->cur_dir, MAX_PATH_SIZE))
	{
		printf("Unable to get current working dir\n");
		return (0);
	}
	ft_strcpy(serv_fs->base_dir, serv_fs->cur_dir);
	printf("Server launch on: %s\n", serv_fs->base_dir);
	return (1);
}

int					read_loop(int sockfd)
{
	t_serv_fs		serv_fs;
	int				ret;

	if (!(init_serv_fs(&serv_fs)))
		return (0);
	while (1)
	{
		ret = execute_cmd(sockfd, &serv_fs);
		if (ret < 0)
			return (1);
	}
	return (1);
}
