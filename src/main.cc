#include "SocketFactory.h"
#include <stdio.h>
#include "TCPConnListener.h"
#include "TCPConn.h"

void add(int a, int b)
{
    for (int i = 0; i < 200; i++)
    {
        printf("%d", a + b);
    }
}

void sub(int a, int b)
{
    for (int i = 0; i < 200; i++)
    {
        printf("%d", a - b);
    }
}

int main()
{
    // TCP *tcpSocket;
    // try
    // {
    //     tcpSocket = SocketFactory::newTCPServSocket(26413);
    //     tcpSocket->listen();
    //     tcpSocket->accept();
    // }
    // catch (int number)
    // {
    //     printf("%d", number);
    //     delete tcpSocket;
    // } 

    TCPConnListener *listener = SocketFactory::newTCPConnListener(8848);
    listener->listen();
    TCPConn * conn = listener->accept();
    conn->recv();
    conn->send();

    delete listener;
    delete conn;

    // std::ThreadPool executor(4);
    // executor.commit(add, 2, 1);
    // executor.commit(sub, 2, 1);

    // printf("%s", exampleResponse());
}