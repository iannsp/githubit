#include <stdio.h>
#include <stdlib.h>
#include "ghtype.h"
#include "ghstuff.h"
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
    ghParam* ghParam = NULL;
    if ( (argc -1) % 2 ==0 ){
        for(i; i< argc; i+=2) {
            if (ghParam == NULL) {
                ghParam = create_ghParam( *(argv+i), *(argv+i+1) );
            }else {
                ghParam->next = create_ghParam( *(argv+1), *(argv+2) );
            }
        }
    }
    return ghParam;
}
ghParam* create_ghParam(char* name, char* value)
{
    ghParam* newghParam = malloc(sizeof(name)+sizeof(value));
    if (newghParam != NULL){
        newghParam->name    = name;
        newghParam->value   = value;
        newghParam->next    = NULL;
    }
    return newghParam;
}
