#include "urlrequest.h"
#include <iostream>
#include <curl/curl.h>
#include <string>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t totalSize = size * nmemb;
    output->append((char *)contents, totalSize);
    return totalSize;
}

std::string fetchHTMLContent(const std::string &url) {
    CURL *curl;
    CURLcode res;
    std::string response;
    
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cout << "Failed to fetch " << url << ": " << curl_easy_strerror(res) << std::endl;
            return "";
        }
        curl_easy_cleanup(curl);
        return response;
    }
}