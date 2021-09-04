class TCP
{
private:
    int socket = 0;
    int actual_socket = 0;
    
public:
    TCP();
    TCP(int port);
    int listen();
    int start();
    ~TCP();
};