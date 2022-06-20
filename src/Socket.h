#ifndef _SOCKET_
#define _SOCKET_

#include <stdexcept>
#include <string>
#include <filesystem>
#include <fstream>
#include <stdio.h>

#include <spdlog/spdlog.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// ---------------------------------------------------------
std::string readfile(const std::string &filename);
// ---------------------------------------------------------
class Socket
{
private:
    int socket;
    int port;
    sockaddr_in remoteAddr;
public:
    Socket(int socket, sockaddr_in &remoteAddr);
    int recv();
    int send();
    int close();
    int send(std::string path);
    int send(const char *path);
    ~Socket();
};
// ---------------------------------------------------------
class ServerSocket
{
private:
    int socket = 0;
    int actual_socket = 0;
    int port = -1;
public:
    ServerSocket();
    ServerSocket(int port);
    void bind(int port);
    void listen();
    Socket *accept();
    ~ServerSocket();
};
// ---------------------------------------------------------

ServerSocket::ServerSocket()
{
}

ServerSocket::ServerSocket(int port)
{
    bind(port);
}

void ServerSocket::bind(int port)
{
    if (port > 65535 || port < 0)
        throw std::runtime_error("port out of bound.");

    this->port = port;
    this->socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (this->socket == -1)
        throw std::runtime_error("");
    
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (::bind(this->socket, (sockaddr *)&addr, sizeof(addr)) == -1)
        throw std::runtime_error("");
}

void ServerSocket::listen()
{
    if (this->port < 0)
        throw std::runtime_error("socket is not bound yet.");

    if (::listen(this->socket, 10) == -1)
    {
        throw std::runtime_error("listen error.");
    }
}

Socket *ServerSocket::accept()
{
    // printf("waiting a connection...\r\n");
    sockaddr_in remote_addr;
    unsigned int addr_len = sizeof(remote_addr);
    int connfd;
    if ((connfd = ::accept(this->socket, (sockaddr *)&remote_addr, &addr_len)) == -1)
        throw std::runtime_error("");

    return new Socket(connfd, remote_addr);

    // 以下是通信逻辑，职责分离后删除
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

    // todo:  using singleton alter static
}

ServerSocket::~ServerSocket()
{
}

Socket::Socket(int socket, sockaddr_in &remoteAddr)
{
    this->socket = socket;
    this->remoteAddr = remoteAddr;
}

int Socket::recv()
{
    // recv 函数目前没有任何的判断逻辑，只是收到消息保存到文件中
    char buff[4096];
    int ret = ::recv(this->socket, buff, 4096, 0);
    if (ret < 0)
    {
        spdlog::error("{0}:{1} recv() error", __FILE__, __LINE__);
        return 0;
    }
    buff[ret] = '\0';
    FILE *fp = fopen("../resource/request/text", "w");
    fwrite(buff, ret, 1, fp);
    fclose(fp);
    return 1;
}

int Socket::send()
{
    send("../resource/image/85116637_p0.jpg");
}

int Socket::close()
{
    return 1;
}

int Socket::send(std::string path)
{
    send(path.c_str());
}

int Socket::send(const char *path)
{
    std::string rmsg = readfile("../resource/response/normal.txt");
    ::send(this->socket, rmsg.c_str(), rmsg.size(), 0);

    FILE *file = fopen(path, "r");
    int fd = fileno(file);

    struct stat stat_buf;
    fstat(fd, &stat_buf);
    sendfile(this->socket, fd, NULL, stat_buf.st_size);

    fclose(file);
    ::close(this->socket);
    return 1;
}

Socket::~Socket()
{
}

std::string readfile(const std::string &filename)
{
    std::ifstream ifile(filename);
    std::string temp;
    std::string res;
    while (std::getline(ifile, temp))
    {
        res += temp;
        res += "\n";
    }
    return res;
}

#endif