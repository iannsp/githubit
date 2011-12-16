// the ghtype file have the input and output structures used by githubit to transport data.
#include <jansson.h>

#define GHURL "https://api.github.com/"

typedef struct {
 char *contents;
 int size;
} data;

typedef struct ghParam ghParam;

struct ghParam{
    char* name;
    char* value;
    ghParam* next;
    };
typedef struct {
    char *area ;
    char *command;
    ghParam *param  ;
    char *url;
    } ghin;

typedef struct{
    char *content;
    char *url;
    json_t *json;
    } ghout;
    
typedef enum{
    head,
    get,
    post,
    path,
    put,
    delete
    }HMETHOD;
