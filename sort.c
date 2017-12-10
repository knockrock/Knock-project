#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

int m_t_compare(const void * p, const void * q) //title로 정렬
{
  movie *tmp_a = (movie*)p;
  movie *tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.title,tmp_b->m_data.title);
}
int m_g_compare(const void * p, const void * q) //genre로 정렬
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.genre,tmp_b->m_data.genre);
}
int m_d_compare(const void * p, const void * q)//director로 정렬
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.director->director,tmp_b->m_data.director->director);
}
int m_y_compare(const void * p, const void * q)//year로 정렬
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.year,tmp_b->m_data.year);
}
int m_r_compare(const void * p, const void * q)//runtime으로 정렬
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.runtime,tmp_b->m_data.runtime);
}
int m_a_compare(const void * p, const void * q)//actor로 정렬
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.actors->actor,tmp_b->m_data.actors->actor);
}
void m_sort(movie * M_L, int optcnt, char * opt2, char * opt3, char * opt4)
{
  movie * tmp_M_L = M_L;
  movie * tmp = (movie *)malloc(sizeof(movie)*100);
  to_actor * tmp_actors = NULL;
  int movie_cnt=1;
//동적 할당
  if(M_L==NULL)
    printf("Please add movie node.\n"); //노드가 없을 경우 출력
  else
  {
    while(M_L->next!=NULL)
    {
      movie_cnt++;
      M_L=M_L->next;
    }
    M_L = tmp_M_L;
//노드 갯수 셈
    for(int i=0;i<movie_cnt;i++)
    {
      *(tmp+i) = *M_L;
      M_L=M_L->next;
    }
    M_L = tmp_M_L; // 노드 갯수만큼 새로운 공간 부여
    if(optcnt==1)
    {
      qsort((void*)tmp,movie_cnt,sizeof(movie),m_t_compare);//정렬
      for(int i=0;i<movie_cnt;i++)
      {
        tmp_actors = (*(tmp+i)).m_data.actors;
        printf("%d:%s:%s:%s:%s:%s:",(*(tmp+i)).m_data.serial_number,(*(tmp+i)).m_data.title,(*(tmp+i)).m_data.genre,(*(tmp+i)).m_data.director->director,(*(tmp+i)).m_data.year,(*(tmp+i)).m_data.runtime);
        printf("%s",(*(tmp+i)).m_data.actors->actor);
        while((*(tmp+i)).m_data.actors->next!=NULL)
        {
          printf(",%s",(*(tmp+i)).m_data.actors->next->actor);
          (*(tmp+i)).m_data.actors=(*(tmp+i)).m_data.actors->next;
        }
        printf("\n");
        (*(tmp+i)).m_data.actors = tmp_actors;
      }
      printf("@@ Done\n");
    }//기본 옵션으로 출력
    if(optcnt==2)
    {
      if(strchr(opt2,'t')!=NULL||strchr(opt2,'g')!=NULL||strchr(opt2,'d')!=NULL||strchr(opt2,'y')!=NULL||strchr(opt2,'r')!=NULL||strchr(opt2,'a')!=NULL)
      {
        if(strcmp(opt2,"t")==0)
          qsort((void*)tmp,movie_cnt,sizeof(movie),m_t_compare);
        else if(strcmp(opt2,"g")==0)
          qsort((void*)tmp,movie_cnt,sizeof(movie),m_g_compare);
        else if(strcmp(opt2,"d")==0)
          qsort((void*)tmp,movie_cnt,sizeof(movie),m_d_compare);
        else if(strcmp(opt2,"y")==0)
          qsort((void*)tmp,movie_cnt,sizeof(movie),m_y_compare);
        else if(strcmp(opt2,"r")==0)
          qsort((void*)tmp,movie_cnt,sizeof(movie),m_r_compare);
        else if(strcmp(opt2,"a")==0)
          qsort((void*)tmp,movie_cnt,sizeof(movie),m_a_compare);
        for(int i=0;i<movie_cnt;i++)
        {
          tmp_actors = (*(tmp+i)).m_data.actors;
          printf("%d:%s:%s:%s:%s:%s:",((*(tmp+i)).m_data.serial_number),(*(tmp+i)).m_data.title,(*(tmp+i)).m_data.genre,(*(tmp+i)).m_data.director->director,(*(tmp+i)).m_data.year,(*(tmp+i)).m_data.runtime);
          printf("%s",(*(tmp+i)).m_data.actors->actor);
          while((*(tmp+i)).m_data.actors->next!=NULL)
          {
            printf(",%s",(*(tmp+i)).m_data.actors->next->actor);
            (*(tmp+i)).m_data.actors=(*(tmp+i)).m_data.actors->next;
          }
          printf("\n");
          (*(tmp+i)).m_data.actors = tmp_actors;
        }
        printf("@@ Done\n");
      }//옵션에 따라 출력
      else
        printf("Please enter the option correctly. (t/g/d/y/r/a)\n");
    }
    if(optcnt==3)
    {
      if(strcmp(opt2,"-f")!=0)
      {
        printf("Please enter the option correctly.\n");
      }
      else
      {
        qsort((void*)tmp,movie_cnt,sizeof(movie),m_t_compare);
        FILE * fp = fopen(opt3,"w");
        for(int i=0;i<movie_cnt;i++)
        {
          tmp_actors = (*(tmp+i)).m_data.actors;
          fprintf(fp,"%d:%s:%s:%s:%s:%s:",(*(tmp+i)).m_data.serial_number,(*(tmp+i)).m_data.title,(*(tmp+i)).m_data.genre,(*(tmp+i)).m_data.director->director,(*(tmp+i)).m_data.year,(*(tmp+i)).m_data.runtime);
          fprintf(fp,"%s",(*(tmp+i)).m_data.actors->actor);
          while((*(tmp+i)).m_data.actors->next!=NULL)
          {
            fprintf(fp,",%s",(*(tmp+i)).m_data.actors->next->actor);
            (*(tmp+i)).m_data.actors=(*(tmp+i)).m_data.actors->next;
          }
          fprintf(fp,"\n");
          (*(tmp+i)).m_data.actors = tmp_actors;
        }
        fclose(fp);
        printf("@@ Done\n");
      }
    }//기본 옵션으로 지정된 파일에 출력
    if(optcnt==4)
    {
      if(strcmp(opt3,"-f")!=0)
      {
        printf("Please enter the option correctly.\n");
      }
      else
      {
        if(strchr(opt2,'t')!=NULL||strchr(opt2,'g')!=NULL||strchr(opt2,'d')!=NULL||strchr(opt2,'y')!=NULL||strchr(opt2,'r')!=NULL||strchr(opt2,'a')!=NULL)
        {
          if(strcmp(opt2,"t")==0)
            qsort((void*)tmp,movie_cnt,sizeof(movie),m_t_compare);
          else if(strcmp(opt2,"g")==0)
            qsort((void*)tmp,movie_cnt,sizeof(movie),m_g_compare);
          else if(strcmp(opt2,"d")==0)
            qsort((void*)tmp,movie_cnt,sizeof(movie),m_d_compare);
          else if(strcmp(opt2,"y")==0)
            qsort((void*)tmp,movie_cnt,sizeof(movie),m_y_compare);
          else if(strcmp(opt2,"r")==0)
            qsort((void*)tmp,movie_cnt,sizeof(movie),m_r_compare);
          else if(strcmp(opt2,"a")==0)
            qsort((void*)tmp,movie_cnt,sizeof(movie),m_a_compare);
          FILE * fp = fopen(opt4,"w");
          for(int i=0;i<movie_cnt;i++)
          {
            tmp_actors = (*(tmp+i)).m_data.actors;
            fprintf(fp,"%d:%s:%s:%s:%s:%s:",(*(tmp+i)).m_data.serial_number,(*(tmp+i)).m_data.title,(*(tmp+i)).m_data.genre,(*(tmp+i)).m_data.director->director,(*(tmp+i)).m_data.year,(*(tmp+i)).m_data.runtime);
            fprintf(fp,"%s",(*(tmp+i)).m_data.actors->actor);
            while((*(tmp+i)).m_data.actors->next!=NULL)
            {
              fprintf(fp,",%s",(*(tmp+i)).m_data.actors->next->actor);
              (*(tmp+i)).m_data.actors=(*(tmp+i)).m_data.actors->next;
            }
            fprintf(fp,"\n");
            (*(tmp+i)).m_data.actors = tmp_actors;
          }
          fclose(fp);
          printf("@@ Done\n");
        }
        else
        printf("Please enter the option correctly. (t/g/d/y/r/a)\n");
      }
    }//받은 옵션을 지정된 파일에 출력
  }
}

