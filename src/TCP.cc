#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "TCP.h"
#include "ThreadPool.h"
#include "Action.h"
#include "HTTPEntity.h"

TCP::TCP()
{
    TCP(8080);
}

TCP::TCP(int port)
{
    if (port > 65535 || port < 0)
    {
        throw 10001;
    }

    this->socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (this->socket == -1)
    {
        printf("%s:%d socket() error\r\n", __FILE__, __LINE__);
        throw 10002;
    }
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (::bind(this->socket, (sockaddr *)&addr, sizeof(addr)) == -1)
    {
        printf("%s:%d bind() error\r\n", __FILE__, __LINE__);
        throw 10003;
    }
}

int TCP::listen()
{
    if (::listen(this->socket, 10) == -1)
    {
        printf("%s:%d bind() error\r\n", __FILE__, __LINE__);
        return 10004;
    }
}

int TCP::start()
{
    while (1)
    {
        printf("waiting a connection...\r\n");
        sockaddr_in remote_addr;
        unsigned int addr_len = sizeof(remote_addr);
        int connfd;
        if ((connfd = ::accept(this->socket, (sockaddr *)&remote_addr, &addr_len)) == -1)
        {
            printf("%s:%d accept() error\r\n", __FILE__, __LINE__);
            throw 10005;
        }
        printf("accept a connection:%s \r\n", inet_ntoa(remote_addr.sin_addr));
        // char buff[4096];
        // int ret = recv(connfd, buff, 4096, 0);
        // if (ret < 0)
        // {
        //     printf("error\r\n");
        //     return 0;
        // }
        // send(connfd, buff, 4096, 0);
        // buff[ret] = '\0';

        // printf("recv msg from client: %s\n", buff);
        // close(connfd);
        HTTPResponse hTTPResponse;
        executor.commit(sendRandomImage, connfd, hTTPResponse);
        // -------------------------------------------------------------------------------------------------
    }
}

TCP::~TCP()
{
}