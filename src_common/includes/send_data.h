#ifndef SEND_DATA_H
# define SEND_DATA_H

# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/tcp.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

# define BUF_FILE_SIZE 4096

int		send_data(int sockfd, void *data, ssize_t size);
int		send_string(int sockfd, char *str, uint64_t size);
int		send_file(int sockfd, int filefd);

#endif
