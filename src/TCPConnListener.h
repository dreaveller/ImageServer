#ifndef _TCPCONNLISTENER_
#define _TCPCONNLISTENER_

#include "TCPConn.h"

class TCPConnListener
{
private:
    int socket = 0;
    int actual_socket = 0;
    int port = 8848;
public:
    TCPConnListener();
    TCPConnListener(int port);
    ~TCPConnListener();
    int listen();
    TCPConn * accept();
};

#endif