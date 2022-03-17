#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define MAX 1024
#define PORT 11000
#define SA struct sockaddr

void func(int sockfd){
    char buff[MAX];     // character array
    int n;      // char index in char array
    for(;;){
        bzero(buff, sizeof(buff));      // zero out memory where buffer is located
        printf("Enter string: ");
        n = 0;
        while((buff[n++] = getchar()) != '\n');     // get characters in array

        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if((strncmp(buff, "exit", 4)) == 0){
            printf("Client Exit...\n");
            break;
        }
    }
}


int main(){
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // create socket and verify
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("socket creation failed...\n");
        exit(0);
    } else
        printf("Socket creation succeeded..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP and PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
}