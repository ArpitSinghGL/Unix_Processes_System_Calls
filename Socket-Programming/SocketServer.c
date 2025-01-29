#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    // Creating a socket on the server
    int serverSocketFd = socket(AF_INET , SOCK_STREAM , 0);

    if(serverSocketFd == -1)
    {
        printf("Failed to create socket\n");
        return 1;
    }

    if(serverSocketFd == 0)
    {
        printf("Socket created successfully....\n");
    }

    struct sockaddr_in address;

    address.sin_port = htons(2000);  // PORT on which the server will listen
    address.sin_family = AF_INET;    // Address family for IPv4
    address.sin_addr.s_addr = INADDR_ANY;  // Address  to accept any incoming messages

    // Binding serverSocketFD to the local address "address" created above
    int bindFeedback = bind(serverSocketFd , (struct sockaddr*) &address , sizeof(address));

    if(bindFeedback == -1)
    {
        printf("Could not bind socket to local address\n");
        return 2;
    }

    if(bindFeedback == 0)
    {
        printf("Socket bound successfully....\n");
    }

    // listen for connections on a socket.
    // Prepare to accept connections on socket FD.
    // N connection requests will be queued before further requests are refused.
    // listen() marks the socket referred to by sockfd as a passive socket, that is, 
    // as a socket that will be used to accept incoming connection requests using accept().

    int listenFeedback = listen(serverSocketFd , 10);

    if(listenFeedback == -1)
    {
        printf("Could not listen to incoming connections\n");
        return 3;
    }

    if(listenFeedback == 0)
    {
        printf("Listening to incoming connections....");
    }

    // accept(): extracts the first connection request on the queue of pending connections 
    // for the listening socket, serverSocketFd, creates a new connected socket, and returns a 
    // new file descriptor referring to that socket. 
    // The newly created socket is not in the listening state.  
    // The original socket serverSocketFd is unaffected by this call.
    // The  argument  sockfd is a socket that has been created with socket(), bound to a 
    // local address with bind(), and is listening for connections after a listen().

    return 0;
}