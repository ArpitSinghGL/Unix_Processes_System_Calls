#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid = vfork();

    if(pid == 0)
    {
        printf("I will not invoke the exec() system call ! Do whatever the fuck you want !\n");
        while(1);
        // exit(0);
    }
    if(pid != 0)
    {
        printf("I am your father for god sake ! Show some respect you moron !\n");
    }

    return 0;
}