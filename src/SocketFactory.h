#include "TCP.h"

class SocketFactory
{
private:
    SocketFactory(/* args */);
    ~SocketFactory();
public:
    static TCP newTCPServSocket();
    static TCP newTCPServSocket(int port);
    static UDP newUDPServSocket(int port);
};