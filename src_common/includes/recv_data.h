#ifndef RECV_DATA_H
# define RECV_DATA_H

# include <sys/socket.h>
# include <shared_struct.h>
# include <stdlib.h>
# include <unistd.h>

int 	recv_data(int sockfd, void *out, ssize_t size);
char	*recv_string(int sockfd, uint64_t *size);


#endif
