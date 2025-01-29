#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int id = fork();  // The Main process or Parent-1 spawns a Child process Child-1

    // Total number of process at this stage: 2 ( Parent-1 and Child-1 )

    // Parent-1 : 6842 --> Process Id of the child process Child-1 is returned to the parent process Parent-1
    // Child-1 : 0  ---> 0 is returned to the child process Child-1

    printf("Process Id: %d says Hello World !\n" , id);

    // Ouput from Parent-1 : Process Id: 6842 says Hello World !
    // Ouptput from Child-1 : Process Id: 0 says Hello World !

    int id1 = fork();  // Both Parent-1 and Child-1 each spawn a Child Process

    // Parent-1 spawns Child-2
    // Child-1 spawns Child-1.1

    // Total Number of processes at this stage: 4 ( Parent-1 , Child-1 , Child-2 , Child-1.1 )

    // Parent-1 : 6843  ---> Process Id of the Child process Child-2 is returned to Parent process Parent-1
    // Child-2 : 0 ---> 0 is returned to the Child Process Child-2
    // Child-1 : 6844 ---> Process Id of the Child Process Child-1.1 is returned to the Parent process Child-1
    // Child-1.1 : 0 ---> 0 is returned to the child process Child-1.1

    printf("Process Id1: %d says Bye World !\n" , id1);

    // Output from Parent-1: Process Id: 6843 says Hello World !
    // Ouput from Child-1: Process Id: 6844 says Hello World !
    // Output from Child-2: Process Id: 0 says Hello World !
    // Output from Child-1.1: Process Id: 0 says Hello World !

    return 0;
}
