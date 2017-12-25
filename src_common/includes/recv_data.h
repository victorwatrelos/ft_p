#ifndef RECV_DATA_H
# define RECV_DATA_H

# include <sys/socket.h>
# include <shared_struct.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

# define SIZE_BUF 4096

int		recv_cmd(int sockfd, void *buff, ssize_t buff_size);
int 	recv_data(int sockfd, void *out, ssize_t size);
char	*recv_string(int sockfd, uint64_t *size);
int		recv_file(int sockfd, char *pathname);


#endif
