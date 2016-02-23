#ifndef RECV_DATA_H
# define RECV_DATA_H

# include <sys/socket.h>

int recv_data(int sockfd, void *out, ssize_t size);

#endif
