#include "main_server.h"

static t_param		*parse_param(int argc, char **argv)
{
	size_t		size;
	t_param		*res;
	uint32_t	val;

	if (argc < 2)
		return (NULL);
	size = ft_strlen(argv[1]);
	if (!size)
		return (NULL);
	while (size--)
	{
		if (!ft_isdigit(argv[1][size]))
			return (NULL);
	}
	if ((val = ft_atoi(argv[1])) > 0xFFFF)
		return (NULL);
	if (!(res = malloc(sizeof(t_param))))
		return (NULL);
	res->port = val;
	return (res);
}

int		main(int argc, char **argv)
{
	t_param		*param;

	if (!(param = parse_param(argc, argv)))
	{
		printf("./serveur port\n");
		return (1);
	}
	launch_server(param);
	return (0);
}