int d_n_compare(const void * p, const void * q)//name으로 정렬
{
  director *tmp_a = (director*)p;
  director *tmp_b = (director*)q;
  return strcmp(tmp_a->d_data.name,tmp_b->d_data.name);
}
int d_s_compare(const void * p, const void * q)//sex로 정렬
{
  director *tmp_a = (director*)p;
  director *tmp_b = (director*)q;
  if(tmp_a->d_data.sex > tmp_b->d_data.sex)
    return 1;
  else if(tmp_a->d_data.sex == tmp_b->d_data.sex)
    return 0;
  else
    return -1;
}
int d_b_compare(const void * p, const void * q)//birth로 정렬
{
  director *tmp_a = (director*)p;
  director *tmp_b = (director*)q;
  return strcmp(tmp_a->d_data.birth,tmp_b->d_data.birth);
}
int d_m_compare(const void * p, const void * q)//movie로 정렬
{
  director *tmp_a = (director*)p;
  director *tmp_b = (director*)q;
  return strcmp(tmp_a->d_data.best_movies->title,tmp_b->d_data.best_movies->title);
}
void d_sort(director * D_L, int optcnt, char * opt2, char * opt3, char * opt4)
{
  director * tmp_D_L = D_L;
  director * tmp = (director *)malloc(sizeof(director)*100);
  to_movie * tmp_best_movies = NULL;
  int director_cnt=1;
//동적 할당
  if(D_L==NULL)
    printf("Please add director node.\n");//노드가 없을 경우 메세지 출력
  else
  {
    while(D_L->next!=NULL)
    {
      director_cnt++;
      D_L=D_L->next;
    }
    D_L = tmp_D_L;
//노드 갯수 세기
    for(int i=0;i<director_cnt;i++)
    {
      *(tmp+i) = *D_L;
      D_L=D_L->next;
    }
    D_L = tmp_D_L;
//노드 갯수만큼 새로운 공간 부여
    if(optcnt==1)
    {
      qsort((void*)tmp,director_cnt,sizeof(director),d_n_compare);
      for(int i=0;i<director_cnt;i++)
      {
        tmp_best_movies = (*(tmp+i)).d_data.best_movies;
        printf("%d:%s:%s:%s:",(*(tmp+i)).d_data.serial_number,(*(tmp+i)).d_data.name,&(*(tmp+i)).d_data.sex,(*(tmp+i)).d_data.birth);
        printf("%s",(*(tmp+i)).d_data.best_movies->title);
        while((*(tmp+i)).d_data.best_movies->next!=NULL)
        {
          printf(",%s",(*(tmp+i)).d_data.best_movies->next->title);
          (*(tmp+i)).d_data.best_movies=(*(tmp+i)).d_data.best_movies->next;
        }
        printf("\n");
        (*(tmp+i)).d_data.best_movies = tmp_best_movies;
      }
      printf("@@ Done\n");
    }//기본 옵션으로 출력
    if(optcnt==2)
    {
      if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
      {
        if(strcmp(opt2,"n")==0)
          qsort((void*)tmp,director_cnt,sizeof(director),d_n_compare);
        else if(strcmp(opt2,"s")==0)
          qsort((void*)tmp,director_cnt,sizeof(director),d_s_compare);
        else if(strcmp(opt2,"b")==0)
        qsort((void*)tmp,director_cnt,sizeof(director),d_b_compare);
        else if(strcmp(opt2,"m")==0)
          qsort((void*)tmp,director_cnt,sizeof(director),d_m_compare);
        for(int i=0;i<director_cnt;i++)
        {
          tmp_best_movies = (*(tmp+i)).d_data.best_movies;
          printf("%d:%s:%s:%s:",(*(tmp+i)).d_data.serial_number,(*(tmp+i)).d_data.name,&(*(tmp+i)).d_data.sex,(*(tmp+i)).d_data.birth);
          printf("%s",(*(tmp+i)).d_data.best_movies->title);
          while((*(tmp+i)).d_data.best_movies->next!=NULL)
          {
            printf(",%s",(*(tmp+i)).d_data.best_movies->next->title);
            (*(tmp+i)).d_data.best_movies=(*(tmp+i)).d_data.best_movies->next;
          }
          printf("\n");
          (*(tmp+i)).d_data.best_movies = tmp_best_movies;
        }
        printf("@@ Done\n");
      }//지정된 옵션으로 출력
      else
        printf("Please enter the option correctly. (n/s/b/m)\n");
    }
    if(optcnt==3)
    {
      if(strcmp(opt2,"-f")!=0)
      {
        printf("Please enter the option correctly. \n");
      }
      else
      {
        qsort((void*)tmp,director_cnt,sizeof(director),d_n_compare);
        FILE * fp = fopen(opt3,"w");
        for(int i=0;i<director_cnt;i++)
        {
          tmp_best_movies = (*(tmp+i)).d_data.best_movies;
          fprintf(fp,"%d:%s:%s:%s:",(*(tmp+i)).d_data.serial_number,(*(tmp+i)).d_data.name,&(*(tmp+i)).d_data.sex,(*(tmp+i)).d_data.birth);
          fprintf(fp,"%s",(*(tmp+i)).d_data.best_movies->title);
          while((*(tmp+i)).d_data.best_movies->next!=NULL)
          {
            fprintf(fp,",%s",(*(tmp+i)).d_data.best_movies->next->title);
            (*(tmp+i)).d_data.best_movies=(*(tmp+i)).d_data.best_movies->next;
          }
          fprintf(fp,"\n");
          (*(tmp+i)).d_data.best_movies = tmp_best_movies;
        }
        fclose(fp);
        printf("@@ Done\n");
      }
    }//기본옵션을 지정된 파일에 출력
    if(optcnt==4)
    {
      if(strcmp(opt3,"-f")!=0)
      {
        printf("Please enter the option correctly. \n");
      }
      else
      {
        if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
        {
          if(strcmp(opt2,"n")==0)
            qsort((void*)tmp,director_cnt,sizeof(director),d_n_compare);
          else if(strcmp(opt2,"s")==0)
            qsort((void*)tmp,director_cnt,sizeof(director),d_s_compare);
          else if(strcmp(opt2,"b")==0)
          qsort((void*)tmp,director_cnt,sizeof(director),d_b_compare);
          else if(strcmp(opt2,"m")==0)
            qsort((void*)tmp,director_cnt,sizeof(director),d_m_compare);
          FILE * fp = fopen(opt4,"w");
          for(int i=0;i<director_cnt;i++)
          {
            tmp_best_movies = (*(tmp+i)).d_data.best_movies;
            fprintf(fp,"%d:%s:%s:%s:",(*(tmp+i)).d_data.serial_number,(*(tmp+i)).d_data.name,&(*(tmp+i)).d_data.sex,(*(tmp+i)).d_data.birth);
            fprintf(fp,"%s",(*(tmp+i)).d_data.best_movies->title);
            while((*(tmp+i)).d_data.best_movies->next!=NULL)
            {
              fprintf(fp,",%s",(*(tmp+i)).d_data.best_movies->next->title);
              (*(tmp+i)).d_data.best_movies=(*(tmp+i)).d_data.best_movies->next;
            }
            fprintf(fp,"\n");
            (*(tmp+i)).d_data.best_movies = tmp_best_movies;
          }
          fclose(fp);
          printf("@@ Done\n");
        }
        else
          printf("Please enter the option correctly. (n/s/b/m)\n");
      }
    }
  }//지정된 옵션으로 지정된 파일에 출력
}

