#include "catch_signal.h"

static void	catch_sigint(void)
{
	if (g_sockfd < 0)
		printf("Good bye\n");
	else
	{
		close(g_sockfd);
		printf("Client disconnected\n");
	}
	exit(0);
}

static void	catch_sigpipe(void)
{
	if (g_sockfd >= 0)
		close(g_sockfd);
	printf("Client disconnected\n");
}

void		catch_signal(int sig)
{
	if (sig == SIGINT)
		catch_sigint();
	if (sig == SIGPIPE)
		catch_sigpipe();
}
