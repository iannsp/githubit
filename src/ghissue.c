#include <stdio.h>
#include <stdlib.h>
#include <json/json.h>
#include <string.h>
#include "ghtype.h"
#include "ghcurl.h"
#include "ghstuff.h"
#include "ghissue.h"

int    ghIssue(ghin param)
{
    if ( strcmp(param.command,"add")==0) {
        ghissue_add(param);
    }
    else
    if ( strcmp(param.command,"list")==0) {
        ghissue_list(param);
    }
    else
    if ( strcmp(param.command,"edit")==0) {
        ghissue_edit(param);
    }
    else
    if ( strcmp(param.command,"mylist")==0) {
        ghissue_mylist(param);
    }
    else {
        ghissue_help();
    }
    return 1;
}
ghout   ghissue_list(ghin param)
{
    ghout out;
    char *user = getParamValue(param.param, "user");
    char *repo = getParamValue(param.param, "repo");

    if (!user | !repo){
        printf("problemas ao requisitar a lista de issues.\n");
        ghissue_help();
        exit(EXIT_FAILURE);
    }
    param.url = malloc(sizeof(GHURL)+sizeof("repos/")+sizeof(user)+sizeof(repo)+3);
    sprintf(param.url, "%srepos/%s/%s/issues", GHURL,user,repo );
    out = ghExecute(get, param);
    printf("%s\n", out.content);
    return out;
}
ghout   ghissue_mylist(ghin param)
{
    param.url = malloc(sizeof(GHURL));
    param.url = GHURL;
//    return ghExcute(get, param);
    
}
ghout   ghissue_add(ghin param)
{
    param.url = malloc(sizeof(GHURL));
    param.url = GHURL;
//    return ghExcute(get, param);
    
}
ghout   ghissue_edit(ghin param)
{
    param.url = malloc(sizeof(GHURL));
    param.url = GHURL;
//    return ghExcute(get, param);
}
void ghissue_help()
{
    printf("help de Issue.\n");
    
}