#ifndef CLIENT_STRUCT_H
# define CLIENT_STRUCT_H

# include <stdint.h>
# include <stdlib.h>

# define MAX_HISTO 128

typedef struct		s_param
{
	const char		*host;
	uint32_t		port;
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
