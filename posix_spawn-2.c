#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <spawn.h>
#include <string.h>

extern char** environ;

void main()
{
    pid_t child_pid;   // Process ID for the child process

    char* argv[] = {"/bin/ls" , "-l" , NULL};   // arguments to the ls command

    // spawning the child process
    int child_process_status = posix_spawn(&child_pid , "/bin/ls" , NULL , NULL , argv , environ);

    if(child_process_status == 0)
    {
        pid_t parent_pid = getpid();
        printf("This is the parent process with pid: %d\n" , parent_pid);
        printf("Child process was created successfully with pid: %d\n" , child_pid);

        // Parent process waiting for the child process matching pid to terminate
        if( waitpid(child_pid , &child_process_status , 0) == child_pid )
        {
            if(WIFEXITED(child_process_status))
            {
                printf("Child process exited normally with status: %d\n" , WEXITSTATUS(child_process_status));
            }
            else
            {
                printf("Child process did not terminate normally\n");
            }
        }
        else if( waitpid(child_pid , &child_process_status , 0) == -1 )
        {
            perror("waitpid failed");
            return;
        }
    }
    else
    {
        printf("posix_spawn failed to create child process: %s\n" , strerror(child_process_status));
    }

    return;
}