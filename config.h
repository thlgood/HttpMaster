#ifndef CONFIG_H
#define CONFIG_H

#ifndef _CONFIG_FILE_PATH_
#define _CONFIG_FILE_PATH_ "./config.conf"
#endif

/**
 * @brief read config file 'config' file
 * @return -1 for errors
 *          0 for success
 */
int load_config();

#endif // CONFIG_H
