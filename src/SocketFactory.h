#ifndef _SOCKETFACTORY_
#define _SOCKETFACTORY_

#include "TCP.h"
#include "UDP.h"

class SocketFactory
{
private:
    SocketFactory();
    ~SocketFactory();

public:
    static TCP *newTCPServSocket();
    static TCP *newTCPServSocket(int port);
    static UDP *newUDPServSocket();
    static UDP *newUDPServSocket(int port);
};

#endif