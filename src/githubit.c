#include <stdio.h>
#include <stdlib.h>
#include "ghtype.h"
#include "ghcurl.h"
#include "ghstuff.h"
#include "ghgist.h"
#include "ghissue.h"
#include "ghrepo.h"
#include "ghorg.h"

int main(int argc, char* argv[])
{
    hellogh();
    if (argc == 1) {
        helphg();
        exit(EXIT_FAILURE);
    }
   ghin cmdinput;
   cmdinput.area = argv[1];
   cmdinput.command = (argc >=3 )?argv[2]:"help";
   cmdinput.param = ghcreateParam(argc, argv);

  if (strcmp(cmdinput.area, "gist")==0) {
      printf("em desenvolvimento.\n");
 } else
  if (strcmp(cmdinput.area, "issue")==0) {
      ghIssue(cmdinput);
 }
  else
  if (strcmp(cmdinput.area, "repository")==0 || strcmp(cmdinput.area, "repo")==0 ) {
      printf("em desenvolvimento.\n");
 } else
  if (strcmp(cmdinput.area, "organization")==0 || strcmp(cmdinput.area, "org")==0 ) {
      printf("em desenvolvimento.\n");
 }
}
/*
ghParam* p;
p = cmdinput.param;
while(p) {
    printf("\n:%s - %s\n",p->name,p->value);
    p = p->next;
}

*/