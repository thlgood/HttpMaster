#include "core.h"
#include <sstream>

int http_head_parser(httphead* hh, const string& ptr)
{
    stringstream ss(ptr);
    string temp;

    ss >> temp;
    if(temp == string("GET")) {
        hh->http_method = httphead::GET;
    } else if(temp == string("HEAD")) {
        hh->http_method = httphead::HEAD;
    } else {
        hh->http_method = httphead::UNKNOW;
        return 0;
    }

    ss >> hh->URI;
    ss >> temp;
    if(temp == string("HTTP/1.1")) {
        hh->http_version = httphead::HTTP1_1;
    } else { //if temp == http/1.0 or others
        hh->http_version = httphead::HTTP1_0;
        hh->iskeepalive = false;
        return 1;
    }

    hh->iskeepalive = true;                     //默认设置keep-alive
    while (ss >> temp && string("Connection:") != temp){
        NULL;
    }
    if (string("Connection:") == temp) {
        ss >> temp;
        if (temp != string("keep-alive")) {
            hh->iskeepalive = false;
        }
    }
    return 2;
}
