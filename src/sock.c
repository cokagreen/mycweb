#include "sock.h"

int sock(void *(* dosock)(void *), void *arg)
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(9527);
	bind(sfd, (struct sockaddr *)&addr, sizeof(addr));
	
	listen(sfd, 3);
	
	char buf[1024];
	while (1)
	{
		int cfd = accept(sfd, (struct sockaddr *)NULL, NULL);
		memset(buf, 0, sizeof(buf));
		int nrecv = recv(cfd, buf, sizeof(buf), 0);
		dosock(arg);
		send(cfd, buf, nrecv, 0);
		close(cfd);
	}
	close(sfd);
	return 0;
}
