// 1.4	file/hello.c
// gcc 1.4.c                a./out
// 
#include	"ourhdr.h"

int
main(void)
{
	printf("hello world from process ID %d\n", getpid());
	exit(0);
}

