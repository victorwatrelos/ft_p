#ifndef CLIENT_STRUCT_H
# define CLIENT_STRUCT_H

# include <stdint.h>
# include <stdlib.h>

# define MAX_HISTO 128

# define MALLOC_FAIL " - Malloc fail"
# define INVALID_CMD " - Invalid command"
# define SEND_CMD_FAIL " - Send command to server fail"
# define SEND_STRING_FAIL " - Send string to server fail"
# define RECV_CMD_FAIL " - Reception of command confirmation fail"
# define RECV_MAGIC_CONF_FAIL " - Reception of confirmation from server fail"
# define RECV_CONF_FAIL " - Reception of confirmation from server fail"
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

typedef struct		s_param
{
	const char		*host;
	uint32_t		port;
	uint8_t			to_deco;
}					t_param;

typedef struct		s_cmd
{
	uint32_t		cmd;
	char			str[16];
	void			*fn;
}					t_cmd;

typedef struct		s_log
{
	char			*list_event[MAX_HISTO];
	size_t			size_lst_event;
	size_t			to_deco;
}					t_log;

#endif
