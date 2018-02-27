#include <stdio.h>

#include "sock.h"

void *ha(void *arg)
{
	printf("[DOSOCK] %s\n", (char *)arg);
}

int main()
{
	sock(ha, (void *)"hello");
	return 0;
}