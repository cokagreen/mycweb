#include <stdio.h>

#include "sock.h"

char msg[] = "OK";

int reqdeal(request_t *reqptr)
{
	printf("[%s][%d] REQID=[%d], REQMSG=[%s]\n", __FILE__, __LINE__, reqptr->id, (char *)reqptr->msg);
}

int resdeal(response_t *resptr)
{
	resptr->id = 200;
	resptr->msg = msg;
	printf("[%s][%d] RESID=[%d], RESMSG=[%s]\n", __FILE__, __LINE__, resptr->id, (char *)resptr->msg);
}

int tx(request_t *reqptr, response_t *resptr)
{
	reqdeal(reqptr);
	printf("[%s][%d] do something!\n", __FILE__, __LINE__);
	resdeal(resptr);
}

int main()
{
	request_t req;
	response_t res;
	memset(&req, 0, sizeof(req));
	memset(&res, 0, sizeof(res));
	sock(tx, &req, &res);
	return 0;
}
