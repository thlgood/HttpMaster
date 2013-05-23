#include "core.h"

template<typename T>
void conn_manager(set<T>&){}

void* work_thread(void *arg)
{
    (void)arg;                               //arg not use
    pthread_detach(pthread_self());

    set<int>fdset;
    int accept_disabled = (max_load / 8) - (max_load - fdset.size());
    while(1)
    {
        if (accept_disabled > 0) {
            accept_disabled--;
        }
        else if (!pthread_mutex_trylock(&accept_mutex))
        {
            if (!reqs.empty()) {
                fdset.insert(reqs.front());
                reqs.pop();
            }
            pthread_mutex_unlock(&accept_mutex);
            accept_disabled = (max_load / 8) - (max_load - fdset.size());
        }
        if (!fdset.empty()) {
            conn_manager(fdset);
        }
    }

    return NULL;
}
