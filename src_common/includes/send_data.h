#ifndef SEND_DATA_H
# define SEND_DATA_H

# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/tcp.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int		send_data(int sockfd, void *data, ssize_t size);
int		send_string(int sockfd, char *str, uint64_t size);

#endif
