#ifndef LOG_H
# define LOG_H

# include <stdio.h>
# include <libft.h>

# include "client_struct.h"

# define INVALID_CMD " - Invalid command"
# define SEND_CMD_FAIL " - Send cmd to server fail"
# define SEND_STRING_FAIL " - Send string to server fail"
# define RECV_MAGIC_CONF_FAIL " - Reception of confirmation from server fail"
# define MAGIC_CONF_INVALID " - Magic number of server confirmation is invalid"
# define RECV_STRING_FAIL " - String reception from server fail"
# define RECV_FILE_FAIL " - File reception fail"
# define SEND_FILE_FAIL " - File sending fail"
# define FILE_OPENING_FAIL " - Unable to open the file"

# define INVALID_ARG_GET " - Argument invalid (get src dest)"
# define INVALID_ARG_PUT " - Argument invalid (put src dest)"
# define INVALID_ARG_CD " - Argument invalid (cd path)"

# define SUCCESS_MSG "SUCCESS"
# define FAILURE_MSG "FAIL"

t_log	*get_log_struct(void);
int		display_log(t_log *log);
int		free_log(t_log *log);
int		add_line(t_log *log, char *line);

#endif