int a_n_compare(const void * p, const void * q)//name으로 정렬
{
  actor *tmp_a = (actor*)p;
  actor *tmp_b = (actor*)q;
  return strcmp(tmp_a->a_data.name,tmp_b->a_data.name);
}
int a_s_compare(const void * p, const void * q)//sex로 정렬
{
  actor *tmp_a = (actor*)p;
  actor *tmp_b = (actor*)q;
  if(tmp_a->a_data.sex > tmp_b->a_data.sex)
    return 1;
  else if(tmp_a->a_data.sex == tmp_b->a_data.sex)
    return 0;
  else
    return -1;
}
int a_b_compare(const void * p, const void * q)//birth로 정렬
{
  actor *tmp_a = (actor*)p;
  actor *tmp_b = (actor*)q;
  return strcmp(tmp_a->a_data.birth,tmp_b->a_data.birth);
}
int a_m_compare(const void * p, const void * q)//movie로 정렬
{
  actor *tmp_a = (actor*)p;
  actor *tmp_b = (actor*)q;
  return strcmp(tmp_a->a_data.best_movies->title,tmp_b->a_data.best_movies->title);
}
void a_sort(actor* A_L, int optcnt, char * opt2, char * opt3, char * opt4)
{
  actor * tmp_A_L = A_L;
  actor * tmp = (actor *)malloc(sizeof(actor)*100);
  to_movie * tmp_best_movies = NULL;
  int actor_cnt=1;
//동적 할당
  if(A_L==NULL)
    printf("Please add actor node.\n");//노드 없을 경우 메세지 출력
  else
  {
    while(A_L->next!=NULL)
    {
      actor_cnt++;
      A_L=A_L->next;
    }
    A_L = tmp_A_L;
//노드 갯수 세기
    for(int i=0;i<actor_cnt;i++)
    {
      *(tmp+i) = *A_L;
      A_L=A_L->next;
    }
    A_L = tmp_A_L;
//노드 갯수만큼 새로운 공간 부여
    if(optcnt==1)
    {
      qsort((void*)tmp,actor_cnt,sizeof(actor),a_n_compare);
      for(int i=0;i<actor_cnt;i++)
        {
          tmp_best_movies = (*(tmp+i)).a_data.best_movies;
          printf("%d:%s:%s:%s:",(*(tmp+i)).a_data.serial_number,(*(tmp+i)).a_data.name,&(*(tmp+i)).a_data.sex,(*(tmp+i)).a_data.birth);
          printf("%s",(*(tmp+i)).a_data.best_movies->title);
          while((*(tmp+i)).a_data.best_movies->next!=NULL)
          {
            printf(",%s",(*(tmp+i)).a_data.best_movies->next->title);
            (*(tmp+i)).a_data.best_movies=(*(tmp+i)).a_data.best_movies->next;
          }
          printf("\n");
          (*(tmp+i)).a_data.best_movies = tmp_best_movies;
        }
        printf("@@ Done\n");
    }//기본 옵션으로 출력
    if(optcnt==2)
    {
      if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
      {
        if(strcmp(opt2,"n")==0)
          qsort((void*)tmp,actor_cnt,sizeof(actor),a_n_compare);
        else if(strcmp(opt2,"s")==0)
          qsort((void*)tmp,actor_cnt,sizeof(actor),a_s_compare);
        else if(strcmp(opt2,"b")==0)
        qsort((void*)tmp,actor_cnt,sizeof(actor),a_b_compare);
        else if(strcmp(opt2,"m")==0)
          qsort((void*)tmp,actor_cnt,sizeof(actor),a_m_compare);
        for(int i=0;i<actor_cnt;i++)
        {
          tmp_best_movies = (*(tmp+i)).a_data.best_movies;
          printf("%d:%s:%s:%s:",(*(tmp+i)).a_data.serial_number,(*(tmp+i)).a_data.name,&(*(tmp+i)).a_data.sex,(*(tmp+i)).a_data.birth);
          printf("%s",(*(tmp+i)).a_data.best_movies->title);
          while((*(tmp+i)).a_data.best_movies->next!=NULL)
          {
            printf(",%s",(*(tmp+i)).a_data.best_movies->next->title);
            (*(tmp+i)).a_data.best_movies=(*(tmp+i)).a_data.best_movies->next;
          }
          printf("\n");
          (*(tmp+i)).a_data.best_movies = tmp_best_movies;
        }
        printf("@@ Done\n");
      }
      else
        printf("Please enter the option correctly. (n/s/b/m)\n");
    }//지정된 옵션으로 출력
    if(optcnt==3)
    {
      if(strcmp(opt2,"-f")!=0)
      {
        printf("Please enter the option correctly. \n");
      }
      else
      {
        qsort((void*)tmp,actor_cnt,sizeof(actor),a_n_compare);
        FILE * fp = fopen(opt3,"w");
        for(int i=0;i<actor_cnt;i++)
        {
          tmp_best_movies = (*(tmp+i)).a_data.best_movies;
          fprintf(fp,"%d:%s:%s:%s:",(*(tmp+i)).a_data.serial_number,(*(tmp+i)).a_data.name,&(*(tmp+i)).a_data.sex,(*(tmp+i)).a_data.birth);
          fprintf(fp,"%s",(*(tmp+i)).a_data.best_movies->title);
          while((*(tmp+i)).a_data.best_movies->next!=NULL)
          {
            fprintf(fp,",%s",(*(tmp+i)).a_data.best_movies->next->title);
            (*(tmp+i)).a_data.best_movies=(*(tmp+i)).a_data.best_movies->next;
          }
          fprintf(fp,"\n");
          (*(tmp+i)).a_data.best_movies = tmp_best_movies;
        }
        fclose(fp);
        printf("@@ Done\n");
      }//기본 옵션으로 지정된 파일에 출력
    }
    if(optcnt==4)
    {
      if(strcmp(opt3,"-f")!=0)
      {
        printf("Please enter the option correctly. \n");
      }
      else
      {
        if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
        {
          if(strcmp(opt2,"n")==0)
            qsort((void*)tmp,actor_cnt,sizeof(actor),a_n_compare);
          else if(strcmp(opt2,"s")==0)
            qsort((void*)tmp,actor_cnt,sizeof(actor),a_s_compare);
          else if(strcmp(opt2,"b")==0)
          qsort((void*)tmp,actor_cnt,sizeof(actor),a_b_compare);
          else if(strcmp(opt2,"m")==0)
            qsort((void*)tmp,actor_cnt,sizeof(actor),a_m_compare);
          FILE * fp = fopen(opt4,"w");
          for(int i=0;i<actor_cnt;i++)
          {
            tmp_best_movies = (*(tmp+i)).a_data.best_movies;
            fprintf(fp,"%d:%s:%s:%s:",(*(tmp+i)).a_data.serial_number,(*(tmp+i)).a_data.name,&(*(tmp+i)).a_data.sex,(*(tmp+i)).a_data.birth);
            fprintf(fp,"%s",(*(tmp+i)).a_data.best_movies->title);
            while((*(tmp+i)).a_data.best_movies->next!=NULL)
            {
              fprintf(fp,",%s",(*(tmp+i)).a_data.best_movies->next->title);
              (*(tmp+i)).a_data.best_movies=(*(tmp+i)).a_data.best_movies->next;
            }
            fprintf(fp,"\n");
            (*(tmp+i)).a_data.best_movies = tmp_best_movies;
          }
          fclose(fp);
          printf("@@ Done\n");
        }
        else
          printf("Please enter the option correctly. (n/s/b/m)\n");
      }
    }
  }//지정된 옵션으로 지정된 파일에 출력
}
