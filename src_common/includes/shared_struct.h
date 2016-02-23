#ifndef SHARED_STRUCT_H
# define SHARED_STRUCT_H

# include <stddef.h>
# include <stdint.h>

# define MAGIC_CMD 0x1234
# define MAGIC_CONNECT_CLIENT 0x9897
# define MAGIC_CONNECT_RESPONSE_SERVER 0x32343

typedef struct		s_connect_response
{
	uint32_t		magic;
}					t_connect_response;

typedef struct		s_connect
{
	uint32_t		magic;
}					t_connect;

typedef struct		s_command
{
	uint32_t		magic;
	uint32_t		command;
}					t_command;

typedef struct		s_string
{
	uint64_t		size;
	char			*str;
}					t_string;

typedef struct		s_file
{
	char			*name;
	uint32_t		chmod;
	uint64_t		size;
}					t_file;

#endif
