// 1.7	file/uidgid.c
// print uid and gid os executing user

#include	"ourhdr.h"

int
main(void)
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	exit(0);
}

