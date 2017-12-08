#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

int m_t_compare(const void * p, const void * q)
{
  movie *tmp_a = (movie*)p;
  movie *tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.title,tmp_b->m_data.title);
}
int m_g_compare(const void * p, const void * q)
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.genre,tmp_b->m_data.genre);
}
int m_d_compare(const void * p, const void * q)
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.director->director,tmp_b->m_data.director->director);
}
int m_y_compare(const void * p, const void * q)
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.year,tmp_b->m_data.year);
}
int m_r_compare(const void * p, const void * q)
{
  movie * tmp_a = (movie*)p;
  movie * tmp_b = (movie*)q;
  return strcmp(tmp_a->m_data.runtime,tmp_b->m_data.runtime);
}
int m_a_compare(const void * p, const void * q)
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

  if(M_L==NULL)
    printf("Please add movie node.\n");
  else
  {
    while(M_L->next!=NULL)
    {
      movie_cnt++;
      M_L=M_L->next;
    }
    M_L = tmp_M_L;

    for(int i=0;i<movie_cnt;i++)
    {
      *(tmp+i) = *M_L;
      M_L=M_L->next;
    }
    M_L = tmp_M_L;
    if(optcnt==1)
    {
      qsort((void*)tmp,movie_cnt,sizeof(movie),m_t_compare);
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
    }
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
      }
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
      }
    }
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
        }
        else
        printf("Please enter the option correctly. (t/g/d/y/r/a)\n");
      }
    }
  }
}

int d_n_compare(const void * p, const void * q)
{
  director *tmp_a = (director*)p;
  director *tmp_b = (director*)q;
  return strcmp(tmp_a->d_data.name,tmp_b->d_data.name);
}
int d_s_compare(const void * p, const void * q)
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
int d_b_compare(const void * p, const void * q)
{
  director *tmp_a = (director*)p;
  director *tmp_b = (director*)q;
  return strcmp(tmp_a->d_data.birth,tmp_b->d_data.birth);
}
int d_m_compare(const void * p, const void * q)
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

  if(D_L==NULL)
    printf("Please add director node.\n");
  else
  {
    while(D_L->next!=NULL)
    {
      director_cnt++;
      D_L=D_L->next;
    }
    D_L = tmp_D_L;

    for(int i=0;i<director_cnt;i++)
    {
      *(tmp+i) = *D_L;
      D_L=D_L->next;
    }
    D_L = tmp_D_L;

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
    }
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
      }
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
      }
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
        }
        else
          printf("Please enter the option correctly. (n/s/b/m)\n");
      }
    }
  }
}

int a_n_compare(const void * p, const void * q)
{
  actor *tmp_a = (actor*)p;
  actor *tmp_b = (actor*)q;
  return strcmp(tmp_a->a_data.name,tmp_b->a_data.name);
}
int a_s_compare(const void * p, const void * q)
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
int a_b_compare(const void * p, const void * q)
{
  actor *tmp_a = (actor*)p;
  actor *tmp_b = (actor*)q;
  return strcmp(tmp_a->a_data.birth,tmp_b->a_data.birth);
}
int a_m_compare(const void * p, const void * q)
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

  if(A_L==NULL)
    printf("Please add actor node.\n");
  else
  {
    while(A_L->next!=NULL)
    {
      actor_cnt++;
      A_L=A_L->next;
    }
    A_L = tmp_A_L;

    for(int i=0;i<actor_cnt;i++)
    {
      *(tmp+i) = *A_L;
      A_L=A_L->next;
    }
    A_L = tmp_A_L;
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
    }
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
      }
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
      }
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
        }
        else
          printf("Please enter the option correctly. (n/s/b/m)\n");
      }
    }
  }
}
