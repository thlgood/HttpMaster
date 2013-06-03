#ifndef CONN_MANAGER_H
#define CONN_MANAGER_H
#include "core.h"
/**
 * @brief conn_manager connections manager!
 * @param fdset file descriptors set
 */
void conn_manager(set<int>&fdset, int&, multimap<int, int>&);

#endif // CONN_MANAGER_H
