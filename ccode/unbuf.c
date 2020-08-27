#include <errno.h>
#include <stdarg.h>
#include "ourhdr.h"
// #define MAXLINE  256
#include <string.h>


/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag".
 */
static void
err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
    char    buf[MAXLINE];
    vsnprintf(buf, MAXLINE, fmt, ap);
    if (errnoflag)
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s",
    strerror(error));
    strcat(buf, "\n");
    fflush(stdout);     /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL);       /* flushes all stdio output streams */
}


/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void
err_sys(const char *fmt, ...)
{
    va_list     ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}


#define BUFFSIZE  8192

/*
void err_sys(const char* x){
    perror(x);
    exit(1);
}
*/

int main(void) {
  int n;
  char buf[BUFFSIZE];
  while ( (n = read(STDIN_FILENO, buf, BUFFSIZE) ) > 0)
      if (write(STDOUT_FILENO, buf,n) != n)
        err_sys("write error.");

  if (n < 0)
      err_sys("read error.");

  exit(0);
}

