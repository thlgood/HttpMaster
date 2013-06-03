#ifndef HTTP_HEAD_H
#define HTTP_HEAD_H
#include "core.h"

struct httphead
{
    enum {GET, POST, PUT,       //请求类型
          HEAD, UNKNOW
         }http_method;
    enum {HTTP1_0, HTTP1_1      //http协议版本
         }http_version;
    enum {SC200, SC404, SC403,  //SC：状态码(Status Code)
          SC500
         }status_code;
    string URI;                 //URI
    bool iskeepalive;           //是否保持keep-alive
    string datetime;            //时间和日期
};


/**
 * @brief http请求头部分析
 * @param hh httphead 指针
 * @param ptr 待分析的C字符串
 * @return 小于0表示输入的参数有误
 */
int http_head_parser(httphead* hh, const string& ptr);

#endif // HTTP_HEAD_H
