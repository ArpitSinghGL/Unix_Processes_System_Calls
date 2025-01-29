#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <spawn.h>

// External symbol that always points to the list of environment variables
extern char** environ;

void main()
{
    char* args[4] = {"/usr/bin/echo" , "Hello " , "World !" , NULL};

    int child_status;
    int result;

    if(posix_spawn(&result , args[0] , NULL , NULL , args , environ) != 0)
    {
        perror("spawn failed");
        exit(1);
    }
    wait(&child_status);
    return;
}