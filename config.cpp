#include "core.h"
#include "config.h"

int load_config()
{
/*    extern int    port;             //default 8080
    extern int    thread_count;     //default 1
    extern int    max_load;         //max load per thread, default 1000
    extern string docpath;          //website root
    extern string indexfile;        //default "index.htm"*/

    char     *str;
    GKeyFile *key_file = g_key_file_new();
    GError   *g_error = NULL;

    g_key_file_load_from_file(key_file, _CONFIG_FILE_PATH_, GKeyFileFlags(0), &g_error);
    if (g_error)
    {
        std::cerr << __FUNCTION__ << __LINE__ << g_error->message;
        g_key_file_free(key_file);
        g_error_free(g_error);
        return -1;
    }

    //docpath
    str = g_key_file_get_string(key_file, "options", "docpath", &g_error);
    if (str != NULL)
        docpath = str;
    else
    {
        std::cerr << __FUNCTION__ << __LINE__ << g_error->message;
        g_key_file_free(key_file);
        g_error_free(g_error);
        return -1;
    }

    //indexfile
    str = g_key_file_get_string(key_file, "options", "indexfile", &g_error);
    if (str != NULL)
        indexfile = str;
    else
    {
        std::cerr << __FUNCTION__ << __LINE__ << g_error->message;
        g_key_file_free(key_file);
        g_error_free(g_error);
        return -1;
    }

    //thread
    thread_count = g_key_file_get_integer(key_file, "options", "thread-count", NULL);
    if (!thread_count)
        thread_count = 1;

    //port
    port = g_key_file_get_integer(key_file, "options", "port", NULL);
    if (!port)
        port = 8080;

    //max_load
    max_load = g_key_file_get_integer(key_file, "options", "max-load", NULL);
    if (!max_load)
        port = 1000;

    g_key_file_free(key_file);

    return 0;
}

