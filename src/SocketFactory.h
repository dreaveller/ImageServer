#ifndef _SOCKETFACTORY_
#define _SOCKETFACTORY_

#include "TCPConnListener.h"
#include "TCPConn.h"

class SocketFactory
{
private:
    SocketFactory();
    ~SocketFactory();

public:
    static TCPConnListener *newTCPConnListener();
    static TCPConnListener *newTCPConnListener(int port);
    static TCPConn *newTCPConn(int port, sockaddr_in &remoteAddr);
    // static UDP *newUDPServSocket();
    // static UDP *newUDPServSocket(int port);
};

#endif