#include "SocketFactory.h"
#include <stdio.h>
#include <spdlog/spdlog.h>
#include "TCPConnListener.h"
#include "TCPConn.h"

#include "Socket.h"

int main()
{
    spdlog::info("create socket with port 8848.");
    // TCPConnListener *listener = SocketFactory::newTCPConnListener(8848);
    // listener->listen();
    // TCPConn * conn = listener->accept();
    // conn->recv();
    // conn->send();

    // delete listener;
    // delete conn;

    ServerSocket server(8848);
    server.listen();
    Socket *s = server.accept();
    s->recv();
    s->send();



    // std::ThreadPool executor(4);
    // executor.commit(add, 2, 1);
    // executor.commit(sub, 2, 1);

    // printf("%s", exampleResponse());
}