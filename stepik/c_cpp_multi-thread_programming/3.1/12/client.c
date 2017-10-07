#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
    int Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port = htons(12345);
    SockAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if ( connect(Socket, (struct sockaddr*)(&SockAddr), sizeof(SockAddr)) != -1) { //Did it succeeded? An error is -1.
        char Buffer[] = "PING";
        if (send(Socket, Buffer, 4, MSG_NOSIGNAL) != 1) { //Did it succeeded? An error is -1.
            if (recv(Socket, Buffer, 4, MSG_NOSIGNAL) != 1) //Did it succeeded? An error is -1.
                printf("%s\n", Buffer);
        }
        if (shutdown(Socket, SHUT_RDWR) == -1)
            printf("Shutdown error!");
        if (close(Socket) == -1 )
            printf("Close error!");
    }

    return 0;
}
