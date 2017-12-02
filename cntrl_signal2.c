#include <signal.h>#include <stdio.h>#include <stdlib.h>
void cntrl_signal(int sig){char c;printf("Get Interrupt Signal.\n");printf("Do you want to exit myMOVIE program? (y/n)");char *c = (char*)malloc(sizeof(char*)*10);gets(c);while(1){  if(strcmp(c,"n") == 0 ||  strcmp(c,"N") == 0)  {
  }  else if(strcmp(c,"y") == 0 || strcmp(c,"Y") == 0)  {    exit(1);  }  else  {    printf("Wrong answer. Put again. ");    gets(c);  }}
