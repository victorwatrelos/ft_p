#include "cmd_ls.h"

int			cmd_ls(int sockfd, char *line, uint32_t cmd)
{
	printf("line for ls: %s\n", line);
	return (1);
}
