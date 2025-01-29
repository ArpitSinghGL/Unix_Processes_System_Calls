#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    int pipefd[2];

    if( pipe(pipefd) == -1 )
    {
        printf("Some error occurred while creating the pipe !\n");
        return;
    }

    // Creating a child process using fork() system call
    int id = fork();

    if(id != 0)
    {
        // Parent Process ---> Sender Process

        // Closing the READ end of the pipe for the parent process as it is not used by the parent process
        close(pipefd[0]); 

        sleep(5);

        char* message = "My name is Oliver Queen !";

        size_t num_of_bytes_written = write(pipefd[1] , message , strlen(message));

        // Closing the WRITE end of the pipe for the parent process after use
        close(pipefd[1]);

        printf("\n");
        printf("The number of bytes written to the pipe by the parent process is: %zu\n" , num_of_bytes_written);
        printf("The message written to the pipe by the parent process is: %s\n" , message);
        printf("\n");

    }
    else
    {
        // Child Process ---> Reciever Process

        close(pipefd[1]);

        char messageRead[256];

        size_t num_of_bytes_read = read(pipefd[0] , messageRead , 17);

        close(pipefd[0]);

        printf("\n");
        printf("The number of bytes read from the pipe is: %zu\n" , num_of_bytes_read);
        printf("The message read from the pipe by the child process is: %s\n" , messageRead);
        printf("\n");
    }

    return;

}