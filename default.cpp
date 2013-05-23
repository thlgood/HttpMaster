/**
 * @brief default settings
 *
 */
#include "core.h"


int    port = 8000;
int    thread_count = 1;
int    max_load = 1000;
string docpath = "/var/www/";
string indexfile = "index.html";
pthread_mutex_t accept_mutex = PTHREAD_MUTEX_INITIALIZER;
queue<int>reqs;
