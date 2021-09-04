#include <SocketFactory.h>
#include <TCP.h>

static SocketFactory::newTCPSocket()
{
    return SocketFactory::newTCPServSocket(8080);
}

static SocketFactory::newTCPSocket(int port)
{
    return new TCP(port);
}

static SocketFactory::newUDPServSocket(int port)
{
    
}