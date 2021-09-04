#include "TCP.h"
#include <sys/unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>


TCP::TCP(char *address)
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
        printf("%s:%s socket() error\r\n", __FILE__, __LINE__);
        throw 10002;
    }
    sockaddr addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (::bind(this->socket, (sockaddr *)&addr, sizeof(sock)) == -1)
    {
        printf("%s:%s bind() error\r\n", __FILE__, __LINE__);
        throw 10003;
    }
}

int TCP::listen()
{
    if (::listen(this->socket, 10) == -1)
    {
        printf("%s:%s bind() error\r\n", __FILE__, __LINE__);
        return 10004;
    }
}

int TCP::start()
{
    sockaddr_in remote_addr;
    socklen_t addr_len = sizeof(remote_addr);
    if (::accept(this->socket, (sockaddr *)&remote_addr, &addr_len) == -1)
    {
        printf("%s:%s accept() error\r\n", __FILE__, __LINE__);
        throw 10005;
    }
    
}