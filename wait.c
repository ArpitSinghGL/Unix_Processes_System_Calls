#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Task: Create two processes and print 1-5 using one process and 6-10 using other process

void main()
{
    int id = fork();

    if(id == 0)
    {
        for(int i = 1 ; i <= 5 ; i++)
        {
            printf("%d " , i);
        }
    }
    else
    {
        wait();
        for(int i = 6 ; i <= 10 ; i++)
        {
            printf("%d " , i);
        }
        printf("\n");
    }
}