#ifndef FEED_CONN_H
#define FEED_CONN_H

#include "core.h"

/**
 * @brief 为每一个请求发送数据
 * @param fdset 套接字集合
 * @param fdpair key-fd集合，key是套接字，fd是文件描述符
 */
void feed_eve_conn(set<int>&fdset, multimap<int, int>&fdpair);

/**
 * @brief 响应一个新的请求
 * @param fdpair：key-fd集合，key是套接字，fd是文件描述符
 * @param fd：单个文件描述符
 * @return 返回从客户端收到的字节数
 */
int response_new_conn(multimap<int, int>&fdpair, int& fd);

#endif // FEED_CONN_H
