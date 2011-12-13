#include <stdio.h>
#include <stdlib.h>
#include "ghtype.h"
#include "ghstuff.h"

#include "ghgist.h"
#include "ghissue.h"
#include "ghrepo.h"
#include "ghorg.h"

int main(int argc, char *argv[])
{
    hellogh();
    if (argc == 1) {
        helphg();
        exit(0);
    }
   ghin cmdinput;
   cmdinput.area = argv[1];
  printf("%s", cmdinput.area);
  if (strcmp(cmdinput.area, "gist")==0) {
	printf("eh um gist\n");
 } else
  if (strcmp(cmdinput.area, "issue")==0) {
	printf("eh um Issue\n");
 } else
  if (strcmp(cmdinput.area, "repository")==0 || strcmp(cmdinput.area, "repo")==0 ) {
	printf("eh um repository\n");
 } else
  if (strcmp(cmdinput.area, "organization")==0 || strcmp(cmdinput.area, "org")==0 ) {
	printf("eh um Organization\n");
 }
}
