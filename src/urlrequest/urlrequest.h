#ifndef URLREQUEST_H
#define URLRQUEST_H
#include <iostream>
#include <string>

size_t WriteCallback(void*, size_t, size_t, std::string*);
std::string fetchHTMLContent(const std::string&);

#endif