#include "SocketFactory.h"

TCPConnListener *SocketFactory::newTCPConnListener()
{
    return SocketFactory::newTCPConnListener(8848);
}

TCPConnListener *SocketFactory::newTCPConnListener(int port)
{
    return new TCPConnListener(port);
}

TCPConn *SocketFactory::newTCPConn(int port, sockaddr_in &remoteAddr)
{
    return new TCPConn(port, remoteAddr);
}

// UDP *SocketFactory::newUDPServSocket()
// {
//     return SocketFactory::newUDPServSocket();
// }

// UDP *SocketFactory::newUDPServSocket(int port)
// {
//     return new UDP(port);
// }