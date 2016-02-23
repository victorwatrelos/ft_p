#ifndef CLIENT_STRUCT_H
# define CLIENT_STRUCT_H

# include <stdint.h>

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

#endif
