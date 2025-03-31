#ifndef URLRESOLVER_H
#define URLRESOLVER_H
#include <iostream>
#include <string>

std::string get_base_url(const std::string&);
std::string get_base_path(const std::string&);
std::string resolve_relative_url(const std::string&, const std::string&);

#endif