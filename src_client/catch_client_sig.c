#include "catch_client_sig.h"

static void		catch_sigpipe(void)
{
	printf("Server disconnect\nGood bye\n");
	exit(0);
}

void			catch_client_sig(int sig)
{
	if (sig == SIGPIPE)
		catch_sigpipe();
}
