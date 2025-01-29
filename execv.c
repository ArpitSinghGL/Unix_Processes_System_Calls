#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
    char* args[4] = {"/usr/bin/echo" , "Hello " , "World !" , NULL};
    execv(args[0] , args);
    // If we get to this line, we know that something went wrong....
    perror("execv failed");
    exit(1);
}