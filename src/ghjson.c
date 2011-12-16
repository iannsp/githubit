#include <stdlib.h>
#include <string.h>
#include "ghtype.h"
#include "ghcurl.h"
#include "ghstuff.h"
#include <jansson.h>

void ghstringparse(ghout *out)
{
    json_t *root;
    json_error_t error;
    root = json_loads(out->content, 0, &error);
    out->json = malloc(sizeof(root));
    out->json = root;
}

json_t* getJsonItensbyName(ghout *out, char *nodename)
{
    json_t *itens;
    json_error_t error;
    itens = json_object_get(out->json, nodename);
    if(!json_is_array(itens))
    {
        return NULL;
    }
    return itens;
}

json_t* getValueOf(json_t *json, char* name)
{
    json_t *item;
    item = json;
            item = json_object_get(item, name);
            return item;
            
}