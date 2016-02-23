#include "str_utils.h"

char			*jump_after_space(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

char			*jump_to_space(char *line)
{
	while (*line != ' ' && *line != '\t' && *line != '\0')
		line++;
	return (line);
}
