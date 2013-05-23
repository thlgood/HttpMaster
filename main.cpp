#include "core.h"


int main()
{
    int fd;
    int sock = setup_tcp();
    struct sockaddr_in sock_addr;
    socklen_t len = sizeof(sock_addr);
    load_config();

    for(int i = 0; i < thread_count; i++)
    {
        pthread_t pthread;
        pthread_create(&pthread, NULL, work_thread, NULL);
    }
    while (1)
    {
        fd = accept(sock, (struct sockaddr*)&sock_addr, &len);
        pthread_mutex_lock(&accept_mutex);
        reqs.push(fd);
        pthread_mutex_unlock(&accept_mutex);
    }
    return 0;
}
