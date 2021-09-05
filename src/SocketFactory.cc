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

UDP *SocketFactory::newUDPServSocket(int port)
{
}