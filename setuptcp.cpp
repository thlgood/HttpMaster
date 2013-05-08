#include "core.h"

int setup_tcp()
{
    extern int port;
    sockaddr_in server_addr;
    in_port_t server_port = (in_port_t)port;
    int sock;
    int retval;
    int sockopt = 1;

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0)
    {
        perror("socket");
        return sock;
    }
    if ((retval = setsockopt(sock, SOL_SOCKET,
                             SO_REUSEADDR, &sockopt, sizeof(int))) < 0)
    {
        perror("setsockopt");
        return retval;
    }

    //Bind
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port        = htons(server_port);
    server_addr.sin_family      = AF_INET;
    retval = bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (retval < 0)
    {
       perror("bind");
       return retval;
    }


    //Listen
    retval = listen(sock, 40);
    if (retval < 0)
    {
        perror("listen");
        return retval;
    }

    return sock;
}

