#include "SocketFactory.h"
#include <stdio.h>
#include "TCPConnListener.h"
#include "TCPConn.h"

int main()
{
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