#include "core.h"

static void setnonblock(int fd)
{
    int opt;
    opt = fcntl(fd, F_GETFD);
    opt |= O_NONBLOCK;
    fcntl(fd, F_SETFD, opt);
}

void* work_thread(void *arg)
{
    (void)arg;                               //arg not use
    pthread_detach(pthread_self());

    set<int>fdset;
    map<int, int>fdpair;

    int epollfd = -1;                       //the argument of epoll_create is unused
    *epollfd = epoll_create(1);             //but must big than zero
    if (*epollfd < 0)
    {
        perror("epoll_create");
        exit(EXIT_FAILURE);
    }

    int accept_disabled = (max_load / 8) - (max_load - fdset.size());

    struct epoll_event ev;
    while(1)
    {
        if (accept_disabled > 0)
        {
            accept_disabled--;
        }
        else if (!pthread_mutex_trylock(&accept_mutex))
        {
            if (!reqs.empty())
            {
                ev.events = EPOLLIN|EPOLLET;
                ev.data.fd = reqs.front();

                setnonblock(reqs.front());
                epoll_ctl(epollfd, EPOLL_CTL_ADD, reqs.front(), &ev);
                fdset.insert(reqs.front());
                fdpair[reqs.front()] = 0;
                reqs.pop();
            }
            pthread_mutex_unlock(&accept_mutex);
            accept_disabled = (max_load / 8) - (max_load - fdset.size());
        }
        if (!fdset.empty())
        {
            conn_manager(fdset, epollfd, fdpair);
        }
    }
    return NULL;
}
