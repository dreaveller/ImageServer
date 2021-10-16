#include <SocketFactory.h>
#include <TCP.h>

TCP *SocketFactory::newTCPServSocket()
{
    return SocketFactory::newTCPServSocket();
}

TCP *SocketFactory::newTCPServSocket(int port)
{
    return new TCP(port);
}

UDP *SocketFactory::newUDPServSocket()
{
    return SocketFactory::newUDPServSocket();
}

UDP *SocketFactory::newUDPServSocket(int port)
{
    return new UDP(port);
}