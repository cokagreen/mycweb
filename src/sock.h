#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFLEN 1024

typedef struct __request{
	int id;
	void *msg;
} request_t;

typedef struct __response {
	int id;
	void *msg;
} response_t;
int sock(int (* dosock)(request_t *, response_t *), request_t *reqptr, response_t *resptr);
