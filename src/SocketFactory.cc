#include <SocketFactory.h>
#include <TCP.h>

TCPConnListener *SocketFactory::newTCPConnListener()
{
    return SocketFactory::newTCPConnListener(8848);
}

TCPConnListener *SocketFactory::newTCPConnListener(int port)
{
    return new TCPConnListener(port);
}

TCPConn *SocketFactory::newTCPConn(int port)
{
    return new TCPConn(port);
}

UDP *SocketFactory::newUDPServSocket()
{
    return SocketFactory::newUDPServSocket();
}

UDP *SocketFactory::newUDPServSocket(int port)
{
    return new UDP(port);
}