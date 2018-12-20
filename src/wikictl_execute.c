#include <wikictl.h>
#include <curl/curl.h>
#include <wikictl_execute.h>
#include <wikictl_help.h>
#include <wikictl_utilities.h>

int execute(parameters_t *params)
{
    CURL *curl;
    CURLcode res;

    if(1 == params->show_help){
        show_help();
        return 0;
    }

    if(1 == params->show_version){
        show_version();
        return 0;
    }

    if(RESET == params->operation){
        sprintf(params->endpoint, "/reset/%s", params->key);
        update_http_request(params);
    } else if(ACCENDI == params->operation){
        sprintf(params->endpoint, "/on/%s/%d", params->key, params->position);
        update_http_request(params);
    } else if(SPEGNI == params->operation){
        sprintf(params->endpoint, "/off/%s/%d", params->key, params->position);
        update_http_request(params);
    } else if(APRI == params->operation){
        sprintf(params->endpoint, "/openclose/%s/%d", params->key, params->position);
        update_http_request(params);
    } else if(CHIUDI == params->operation){
        sprintf(params->endpoint, "/openclose/%s/%d", params->key, params->position);
        update_http_request(params);
    } else if(STATUS == params->operation){
        sprintf(params->endpoint, "/status/%s", params->key);
        update_http_request(params);
    } else if(NONE == params->operation){
        return 1;
    }

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, params->http_request);
        /* example.com is redirected, so we tell libcurl to follow redirection */ 
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /* Perform the request, res will get the return code */ 
        res = curl_easy_perform(curl);
        /* Check for errors */ 
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */ 
        curl_easy_cleanup(curl);
    }
    return 0;
}