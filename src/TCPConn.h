#ifndef _TCPCONN_
#define _TCPCONN_

#include <netinet/in.h>

class TCPConn
{
private:
    int socket;
    int port;
    sockaddr_in remoteAddr;
public:
    TCPConn(int socket, sockaddr_in &remoteAddr);
    ~TCPConn();
    int recv();
    int send();
    int close();
};

#endif