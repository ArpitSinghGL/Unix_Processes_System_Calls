#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    printf("\n");

    // ----------------------------------------------------------------------------------------------

    int fd = open("a.txt" , O_RDWR | O_APPEND | O_EXCL);

    char message_read_from_fd[1024];

    int num_of_bytes_read_from_fd = read(fd , message_read_from_fd , sizeof(message_read_from_fd));

    printf("num_of_bytes_read_from_fd: %d\n" , num_of_bytes_read_from_fd);

    printf("%s\n" , message_read_from_fd);

    memset(message_read_from_fd , 0 , strlen(message_read_from_fd));

    printf("\n");

    // ---------------------------------------------------------------------------------------------

    char user_input[1024];

    printf("Taking user input from the terminal: \n");

    int num_of_bytes_user_input = read(0 , user_input , sizeof(user_input));

    printf("\n");

    printf("num_of_bytes_user_input: %d\n" , num_of_bytes_user_input);

    printf("user_input: %s\n" , user_input);

    // ----------------------------------------------------------------------------------------------

    int num_of_bytes_written_to_fd = write(fd , user_input , strlen(user_input));

    memset(user_input , 0 , strlen(user_input));

    printf("num_of_bytes_written_to_fd: %d\n" , num_of_bytes_written_to_fd);

    // ------------------------------------------------------------------------------------------------

    lseek(fd , 0 , SEEK_SET);

    num_of_bytes_read_from_fd = read(fd , message_read_from_fd , sizeof(message_read_from_fd));

    printf("num_of_bytes_read_from_fd: %d\n" , num_of_bytes_read_from_fd);

    printf("message_read_from_fd: %s\n" , message_read_from_fd);

    close(fd);

    printf("\n");

    return 0;
}