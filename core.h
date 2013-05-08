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

/**
 * @brief C++ headers
 */
#include <iostream>
#include <string>

/**
 * @brief HttpMaster header
 *
 */
#include "config.h"
#include "setuptcp.h"

/**
 * @brief Macros
 */
#define C_STRING(a) (char*)(a)          //disable char* to string cast


/**
 *
 * @brief default settings
 */
extern int    port;             //port
extern int    thread_count;     //default 4
extern int    max_load;         //max load per thread
extern string docpath;          //website root
extern string indexfile;        //default "index.htm"

#endif // CORE_H
