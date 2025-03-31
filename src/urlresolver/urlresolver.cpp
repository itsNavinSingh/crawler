#include "urlresolver.h"
#include <regex>
#include <vector>
#include <string>
#include <sstream>

std::string get_base_url(const std::string &url) {
    std::regex urlRegex(R"((https?://[^/]+))");
    std::smatch match;

    if (std::regex_search(url, match, urlRegex)) {
        return match[1];
    }
    return url;
}

std::string get_base_path(const std::string &url) {
    size_t lastSlash = url.find_last_of('/');

    if (lastSlash != std::string::npos && url.find("://") == std::string::npos) {
        return url.substr(0, lastSlash + 1);
    }
    return url + "/";
}

std::string resolve_relative_url(const std::string &base_url, const std::string &relative_path) {
    if (relative_path.empty()) return base_url;

    if (relative_path.find("http://") == 0 || relative_path.find("https://") == 0) {
        return relative_path;
    }

    if (relative_path.find("//") == 0) {
        return "https:" + relative_path;
    }

    if (relative_path[0] == '/') {
        return get_base_url(base_url) + relative_path;
    }

    std::string base_path = get_base_path(base_url);

    if (relative_path.find("./") == 0) {
        return base_path + relative_path.substr(2);
    }

    if (relative_path.find("../") == 0) {
        std::vector<std::string> parts;
        std::stringstream ss(base_path);
        std::string segment;

        while (std::getline(ss, segment, '/')) {
            if (!segment.empty()) parts.push_back(segment);
        }

        std::string relative = relative_path;
        while (relative.find("../") == 0 && !parts.empty()) {
            parts.pop_back();
            relative = relative.substr(3);
        }
        std::string new_base_path = "/";
        for (const auto &part: parts) {
            new_base_path += part + "/";
        }
        return get_base_url(base_url) + new_base_path + relative;
    }
    return base_path + relative_path;
}