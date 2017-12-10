#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void cntrl_signal(int sig){ // ctrl^z 를 받으면 실행
printf("Get Interrupt Signal.\n");
printf("Do you want to exit myMOVIE program? (y/n)");
char c ;

c = getchar();
if(c=='y'||c=='Y') // y거나 Y면 종료
  exit(1);

}
