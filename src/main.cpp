#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include "urlrequest/urlrequest.h"
#include "htmlparser/htmlparser.h"
int main(int argc, char **argv)
{
    std::queue<std::string> next;
    std::unordered_set<std::string> done;
    for (int i=1; i<argc; ++i) {
        next.push(argv[i]);
    }

    if(argc == 1) {
        next.push("https://en.wikipedia.org/wiki/Web_crawler");
    }

    int count = 0;

    while (!next.empty())
    {
        if(done.find(next.front()) == done.end()){
            
            done.insert(next.front());

            std::cout << count << ". " << next.front() << "\n";
            std::string htmlcontent = fetchHTMLContent(next.front());
            std::vector<std::string> links = extract_links(htmlcontent, next.front());
            for (int i=0; i<links.size(); ++i) {
                if (done.find(links[i]) == done.end()) {
                    next.push(links[i]);
                }
            }
            ++count;
        }
        next.pop();
    }
    return 0;
}