#include <curl.h>
#include <easy.h>
#include <errno.h>

#include <http.h>


typedef struct mem_block {
    char* memory;
    size_t size;
} mem_block_t;

static size_t callback(void* contents, size_t size, size_t nmemb, void* data)
{
    size_t content_size = size * nmemb;
    mem_block_t* mem = (mem_block_t*)data;

    char* ptr = (char*)realloc(mem->memory, mem->size + content_size + 1);
    if (ptr == NULL) {
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, content_size);
    mem->size += content_size;
    mem->memory[mem->size] = 0;

    return content_size;
}


int http_get(const char* url, const char* outfile)
{
    FILE* fp;
    CURL* curl;
    CURLcode res;
    char errbuf[CURL_ERROR_SIZE];

    mem_block_t chunk;
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    res = curl_easy_perform(curl);
    if (res) {
        curl_easy_cleanup(curl);
        free(chunk.memory);
        return -1;
    }

    curl_easy_cleanup(curl);

    fp = fopen(outfile, "wb");
    if (NULL == fp) {
        curl_easy_cleanup(curl);
        free(chunk.memory);
        return -1;
    }

    fwrite(chunk.memory, 1, chunk.size, fp);
    fclose(fp);
    free(chunk.memory);

    return 0;
}
