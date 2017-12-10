#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "movie_manage_program.h"

void m_write(movie * M_L)
{
  time_t tm_time;
  struct tm *st_time;
  char * now_time = (char*)malloc(20);
  char * str = (char *)malloc(40);
  to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
  tmp->actor = NULL;
  tmp->next=NULL;

  time(&tm_time);
  st_time = localtime(&tm_time);
  strftime(now_time,1204,"%Y%m%d%H%M",st_time);
  strcpy(str,"movie_list.");
  strcat(str,now_time); //movie_list.시간 파일이름 생성

  if(access("movie_list",F_OK)==0) //movie_list 파일이 있는지 확인
  {
    FILE * input = fopen("movie_list","r");
    FILE * des = fopen(str,"w");
    char ch;
    while((ch=fgetc(input))!=EOF)
      fputc(ch,des);

    fclose(input);
    fclose(des);
  } //movie_list를 movie_list.시간 파일에 복사

  FILE * fp= fopen("movie_list","w");
  while(M_L!=NULL)
  {
    to_actor * tmp = (to_actor*)malloc(sizeof(to_actor));
    tmp = M_L->m_data.actors;
    fprintf(fp,"%d",M_L->m_data.serial_number);
    fprintf(fp,":");
    fputs(M_L->m_data.title,fp);
    fprintf(fp,":");
    fputs(M_L->m_data.genre,fp);
    fprintf(fp,":");
    fputs(M_L->m_data.director->director,fp);
    fprintf(fp,":");
    fputs(M_L->m_data.year,fp);
    fprintf(fp,":");
    fputs(M_L->m_data.runtime,fp);
    fprintf(fp,":");
    fputs(M_L->m_data.actors->actor,fp);
    while(M_L->m_data.actors->next!=NULL)
    {
      fprintf(fp,",%s",M_L->m_data.actors->next->actor);
      M_L->m_data.actors=M_L->m_data.actors->next;
    }
    M_L->m_data.actors = tmp;
    fprintf(fp,"\n");
    M_L= M_L->next;
  }
  fclose(fp);
}//데이터를 movie_list파일에 출력

void d_write(director * D_L)
{
  time_t tm_time;
  struct tm *st_time;
  char * now_time = (char*)malloc(20);
  char * str = (char *)malloc(40);
  to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
  tmp->actor = NULL;
  tmp->next=NULL;

  time(&tm_time);
  st_time = localtime(&tm_time);
  strftime(now_time,1204,"%Y%m%d%H%M",st_time);
  strcpy(str,"director_list.");
  strcat(str,now_time);//director_list.시간 파일이름 생성

  if(access("director_list",F_OK)==0)
  {
    FILE * input = fopen("director_list","r");
    FILE * des = fopen(str,"w");
    char ch;
    while((ch=fgetc(input))!=EOF)
      fputc(ch,des);

    fclose(input);
    fclose(des);
  }//director_list 파일을 director_list.시간 파일에 복사

  FILE * fp = fopen("director_list","w");
  while(D_L!=NULL)
  {
    to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
    tmp = D_L->d_data.best_movies;
    fprintf(fp,"%d",D_L->d_data.serial_number);
    fprintf(fp,":");
    fputs(D_L->d_data.name,fp);
    fprintf(fp,":");
    fputs(&D_L->d_data.sex,fp);
    fprintf(fp,":");
    fputs(D_L->d_data.birth,fp);
    fprintf(fp,":");
    fputs(D_L->d_data.best_movies->title,fp);
    while(D_L->d_data.best_movies->next!=NULL)
    {
      fprintf(fp,",%s",D_L->d_data.best_movies->next->title);
      D_L->d_data.best_movies=D_L->d_data.best_movies->next;
    }
    D_L->d_data.best_movies = tmp;
    fprintf(fp,"\n");
    D_L= D_L->next;
  }
  fclose(fp);
}//데이터를 director_list 파일에 파일출력

void a_write(actor * A_L)
{
  time_t tm_time;
  struct tm *st_time;
  char * now_time = (char*)malloc(20);
  char * str = (char *)malloc(40);
  to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
  tmp->actor = NULL;
  tmp->next=NULL;

  time(&tm_time);
  st_time = localtime(&tm_time);
  strftime(now_time,1204,"%Y%m%d%H%M",st_time);
  strcpy(str,"actor_list.");
  strcat(str,now_time);//actor_list.시간 파일 이름 생성

  if(access("actor_list",F_OK)==0)
  {
    FILE * input = fopen("actor_list","r");
    FILE * des = fopen(str,"w");
    char ch;
    while((ch=fgetc(input))!=EOF)
      fputc(ch,des);

    fclose(input);
    fclose(des);
  }//actor_list파일을 actor_list.시간 파일에 복사

  FILE * fp = fopen("actor_list","w");
  while(A_L!=NULL)
  {
    to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
    tmp = A_L->a_data.best_movies;
    fprintf(fp,"%d",A_L->a_data.serial_number);
    fprintf(fp,":");
    fputs(A_L->a_data.name,fp);
    fprintf(fp,":");
    fputs(&A_L->a_data.sex,fp);
    fprintf(fp,":");
    fputs(A_L->a_data.birth,fp);
    fprintf(fp,":");
    fputs(A_L->a_data.best_movies->title,fp);
    while(A_L->a_data.best_movies->next!=NULL)
    {
      fprintf(fp,",%s",A_L->a_data.best_movies->next->title);
      A_L->a_data.best_movies=A_L->a_data.best_movies->next;
    }
    A_L->a_data.best_movies = tmp;
    fprintf(fp,"\n");
    A_L= A_L->next;
  }
  fclose(fp);
}//데이터를 actor_list 파일에 파일출력
