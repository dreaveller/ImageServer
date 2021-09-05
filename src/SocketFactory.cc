#include <SocketFactory.h>
#include <TCP.h>

static TCP SocketFactory::newTCPSocket()
{
    return SocketFactory::newTCPServSocket(8080);
}

static TCP SocketFactory::newTCPSocket(int port)
{
    return new TCP(port);
}

static UDP SocketFactory::newUDPServSocket(int port)
{
    
}