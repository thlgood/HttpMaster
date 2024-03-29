#ifndef CORE_H
#define CORE_H
using namespace std;
/**
 * @brief Network headers
 */
#include <sys/socket.h>
#include <arpa/inet.h>

/**
 * @brief C header & UNIX header
 */
#include <cstdio>
#include <cstring>
#include <glib.h>
#include <linux/limits.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <cstdlib>-

/**
 * @brief C++ headers
 */
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <map>

/**
 * @brief HttpMaster header
 *
 */
#include "config.h"
#include "setuptcp.h"
#include "work_thread.h"
#include "conn_manager.h"
#include "feed_conn.h"
#include "http_head.h"
/**
 * @brief Macros
 */
#define C_STRING(a) (char*)(a)  //disable char* to string cast


/**
 *
 * @brief default settings
 */
extern int    port;             //port
extern int    thread_count;     //default 4
extern int    max_load;         //max load per thread
extern string docpath;          //website root
extern string indexfile;        //default "index.htm"
extern pthread_mutex_t accept_mutex;
extern queue<int> reqs;         //requset queue;

#endif // CORE_H
