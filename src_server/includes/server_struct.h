#ifndef SERVER_STRUCT_H
# define SERVER_STRUCT_H

# include <stddef.h>
# include <stdint.h>

# define MAX_PATH_SIZE 4095

typedef struct		s_param
{
	uint32_t		port;
}					t_param;

typedef struct		s_serv_fs
{
	char			cur_dir[MAX_PATH_SIZE + 1];
	char			base_dir[MAX_PATH_SIZE + 1];
	struct in_addr	*client_addr;
	
}					t_serv_fs;

typedef int (*t_cmd_fn)(int, t_serv_fs *, char **, int);

typedef struct		s_cmd
{
	t_cmd_fn		fn;
	char			*cmd;
}					t_cmd;

#endif
