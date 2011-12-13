#include <stdio.h>
void hellogh()
{
    printf("GitHubIt 0.1 by Ivo Nascimento\n");
    printf("\tCommand Line tool for gitHub.\n");
}
void helphg()
{
    printf("usage: githubit [ type ] [ command ] [ parameter ]\n");
    printf("type: [ help | gist | issue | organization | repository ]\n");
    printf("command:\n");
    printf("gist:\t\t\t [ help | create | list ]\n");
    printf("issue:\t\t\t [ help | create | list ]\n");
    printf("organization(org):\t [ help | create | list ]\n");
    printf("repository(repo):\t [ help | create | list ]\n");
}
