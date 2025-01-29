#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 1024

// Structure for message queue
struct Message
{
    long message_type;
    char message_buffer[MAX];
} message;

int main()
{
    // ftok ---> file-to-key ---> to generate unique-key using a file-path
    key_t key =  ftok("progFile.txt" , 65);

    // msgget creates a message queue and returns a unique identifier of the message queue created.

    // Create key if key does not exist. Expands to: 01000 ---> Octal(1000) = Decimal(512)
    // File permissions: 0666 ---> Octal(666) ---> (rw , rw , rw) to (Owner , Group , Others/Users)
    // READ acces: 4 , WRITE access: 2 , EXECUTE access: 1

    int msgid = msgget(key , 0666 | IPC_CREAT);

    if(msgid == -1)
    {
        printf("Could not create message queue !\n");
        return 1;
    }

    message.message_type = 1;  // What does this mean ?

    while(1)
    {
        printf("Write a message to send: \n");

        // Writing a message to the message buffer
        fgets(message.message_buffer , MAX , stdin);

        printf('\n');

        // Sending the message structure to the message queue having uniqie-id: msgid
        msgsnd(msgid , &message , sizeof(message) , 0);

        // Displaying the message sent
        printf("Message Sent: \n");

        printf("%s\n" , message.message_buffer);
    }
    
    return 0;
}