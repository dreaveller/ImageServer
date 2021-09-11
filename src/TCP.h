#ifndef _TCP_
#define _TCP_

#include "ThreadPool.h"

class TCP
{
private:
    int socket = 0;
    int actual_socket = 0;
    static std::ThreadPool executor(4);

public:
    TCP();
    TCP(int port);
    int listen();
    int start();
    ~TCP();
};

#endif