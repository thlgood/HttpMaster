#ifndef WORK_THREAD_H
#define WORK_THREAD_H

/**
 * @brief it's work thread
 * @param arg is not used
 */
void* work_thread(void*arg);

/**
 * @brief set a block fd/socket to nonblock fd
 * @param fd
 */
static void setnonblock(int fd);
#endif // WORK_THREAD_H
