#include "core.h"

void conn_manager(set<int>& fdset, int& epollfd, multimap<int, int>& fdpair)
{
    struct epoll_event *events;

    //epoll wait
    int ndfs = epoll_wait(epollfd, events, max_load, 0);
    int retval;
    for(int i = 0; i < ndfs; i++)
    {
        if (events[i].events & EPOLLIN)
        {
            retval = response_new_conn(fdpair, events[i].data.fd);
            if (retval < 0)
            {
                struct epoll_event ev;              //protect kernel BUG
                epoll_ctl(epollfd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
                fdset.erase(events[i].data.fd);     //
                fdpair.erase(events[i].data.fd);    //Remove from fdpair
                close(events[i].data.fd);
            }
        }
    }

    //feed every connections
    feed_eve_conn(fdset, fdpair);
}
