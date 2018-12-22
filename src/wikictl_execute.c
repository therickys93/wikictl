#include <wikictl.h>
#include <curl/curl.h>
#include <string.h>
#include <wikictl_execute.h>
#include <wikictl_help.h>
#include <wikictl_utilities.h>

int execute(parameters_t *params)
{
    CURL *curl;
    CURLcode res;
    FILE *downloadFile;
    char downloadFilename[100] = "wiki.json";
    char uploadFilename[100]   = "wiki.json";
    char content[4096]         = "";

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
    } else if(DOWNLOAD == params->operation){
        sprintf(params->endpoint, "/download");
        update_http_request(params);
    } else if(UPLOAD == params->operation){
        sprintf(params->endpoint, "/upload");
        update_http_request(params);
    } else if(HOME == params->operation){
        strcpy(params->endpoint, "/");
        update_http_request(params);
    } else if(NONE == params->operation){
        printf("Nessuna operazione specificata\n");
        return 1;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, params->http_request);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        if(DOWNLOAD == params->operation){
            downloadFile = fopen(downloadFilename, "wb");
            if(downloadFile) {
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, downloadFile);
            }
        } else if(UPLOAD == params->operation){
            int rc = read_content_of_file(uploadFilename, content);
            if(0 == rc){
                struct curl_slist *headers = NULL;
                headers = curl_slist_append(headers, "Accept: application/json");
                headers = curl_slist_append(headers, "Content-Type: application/json");
                headers = curl_slist_append(headers, "charsets: utf-8");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, content);
            } else {
                printf("Errore nella lettura del file");
                return 3;
            }
        }
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        if(DOWNLOAD == params->operation){
            fclose(downloadFile);
        }
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    } else {
        printf("Errore di connessione\n");
        return 2;
    }
    return 0;
}