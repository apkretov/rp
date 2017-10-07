#include <stdio.h>

#include <sys/types.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int arqgc, char** argv) {
	int MasterSocket = socket(
		AF_INET /*Ipv4*/,
		SOCK_STREAM /*TCP*/,
        IPPROTO_TCP);
	
    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port = htons(12345);
    SockAddr.sin_addr.s_addr = htonl(INADDR_ANY); //0.0.0.0
    if (bind(MasterSocket, (struct sockaddr*)(&SockAddr), sizeof(SockAddr)) == 0) { //Did it succeeded? An error is -1.
        if (listen(MasterSocket, SOMAXCONN) == 0) { //Did it succeeded? An error is -1.
            while(1) {
                int SlaveSocket = accept(MasterSocket, 0, 0);
                if (SlaveSocket != -1) { //Did it succeeded? An error is -1.
                    int Buffer[5] = {0, 0, 0, 0, 0};

                    unsigned int counter = 0;
                    /*ORIG: Error!
                    while(counter < 4) {
                        int res = recv(SlaveSocket, Buffer + 4 - counter, counter, MSG_NOSIGNAL);
                        if (res > 0) counter += res;
                    }*/
                    if (recv(SlaveSocket, Buffer, 4, MSG_NOSIGNAL) != -1) { //Did it succeeded? An error is -1.
                        printf("%s\n", Buffer);
                        /*ORIG
                        if (send(SlaveSocket, Buffer, 4, MSG_NOSIGNAL) == -1)
                            printf("Send error!\n");
                        */
                    }
                    if (shutdown(SlaveSocket, SHUT_RDWR) == -1)
                        printf("Shutdown error!");
                    if (close(SlaveSocket) == -1 )
                        printf("Close error!");
                }
            }
        }
    }

	return 0;
}
