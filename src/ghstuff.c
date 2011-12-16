#include <stdio.h>
#include <stdlib.h>
#include "ghtype.h"
#include "ghstuff.h"
#include "ghcurl.h"

#include "ghgist.h"
#include "ghissue.h"
#include "ghrepo.h"
#include "ghorg.h"
#include <string.h>

void hellogh()
{
    printf("GitHubIt 0.1 by Ivo Nascimento\n");
    printf("\tCommand Line tool for gitHub.\n");
}
void helphg()
{
    printf("usage: githubit [ type ] [ command ] [ parameter ]\n");
    printf("type: [ help | gist | issue | organization | repository ]\n");
}

ghParam* ghcreateParam(int argc, char* argv[]){
    int i=3;//(0=cmd;1=type;2=command)
    ghParam *ghparam,*p = NULL;
    if ( (argc -1) % 2 ==0 ){
        for(i; i< argc; i+=2) {
            ghparam = create_ghParam( *(argv+i), *(argv+i+1) );
            ghparam->next = p;
            p = ghparam;
            }
        }
    ghparam = p;
    return ghparam;
}
char* getParamValue(ghParam *param, char *name)
{
    ghParam* p;
    p = param;
    while(p) {
        if (strcmp(p->name, name)==0) {
            return p->value;
        }
        p = p->next;
    }
    return NULL;
}
ghParam* create_ghParam(char* name, char* value)
{
    ghParam* newghParam = malloc(sizeof(name)+sizeof(value)+2);
    if (newghParam != NULL){
        newghParam->name    = name;
        newghParam->value   = value;
    }
    return newghParam;
}
