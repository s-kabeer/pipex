#include <stdlib.h>	/* needed to define exit() */
#include <unistd.h>	/* needed to define getpid() */
#include <stdio.h>	/* needed for printf() */

int main(int n,char *av[],char *env[])
{int i;
    while(*env)
    {
        printf("%s\n",*env);
        env++;
    }
}