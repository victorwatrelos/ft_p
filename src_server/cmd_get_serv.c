#include "cmd_get_serv.h"

static char	*remove_filename(char *path)
{
	char	*end;
	char	*res;

	if (!(res = ft_strdup(path)))
		return (NULL);
	if (!(end = ft_strrchr(res, '/')))
	{
		free(res);
		return (NULL);
	}
	*end = '\0';
	return (res);
}

static int	get_file_content(char *filename, char *pathname, t_serv_fs *serv_fs)
{
	int				fd;
	struct stat		stat;

	if (!test_rel_path(pathname, serv_fs->base_dir))
		return (-1);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (-1);
	if (fstat(fd, &stat) < 0)
		return (-1);
	if (!(stat.st_mode & S_IRUSR))
		return (-1);
	return (fd);
}

static int	get_file(char *path, t_serv_fs *serv_fs)
{
	char	*filename;
	char	*pathname;
	int		fd;

	if (!(filename = add_dot_begining(path)))
		return (-1);
	if (!(pathname = remove_filename(filename)))
	{
		free(filename);
		return (-1);
	}
	fd = get_file_content(filename, pathname, serv_fs);
	free(filename);
	free(pathname);
	return (fd);
}

int			cmd_get_serv(int sockfd, t_serv_fs *serv_fs)
{
	char			*path;
	uint32_t		conf;
	int				filefd;

	conf = MAGIC_CONF_FAIL;
	if (!(path = recv_string(sockfd, NULL)))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	if ((filefd = get_file(path, serv_fs)) < 0)
	{
		free(path);
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	free(path);
	conf = MAGIC_CONF_SUCCESS;
	if (!(send_data(sockfd, &conf, sizeof(conf))))
	{
		close(filefd);
		return (0);
	}
	if (!send_file(sockfd, filefd))
	{
		close(filefd);
		return (0);
	}
	close(filefd);
	return (1);
}
