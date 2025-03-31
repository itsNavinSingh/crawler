#include "htmlparser.h"
#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>
#include "urlresolver/urlresolver.h"

std::vector<std::string> extract_links(const std::string &htmlContent, const std::string &base_url)
{
    std::vector<std::string> links;
    htmlDocPtr doc = htmlReadMemory(htmlContent.c_str(), htmlContent.size(), NULL, NULL, HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);

    if (!doc)
    {
        return links;
    }

    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    xmlXPathObjectPtr result = xmlXPathEvalExpression((xmlChar *)"//a[@href]", context);

    if (result && result->nodesetval)
    {
        for (int i = 0; i < result->nodesetval->nodeNr; ++i)
        {
            xmlNodePtr node = result->nodesetval->nodeTab[i];
            xmlChar *href = xmlGetProp(node, (xmlChar *)"href");

            if (href)
            {
                std::string abs_url = resolve_relative_url(base_url, (char *)href);
                links.push_back(abs_url);
                xmlFree(href);
            }
        }
    }
    xmlXPathFreeObject(result);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);
    return links;
}