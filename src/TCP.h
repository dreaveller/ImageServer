#ifndef _TCP_
#define _TCP_

class TCP
{
private:
    int socket = 0;
    int actual_socket = 0;
    int port = 8848;
public:
    TCP();
    TCP(int port);
    int listen();
    int accept();
    ~TCP();
};

#endif