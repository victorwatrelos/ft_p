#include "read_loop.h"

static int	exe_from_arg(int fd, char **args, int nb_args, t_serv_fs *serv_fs)
{
	t_cmd_fn	fn_cmd;
	int			i;
	int			ret;

	if (nb_args < 1)
		return (0);
	i = NB_CMD;
	while (i--)
	{
		printf("%s | %s\n", args[0], LIST_CMD[i].cmd);
		if (ft_strncmp(args[0], LIST_CMD[i].cmd, 4096) != 0)
			continue;
		fn_cmd = LIST_CMD[i].fn;
		ret = fn_cmd(fd, serv_fs, args, nb_args);
		return ret;
	}
	return (0);
}

static int	execute_cmd(int sockfd, t_serv_fs *serv_fs)
{
	char	command[MAX_CMD_SIZE];
	char	**args;
	int		nb_args;
	int		ret;

	command[4095] = '\0';
	if (recv_cmd(sockfd, command, MAX_CMD_SIZE - 1) < 0)
		return (-1);
	nb_args = get_args(command, &args);
	if (nb_args < 0)
		return (-1);
	if ((ret = exe_from_arg(sockfd, args, nb_args, serv_fs)) == 0)
		printf("Unable to find cmd %s\n", command);
	free_args(&args, nb_args);
	return (ret);
}

static int	init_serv_fs(t_serv_fs *serv_fs)
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

int			read_loop(int sockfd)
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
