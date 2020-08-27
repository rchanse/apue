// https://www.includehelp.com/c-programs/va_start-and-va_end-functions-of-stdarg-h-in-c.aspx
//
#include <stdio.h>
#include <stdarg.h>

int fun(int a, ...)
{
    // define type of variable
    va_list L;
    int z;

    z = 0;

    va_start(L, a);

    // Loop to adding the int values
    for (int i=0; i < a; i++)
    {
        z = z + va_arg(L, int);
    }

    va_end(L);

    return z;
}

int main()
{
    // Define temporary variables
    int x, y, z;
    int k;

    x = 2;
    y = 3;
    z = 4;

    // calling function
    k = fun(3, x, y, z);

    // displaying message with result
    printf("Total of %d, %d and %d is %d\n", x, y, z, k);
    return 0;
}

