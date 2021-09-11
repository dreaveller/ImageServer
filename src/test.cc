#include "SocketFactory.h"
#include "TCP.h"
#include <stdio.h>
#include "ThreadPool.h"
#include "Action.h"

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
    //     tcpSocket->start();
    // }
    // catch (int number)
    // {
    //     printf("%d", number);
    //     delete tcpSocket;
    // } 

    std::ThreadPool executor(4);
    executor.commit(add, 2, 1);
    executor.commit(sub, 2, 1);

    printf("%s", exampleResponse());
}