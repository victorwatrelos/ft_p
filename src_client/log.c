#include "log.h"

t_log	*get_log_struct(void)
{
	t_log	*log;

	if (!(log = malloc(sizeof(t_log))))
		return (NULL);
	ft_bzero(log, sizeof(t_log));
	return (log);
}

int		add_line(t_log *log, char *line)
{
	log->size_lst_event++;
	if (log->size_lst_event > MAX_HISTO)
		return (0);
	if (log->size_lst_event == MAX_HISTO)
	{
		log->list_event[log->size_lst_event - 1] = ft_strdup("Histo too long\n");
		return (0);
	}
	log->list_event[log->size_lst_event - 1] = ft_strdup(line);
	return (1);
}

int		display_log(t_log *log)
{
	size_t		i;

	i = 0;
	while (i < log->size_lst_event)
	{
		if (log->list_event[i])
			printf("%s\n", log->list_event[i]);
		++i;	
	}
	return (1);
}

int		free_log(t_log *log)
{
	size_t		i;

	i = 0;
	while (i < log->size_lst_event)
	{
		if (log->list_event[i])
			free(log->list_event[i]);
		++i;	
	}
	ft_bzero(log, sizeof(t_log));
	return (1);
}
