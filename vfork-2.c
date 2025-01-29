#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
    int pid = vfork();

    if(pid == 0)
    {
        printf("The child process is executing....\n");
        printf("The child process is invoking the exec() system call...\n");
        execl("/home/arpit-singh/Desktop/Embedded-Basics/test3" , 
        "/home/arpit-singh/Desktop/Embedded-Basics/test3" , 
        NULL);
    }
    if(pid != 0)
    {
        printf("This is the parent process !\n");
        printf("The parent process is suspended until the either the child process finishes execution or terminates or invokes the exec() system call.....\n");
        printf("The parent process is executing....\n");
        printf("The parent process has finished execution !\n");
    }

    return;
}