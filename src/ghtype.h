// the ghtype file have the input and output structures used by githubit to transport data.


#define GHURL "https://api.github.com/"
typedef struct{
    char* name;
    char* value;
    struct ghParam* next;
    } ghParam;
typedef struct {
    char* area ;
    char* command;
    ghParam* param  ;
    } ghin;

typedef struct{
    
    } ghout;
typedef enum{
    head,
    get,
    post,
    path,
    put,
    delete
    }HMETHOD;
