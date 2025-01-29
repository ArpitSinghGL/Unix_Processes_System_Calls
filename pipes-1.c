#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

// Calculate the total sum of an array by calculating the first half of the array
// using the parent process and the second half using the child process.

void main()
{
    int pipefd[2];

    if( pipe(pipefd) == -1)
    {
        printf("Some error occurred while creating the pipe !\n");
        return;
    }

    int nums[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

    // Creating a child process using fork() system call
    __pid_t pid = fork();

    if(pid != 0)
    {
        wait(NULL);

        close(pipefd[1]);

        int sum_from_parent = 0;

        for(int i = 0 ; i < 5 ; i++)
        {
            sum_from_parent += nums[i];
        }

        int sum_from_child;

        int num_of_bytes_read_from_child = read(pipefd[0] , &sum_from_child , sizeof(int));

        close(pipefd[0]);

        printf("Sum from parent: %d\n" , sum_from_parent);

        int total_sum = sum_from_parent + sum_from_child;

        printf("Total sum: %d\n" , total_sum);
    }
    else
    {
        close(pipefd[0]);

        int sum_from_child = 0;

        for(int i = 5 ; i < 10 ; i++)
        {
            sum_from_child += nums[i];
        }

        int num_of_bytes_written_from_child = write(pipefd[1] , &sum_from_child , sizeof(int));

        close(pipefd[1]);

        printf("Sum from child: %d\n" , sum_from_child);
    }

    return;

}