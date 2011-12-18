#include "curl/curl.h"
#include "ghtype.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ghcurl.h"


 
/*Curl uses this function to write the contents of a webpage to a file/stdout*/
size_t write_data( void *ptr, size_t size, size_t nmeb, void *stream)
{
 data *curl_output = (data *)stream;
 int curl_output_size = size * nmeb;
 
 curl_output->contents = (char *) realloc(curl_output->contents, curl_output->size + curl_output_size + 1);
 if (curl_output->contents) {
 memcpy(curl_output->contents, ptr, curl_output_size); /*Copying the contents*/
 curl_output->size += curl_output_size;
 curl_output->contents[curl_output->size] = 0;
 }
}

ghout ghExecute(int method, ghin info)
{
    data webpage;
    ghout out;
    webpage.contents = malloc(1);
    webpage.size = 1;
    printf("Buscando Dados...\n\n");
    CURL *handle = curl_easy_init();
    curl_easy_setopt(handle,CURLOPT_URL, info.url);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(handle,CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(handle,CURLOPT_WRITEDATA, &webpage);
    curl_easy_perform(handle);
    curl_easy_cleanup(handle);
    out.content = malloc(sizeof(webpage.contents));
    out.content = webpage.contents;
    return out;
}
ghout ghPost(ghin info)
{
    return ghExecute(get, info);
}
ghout ghHead(ghin info)
{
    
}
ghout ghget(ghin info)
{
    
}
ghout ghPath(ghin info)
{
    
}
ghout ghPut(ghin info)
{
    
}
ghout ghDelete(ghin info)
{
    
}
