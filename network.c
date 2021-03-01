// standard library;
#include <stdio.h>

// curl library
#include <curl/curl.h>

// header file
#include "network.h"


int http_get_example()
{
        CURL *curl;
        CURLcode result;
        char* url = "https://raw.githubusercontent.com/geohot/minikeyvalue/master/tools/kill.sh";

        curl = curl_easy_init();
        if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, url);

                result = curl_easy_perform(curl);

                if (result != CURLE_OK)
                        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                                        curl_easy_strerror(result));

                curl_easy_cleanup(curl);
        }
        return 0;
}
