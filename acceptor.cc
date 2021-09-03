/***********************************************************************************************
 ***                                                                                         ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : ImageServer                                                  *
 *                                                                                             *
 *                    File Name : acceptor.cc                                                  *
 *                                                                                             *
 *                   Programmer : yunru                                                        *
 *                                                                                             *
 *                   Start Date : Sep 04, 2021                                                 *
 *                                                                                             *
 *                  Last Update : Sep 04, 2021 [yunru]                                         *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   return_ifn_error -- process error code                                                    *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "header.cc"
using namespace std;

int return_ifn_error(int actual, int error_code, char const *error_msg);

int main()
{
    int listenfd;
    char buff[4096];

    listenfd = return_ifn_error(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP), -1, "socket()");

    sockaddr_in sock;
    sock.sin_family = AF_INET;
    sock.sin_port = htons(26413);
    sock.sin_addr.s_addr = htonl(INADDR_ANY);

    return_ifn_error(bind(listenfd, (sockaddr *)&sock, sizeof(sock)), -1, "bind()");
    return_ifn_error(listen(listenfd, 10), -1, "listen()");

    while (1)
    {
        printf("waiting a connection...\r\n");
        // -------------------------------------------------------------------------------------------------
        sockaddr_in remote_addr;
        int connfd = return_ifn_error(accept(listenfd, (sockaddr *)&remote_addr, NULL), -1, "accept()");
        printf("accept a connection:%s \r\n", inet_ntoa(remote_addr.sin_addr));

        int ret = recv(connfd, buff, 4096, 0);
        if (ret < 0)
        {
            printf("error");
            return 0;
        }
        send(connfd, buff, 4096, 0);
        buff[ret] = '\0';

        printf("recv msg from client: %s\n", buff);
        close(connfd);
        // -------------------------------------------------------------------------------------------------
    }
    return 1;
}

int return_ifn_error(int actual, int error_code, char const *error_msg)
{
    if (actual == error_code)
    {
        printf("%s\r\n", error_msg);
        exit(0);
    }
    return actual;
}