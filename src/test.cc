#include "SocketFactory.h"
#include "TCP.h"
#include <stdio.h>

int main()
{
    TCP *tcpSocket;
    try
    {
        tcpSocket = SocketFactory::newTCPServSocket(26413);
        tcpSocket->listen();
        tcpSocket->start();
    }
    catch (int number)
    {
        printf("%d", number);
        delete tcpSocket;
    } 
}