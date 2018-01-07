#ifndef SHARED_STRUCT_H
# define SHARED_STRUCT_H

# include <stddef.h>
# include <stdint.h>

# define MAGIC_CMD 0x1234
# define MAGIC_CONF_SUCCESS 0x1232
# define MAGIC_CONF_FAIL 0x4534
# define MAGIC_CONNECT_CLIENT 0x9897
# define MAGIC_CONNECT_RESPONSE_SERVER 0x32343

#define MAX_CMD_SIZE 65535
#define CMD_CONNECT "\"CONNECT\""
#define CMD_CONNECT_RESPONSE "\"CONNECTED\""
#define CMD_QUIT "QUIT"
#define CMD_QUIT_CONFIRMED "QUIT CONFIRMED"
#define CMD_LS "LS"

# define ADD_QUOTE(x) "\"" x "\""

typedef struct						s_connect_response
{
	uint32_t		magic;
} __attribute__ ((__packed__))		t_connect_response;

typedef struct						s_connect
{
	uint32_t		magic;
} __attribute__ ((__packed__))		t_connect;

typedef struct						s_command
{
	uint32_t		magic;
	uint32_t		command;
} __attribute__ ((__packed__))		t_command;

typedef struct						s_conf
{
	uint32_t						magic;
	uint8_t							success;
}									t_conf;						

typedef struct						s_string
{
	uint64_t		size;
} __attribute__ ((__packed__))		t_string;

typedef struct						s_file
{
	uint64_t		size;
	uint32_t		chmod;
	char			*name;
} __attribute__ ((__packed__))		t_file;

#endif
