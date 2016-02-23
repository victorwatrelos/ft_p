#ifndef SHARED_STRUCT_H
# define SHARED_STRUCT_H

# define MAGIC 0x1234

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
