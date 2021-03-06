#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include "Action.h"

char* exampleResponse()
{
    char *buf = "example";
    return buf;
}

int sendRandomImage(int connFd)
{
    char buff[4096];
    // example
    // string head = hTTPResponse.deserilize();
    char* head = "HTTP/1.1 200 OK\r\nServer: XHttp\r\nContent-Type: image/jpeg\r\n\r\n";
    send(connFd, head, strlen(head), 0);
    int fd = open("../resource/85116637_p0.jpg", O_RDONLY);
    struct stat stat_buf;
    fstat(fd, &stat_buf);
    sendfile(connFd, fd, NULL, stat_buf.st_size);
    close(connFd);
    close(fd);
    return 1;
}