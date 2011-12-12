#include <stdio.h>
#include <stdlib.h>
#include "ghtype.h"
#include "ghstuff.c"
int main(int argc, char *argv[])
{
    hellogh();
/*    printf("%d", argc); */
    if (argc == 1) {
        helphg();
        exit(0);
    }
    
}