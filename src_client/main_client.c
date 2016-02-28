#include "main_client.h"

t_param		*parse_arg(int argc, const char *argv[])
{
	t_param		*res;
	uint32_t	port;
	size_t		size;

	if (argc < 3)
		return (NULL);
	size = ft_strlen(argv[2]);
	if (!size)
		return (NULL);
	while (size--)
	{
		if (!ft_isdigit(argv[2][size]))
			return (NULL);
	}
	if ((port = ft_atoi(argv[2])) > 0xFFFF)
		return (NULL);
	if (!(res = malloc(sizeof(t_param))))
		return (NULL);
	res->port = port;
	res->host = argv[1];
	return (res);
}

int 		main(int argc, const char *argv[])
{
	t_param		*param;

	if (!(param = parse_arg(argc, argv)))
	{
		printf("./client hostname port\n");
		return (1);
	}
	signal(SIGPIPE, catch_client_sig);
	connect_to_server(param);
	free(param);
	return 0;
}
