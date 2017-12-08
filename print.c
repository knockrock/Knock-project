#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"
int Last_number_d(director * p){
   int i = 0;
   while(p->next != NULL){
      i++;
      p = p->next;
   }
   return i + 1;
}
int Last_number_a(actor * p){
	int i = 0;
	while(p->next != NULL){
		i++;
		p = p->next;
	}
	return i + 1;
}
int Last_number_m(movie * p){
  int i = 0;
   while(p->next != NULL){
      i++;
      p = p->next;
   }
   return i + 1;
}
void print_d(director * p, movie * q, char * opt2){
  int y;
  int num = atoi(opt2);
  int number = Last_number_d(p);
  if(num > number)
  {
    printf("No such record\n");
  }
  else if (num == 1)
  {
    printf("%d, %s, %s, %d\n", num, p->d_data->name, &p->d_data->sex, p->d_data->birth);

    while(p->d_data->best_movies->next != NULL)
    {
      while (strcmp(p->d_data->best_movies->title, q->m_data->title)==0)
      {
        q = q->next;
      }
      printf("%s, %s, %s\n",p->d_data->best_movies->title, q->m_data->year, q->m_data->runtime);
      p->d_data->best_movies = p->d_data->best_movies->next;
      //q->m_data->next = q
    }
    while (strcmp(p->d_data->best_movies->title, q->m_data->title)==0)
    {
      q = q->next;
    }
    printf("%s, %s, %s\n",p->d_data->best_movies->title, q->m_data->year, q->m_data->runtime);
  }
  else
  {
  for(y=1; y<num-1; y++)
  {
    p = p->next;
  }
  p = p->next;
  printf("%d, %s, %s, %s\n", num, p->d_data->name, &p->d_data->sex, p->d_data->birth);
  while(p->d_data->best_movies->next != NULL)
  {
    while (strcmp(p->d_data->best_movies->title, q->m_data->title)==0)
    {
      q = q->next;
    }
    printf("%s, %s, %s\n",p->d_data->best_movies->title, q->m_data->year, q->m_data->runtime);
    p->d_data->best_movies = p->d_data->best_movies->next;
    //q->m_data->next = q
  }
  while (strcmp(p->d_data->best_movies->title, q->m_data->title)==0)
  {
    q = q->next;
  }
  printf("%s, %s, %s\n",p->d_data->best_movies->title, q->m_data->year, q->m_data->runtime);
}
}

void print_a(actor * p, movie * q, char * opt2){
  int y;
  int num = atoi(opt2);
  int number = Last_number_a(p);
  if(num > number)
  {
    printf("No such record\n");
  }
  else if (num == 1)
  {
    printf("%d, %s, %s, %s\n", num, p->a_data->name, &p->a_data->sex, p->a_data->birth);
    while(p->a_data->best_movies->next != NULL)
    {
      while (strcmp(p->a_data->best_movies->title, q->m_data->title)==0)
      {
        q = q->next;
      }
      printf("%s, %s, %s\n",p->a_data->best_movies->title, q->m_data->year, q->m_data->runtime);
      p->a_data->best_movies = p->a_data->best_movies->next;
      //q->m_data->next = q
    }
    while (strcmp(p->a_data->best_movies->title, q->m_data->title)==0)
    {
      q = q->next;
    }
    printf("%s, %s, %s\n",p->a_data->best_movies->title, q->m_data->year, q->m_data->runtime);
  }
  else
  {
  for(y=1; y<num-1; y++)
  {
    p = p->next;
  }
  p = p->next;
  printf("%d, %s, %s, %s\n", num, p->a_data->name, &p->a_data->sex, p->a_data->birth);
  while(p->a_data->best_movies->next != NULL)
  {
    while (strcmp(p->a_data->best_movies->title, q->m_data->title)==0)
    {
      q = q->next;
    }
    printf("%s, %s, %s\n",p->a_data->best_movies->title, q->m_data->year, q->m_data->runtime);
    p->a_data->best_movies = p->a_data->best_movies->next;
    //q->m_data->next = q
  }
  while (strcmp(p->a_data->best_movies->title, q->m_data->title)==0)
  {
    q = q->next;
  }
  printf("%s, %s, %s\n",p->a_data->best_movies->title, q->m_data->year, q->m_data->runtime);
}
}

void print_m(movie * p, actor *q, director * z, char * opt2){
  int y,i;
  int num = atoi(opt2);
  int number = Last_number_m(p);
  if(num > number)
  {
    printf("No such record\n");
  }
  else if (num == 1)
  {
    printf("%d, %s, %s \n", num, p->m_data->title, p->m_data->genre);
    while(strcmp(p->m_data->director->director,z->d_data->name)==0)
    {
      z = z->next;
    }
    printf("D : %s(%d)\n",p->m_data->director->director, z->d_data->birth);
      for(int i =1; p->m_data->actors->next != NULL; i++)
        {
          while(strcmp(p->m_data->actors->actor, q->a_data->name)==0)
          {
            q = q->next;
          }
          printf("A%d : %s(%d)",i,p->m_data->actors->actor, q->a_data->birth);
        }
        while(strcmp(p->m_data->actors->actor, q->a_data->name)==0)
        {
          q = q->next;
        }
        printf("A%d : %s(%d)",i,p->m_data->actors->actor, q->a_data->birth);
  }
  else
  {
  for(y=1; y<num-1; y++)
  {
    p = p->next;
  }
  p = p->next;
  printf("%d, %s, %s \n", num, p->m_data->title, p->m_data->genre);
  while(strcmp(p->m_data->director->director,z->d_data->name)==0)
  {
    z = z->next;
  }
  printf("D : %s(%d)\n",p->m_data->director->director, z->d_data->birth);
    for(int i =1; p->m_data->actors->next != NULL; i++)
      {
        while(strcmp(p->m_data->actors->actor, q->a_data->name)==0)
        {
          q = q->next;
        }
        printf("A%d : %s(%d)",i,p->m_data->actors->actor, q->a_data->birth);
      }
      while(strcmp(p->m_data->actors->actor, q->a_data->name)==0)
      {
        q = q->next;
      }
      printf("A%d : %s(%d)",i,p->m_data->actors->actor, q->a_data->birth);
}
}
