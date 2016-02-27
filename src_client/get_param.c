#include "get_param.h"

int	get_param(char *line, char **p1)
{
	char		*end;

	line = jump_after_space(line);
	if (*line == '\0')
		return (0);
	end = jump_to_space(line);
	if (*(jump_after_space(end)) != '\0')
		return (0);
	*end = '\0';
	*p1 = line;
	return (1);
}

int	get_2_params(char *line, char **p1, char **p2)
{
	char		*end;

	line = jump_after_space(line);
	if (*line == '\0')
		return (0);
	*p1 = line;
	end = jump_to_space(line);
	if (*end == '\0')
		return (0);
	*end = '\0';
	end++;
	if (*(*p2 = jump_after_space(end)) == '\0')
		return (0);
	if (!(end = jump_to_space(*p2)))
		return (0);
	if (*(jump_after_space(end)) != '\0')
		return (0);
	*end = '\0';
	return (1);
}
