#include "TCPConn.h"
#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fstream>
#include <string>

TCPConn::TCPConn(int socket, sockaddr_in &remoteAddr)
{
    this->socket = socket;
    this->remoteAddr = remoteAddr;
}

TCPConn::~TCPConn()
{
}

int TCPConn::recv()
{
    char buff[4096];
    int ret = ::recv(this->socket, buff, 4096, 0);
    if (ret < 0)
    {
        printf("error");
        return 0;
    }
    buff[ret] = '\0';

    printf("recv msg from client: %s\n", buff);
    FILE *fp = fopen("../resource/text", "w");
    fwrite(buff, ret, 1, fp);
    fclose(fp);
}

int TCPConn::send()
{
    std::string rmsg = "HTTP/1.1 200 OK\r\n";
    rmsg += "Server: ImageServer\r\n";
    rmsg += "Content-Type: image/jpeg\r\n";
    rmsg += "\r\n";
    ::send(this->socket, rmsg.c_str(), rmsg.size(), 0);

    int fd = open("../resource/85116637_p0.jpg", O_RDONLY);
    struct stat stat_buf;
    fstat(fd, &stat_buf);
    sendfile(this->socket, fd, NULL, stat_buf.st_size);
    // send(connfd, buff, 4096, 0);
    ::close(this->socket);
}

int TCPConn::close()
{
}
