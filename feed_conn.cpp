#include "core.h"

void feed_eve_conn(set<int>&fdset, multimap<int, int>&fdpair)
{
    char buffer[BUFSIZ];
    int length;
    multimap<int, int>::iterator mmap_it = fdpair.begin();
    for(; mmap_it != fdpair.end();)
    {
        length = read((*mmap_it).second, buffer, BUFSIZ);
        if (length < BUFSIZ){
            close((*mmap_it).second);
            fdpair.erase(mmap_it++);    //删除改文件描述符
        }
        if (length = 0){
            ++mmap_it;
            continue;
        }
        length = send((*mmap_it).first, buffer, length, 0);
        if (length <= 0){
            cout << "客户端已经断开连接！" << endl;
            int temp = (*mmap_it).first;
            close(temp);
            fdpair.erase(mmap_it++);
            continue;
        }else{
            ++mmap_it;
        }
    }
}

int response_new_conn(multimap<int, int> &fdpair, int &fd)
{
    char buffer[BUFSIZ];
    int len = -1;
    len = recv(fd, buffer, BUFSIZ, 0);
    if (len <= 0) {
        return -1;
    }
    buffer[len] = '\0';
    httphead hh;
    http_head_parser(&hh, string(buffer));

    if (hh.http_method == httphead::GET)
    {
        fd =
    }
}
