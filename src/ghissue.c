#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ghtype.h"
#include "ghcurl.h"
#include "ghstuff.h"
#include "ghissue.h"
#include <jansson.h>
#include "ghjson.h"
 
int    ghIssue(ghin param)
{
    if ( strcmp(param.command,"add")==0) {
        ghissue_add(param);
    }
    else
    if ( strcmp(param.command,"show")==0) {
        ghissue_show(param);
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
ghout   ghissue_show(ghin param)
{
    ghout out;
    size_t i;
    const char *title, *body, *state, *milestone, *createdate,*html;
    int id;
    json_t *json;
    json_t  *item;

    char *user = getParamValue(param.param, "user");
    char *repo = getParamValue(param.param, "repo");
    char *issueid = getParamValue(param.param, "id");

    if (!user | !repo | !issueid){
        printf("Precisa informar o usuario(user), repositorio(repo) e o id da issue.\n");
        ghissue_help();
        exit(EXIT_FAILURE);
    }
    //https://api.github.com/repos/iannsp/BlueSeed/issues/16
    param.url = malloc(sizeof(GHURL)+sizeof("/repos///issues/0000")+sizeof(user)+sizeof(repo)+3);
    sprintf(param.url, "%srepos/%s/%s/issues/%s", GHURL,user,repo, issueid );
    out = ghExecute(get, param);
    ghstringparse(&out);
        item = out.json;
        if(!json_is_object(item))
        {
            printf("Problemas com os dados.\n");
            exit(EXIT_FAILURE);
        }
        title       = json_string_value(getValueOf(item, "title"));
        body        = json_string_value(getValueOf(item, "body"));
        id          = json_integer_value(getValueOf(item, "number"));
        state       = json_string_value(getValueOf(item, "state"));
        html        = json_string_value(getValueOf(item, "html_url"));
        milestone   = (json_is_null(getValueOf(item, "milestone"))==1)?"-":json_string_value(getValueOf(item, "milestone"));
        createdate  = json_string_value(getValueOf(item, "created_at"));
        printf("%4d-%-90s\n     url: %s\n     status: %s\n     created at: %s\n     milestone: %s\n     content: %s\n",
        id, title, html, state, createdate,milestone, body); 
    return out;    
}
ghout   ghissue_list(ghin param)
{
    ghout out;
    size_t i;
    const char *title, *body, *state;
    int id;
    json_t *json;
    json_t  *item;

    char *user = getParamValue(param.param, "user");
    char *repo = getParamValue(param.param, "repo");

    if (!user | !repo){
        printf("problemas ao requisitar a lista de issues.\n");
        ghissue_help();
        exit(EXIT_FAILURE);
    }
    param.url = malloc(sizeof(GHURL)+sizeof("repos/?sort=created&direction=asc")+sizeof(user)+sizeof(repo)+3);
    sprintf(param.url, "%srepos/%s/%s/issues?sort=created&direction=asc", GHURL,user,repo );
    out = ghExecute(get, param);
    ghstringparse(&out);
    for(i = 0; i < json_array_size(out.json); i++)
    {
        item = json_array_get(out.json, i);
        if(!json_is_object(item))
        {
            printf("Problemas com os dados.\n");
            exit(EXIT_FAILURE);
        }
        title       = json_string_value(getValueOf(item, "title"));
        body        = json_string_value(getValueOf(item, "body"));
        id          = json_integer_value(getValueOf(item, "number"));
        state       = json_string_value(getValueOf(item, "state"));
        printf("%4d-%-90s (%s)\n",id, title, state); 
    }
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