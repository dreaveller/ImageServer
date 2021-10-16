#ifndef _SOCKETFACTORY_
#define _SOCKETFACTORY_

#include "TCP.h"
#include "UDP.h"
#include "TcpConnectionListener.h"
#include "TCPConn.h"

class SocketFactory
{
private:
    SocketFactory();
    ~SocketFactory();

public:
    static TCPConnListener *newTCPConnListener();
    static TCPConnListener *newTCPConnListener(int port);
    static TCPConn *newTCPConn(int port);
    static UDP *newUDPServSocket();
    static UDP *newUDPServSocket(int port);
};

#endif