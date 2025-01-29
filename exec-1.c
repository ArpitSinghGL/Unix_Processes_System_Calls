#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

void main()
{
    int pid = fork();

    if(pid == 0)
    {
        printf("The child process is executing...\n");
        printf("Child process is invoking the exec() system call....\n");
        execl("/home/arpit-singh/Desktop/Embedded-Basics/a.out" , "/home/arpit-singh/Desktop/Embedded-Basics/a.out" , NULL);
        exit(0);
    }

    if(pid != 0)
    {
        wait(NULL);
        printf("The parent process is executing.....\n");
        printf("The parent process has completed execution !\n");
    }

    return;

}