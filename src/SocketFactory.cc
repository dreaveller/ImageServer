#include <SocketFactory.h>
#include <TCP.h>

TCP *SocketFactory::newTCPServSocket()
{
    return SocketFactory::newTCPServSocket(8080);
}

TCP *SocketFactory::newTCPServSocket(int port)
{
    return new TCP(port);
}

UDP *SocketFactory::newUDPServSocket()
{
    return SocketFactory::newUDPServSocket(8080);
}

UDP *SocketFactory::newUDPServSocket(int port)
{
    return new UDP(port);
}