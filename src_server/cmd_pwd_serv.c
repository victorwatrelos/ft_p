#include "cmd_pwd_serv.h"

int			cmd_pwd_serv(int sockfd, t_serv_fs *serv_fs)
{
	char			buff[MAX_PATH_SIZE + 1];
	uint32_t		conf;

	(void)serv_fs;
	conf = MAGIC_CONF_FAIL;
	if (!getcwd(buff, MAX_PATH_SIZE))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	buff[MAX_PATH_SIZE] = '\0';
	conf = MAGIC_CONF_SUCCESS;
	if (!send_data(sockfd, &conf, sizeof(conf)))
		return (0);
	if (!send_string(sockfd, buff, ft_strlen(buff)))
	{
		send_data(sockfd, &conf, sizeof(conf));
		return (0);
	}
	return (1);
}
