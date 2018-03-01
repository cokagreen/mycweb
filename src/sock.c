#include "sock.h"

int sock(int (* dosock)(request_t *, response_t *), request_t *reqptr, response_t *resptr)
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(9527);
	bind(sfd, (struct sockaddr *)&addr, sizeof(addr));
	
	listen(sfd, 3);
	
	char *buf = (char *)malloc(BUFLEN);
	while (1)
	{
		int cfd = accept(sfd, (struct sockaddr *)NULL, NULL);
		memset(buf, 0, BUFLEN);
		int nrecv = recv(cfd, buf, BUFLEN, 0);
		//int nread = read(cfd, buf, (1024));
		printf("\n[%s][%d] request=[%s]\n", __FILE__, __LINE__, buf);
		reqptr->id = cfd;
		reqptr->msg = buf;
		dosock(reqptr, resptr);
		memset(buf, 0, BUFLEN);
		sprintf(buf, "%d %s", resptr->id, (char *)resptr->msg);
		printf("[%s][%d] response=[%s]\n\n", __FILE__, __LINE__, buf);
		send(cfd, buf, BUFLEN, 0);
		//write(cfd, buf, 1024);
		close(cfd);
	}
	free(buf);
	close(sfd);
	return 0;
}
