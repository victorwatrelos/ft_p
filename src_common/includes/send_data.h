#ifndef SEND_DATA_H
# define SEND_DATA_H

# include <sys/socket.h>

int		send_data(int sockfd, void *data, ssize_t size);

#endif
