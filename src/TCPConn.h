#ifndef _TCPCONN_
#define _TCPCONN_

class TCPConn
{
private:
    int socket;
    int port;
public:
    TCPConn(int port)
    ~TCPConn();
    int recv();
    int send();
    int close();
};

#endif