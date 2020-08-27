// 1.5	proc/shell1.c
//  gcc 1.5.c                              ./a.out
//
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"ourhdr.h"
#include    "msg_errors.h"              /* rch add */

int
main(void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int		status;

	printf("%% ");	/* print prompt (printf requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		buf[strlen(buf) - 1] = 0;	/* replace newline with null */

		if ( (pid = fork()) < 0)
			err_sys("fork error");

		else if (pid == 0) {		/* child */
			execlp(buf, buf, (char *) 0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		/* parent */
		if ( (pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}

