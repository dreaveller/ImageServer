#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <fstream>
#include <fcntl.h>
#include <sys/stat.h>
#include <string>
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
        unsigned int addr_len = sizeof(remote_addr);
        int connfd = return_ifn_error(accept(listenfd, (sockaddr *)&remote_addr, &addr_len), -1, "accept()");
        printf("accept a connection:%s \r\n", inet_ntoa(remote_addr.sin_addr));

        int ret = recv(connfd, buff, 4096, 0);
        if (ret < 0)
        {
            printf("error");
            return 0;
        }
        // FILE *fp = fopen("85116637_p0.jpg", "rb");
        // fseek(fp, 0, SEEK_END);
        // int fsize = ftell(fp);
        // fseek(fp, 0, SEEK_SET);

        
        string rmsg = "HTTP/1.1 200 OK\r\n";
        rmsg += "Server: XHttp\r\n";
        rmsg += "Content-Type: image/jpeg\r\n";
        //rmsg+="Content-Type: image/gif\r\n";
        // rmsg += "Content-Length: ";

        //char bsize[128]={0};
        //sprintf(bsize,"%d",filesize);

        //rmsg+="10\r\n";
        // rmsg += "11";
        rmsg += "\r\n";
        send(connfd, rmsg.c_str(), rmsg.size(), 0);

        int fd = open("85116637_p0.jpg", O_RDONLY);
        struct stat stat_buf;
        fstat(fd, &stat_buf);
        sendfile(connfd, fd, NULL, stat_buf.st_size);
        // send(connfd, buff, 4096, 0);
        buff[ret] = '\0';

        printf("recv msg from client: %s\n", buff);


        FILE *fp = fopen("text", "w");
        fwrite(buff, ret, 1, fp);
        fclose(fp);
        close(connfd);
        // -------------------------------------------------------------------------------------------------
    }
    return 1;
}

int return_ifn_error(int actual, int error_code, char const *error_msg)
{
    if (actual == error_code)
    {
        printf("%s errer ...\r\n", error_msg);
        exit(0);
    }
    return actual;
}