#include "SocketFactory.h"
#include "TCP.h"
#include <stdio.h>

int main()
{
    try
    {
        TCP *tcpSocket = SocketFactory::newTCPSocket();
        tcpSocket->listen();
        tcpSocket->start();
    }
    catch (int number)
    {
        printf("%d", number);
    }
}