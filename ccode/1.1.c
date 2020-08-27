//  1.1 file/ls1.c
// gcc 1.1.c                 ./a.out dir-name     ./a.out /bin
// add msg_errors.h
#include	<sys/types.h>
#include	<dirent.h>
#include	"ourhdr.h"
// following is order dependant  need atleast  string.h
// which is found in ourhdr.h
//
#include    "msg_errors.h"

int
main(int argc, char *argv[])
{
	DIR				*dp;
	struct dirent	*dirp;

	if (argc != 2)
		err_quit("a single argument (the directory name) is required");

	if ( (dp = opendir(argv[1])) == NULL)
		err_sys("can't open %s", argv[1]);

	while ( (dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);
}

