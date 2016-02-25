#include "read_loop.h"

static int			wait_for_cmd(int sockfd)
{
	uint32_t	magic;
	int			nb_try;

	nb_try = NB_TRY_MAGIC;
	while (nb_try)
	{
		if (!recv_data(sockfd, &magic, sizeof(uint32_t)))
				return (0);
		if (magic != MAGIC_CMD)
		{
			printf("Magic invalid (%d)\n", nb_try);
			nb_try--;
			continue ;
		}
		return (1);
	}
	return (0);
}

static void			*get_cmd(uint32_t cmd)
{
	int		i;

	i = NB_CMD;
	while (i--)
	{
		if (LIST_CMD[i].cmd == cmd)
			return (LIST_CMD[i].fn);
	}
	return (NULL);
}

static int			init_serv_fs(t_serv_fs *serv_fs)
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
	uint32_t		cmd;
	int				(*fn_cmd)(int, t_serv_fs *);
	t_serv_fs		serv_fs;

	if (!(init_serv_fs(&serv_fs)))
		return (0);
	while (1)
	{
		if (!wait_for_cmd(sockfd))
			return (0);
		if (!recv_data(sockfd, &cmd, sizeof(uint32_t)))
			return (0);
		if (!(fn_cmd = get_cmd(cmd)))
		{
			printf("Command not recognise\n");
			continue ;
		}
		if (!(fn_cmd(sockfd, &serv_fs)))
			printf("Command execution fail\n");
	}
	return (1);
}
