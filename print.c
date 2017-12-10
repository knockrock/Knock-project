#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void print_d(director * p, char * opt2){
  int num = atoi(opt2);
    while(p->next != NULL)
    {
      if(p->d_data.serial_number == num)
      {
        printf("%d, %s, %s, %s\n", num, p->d_data.name, &p->d_data.sex, p->d_data.birth);
        if(p->d_data.best_movies->next == NULL)
        {
          if(p->d_data.best_movies->same_title != NULL)
              printf("%s, %s, %s\n",p->d_data.best_movies->same_title->m_data.title,p->d_data.best_movies->same_title->m_data.year, p->d_data.best_movies->same_title->m_data.runtime);
        }
        else
        {
        while(p->d_data.best_movies->next != NULL)
        {
          if(p->d_data.best_movies->same_title != NULL)
              printf("%s, %s, %s\n",p->d_data.best_movies->same_title->m_data.title,p->d_data.best_movies->same_title->m_data.year, p->d_data.best_movies->same_title->m_data.runtime);
          p->d_data.best_movies=p->d_data.best_movies->next;
        }
        if(p->d_data.best_movies->same_title != NULL)
            printf("%s, %s, %s\n",p->d_data.best_movies->same_title->m_data.title,p->d_data.best_movies->same_title->m_data.year, p->d_data.best_movies->same_title->m_data.runtime);
      }
    }
      p=p->next;
    }
    if(p->d_data.serial_number == num)
    {
      printf("%d, %s, %s, %s\n", num, p->d_data.name, &p->d_data.sex, p->d_data.birth);
      if(p->d_data.best_movies->next == NULL)
      {
        if(p->d_data.best_movies->same_title != NULL)
            printf("%s, %s, %s\n",p->d_data.best_movies->same_title->m_data.title,p->d_data.best_movies->same_title->m_data.year, p->d_data.best_movies->same_title->m_data.runtime);
      }
      else
      {
      while(p->d_data.best_movies->next != NULL)
      {
        if(p->d_data.best_movies->same_title != NULL)
            printf("%s, %s, %s\n",p->d_data.best_movies->same_title->m_data.title,p->d_data.best_movies->same_title->m_data.year, p->d_data.best_movies->same_title->m_data.runtime);
        p->d_data.best_movies=p->d_data.best_movies->next;
      }
      if(p->d_data.best_movies->same_title != NULL)
          printf("%s, %s, %s\n",p->d_data.best_movies->same_title->m_data.title,p->d_data.best_movies->same_title->m_data.year, p->d_data.best_movies->same_title->m_data.runtime);
    }
  }
}

void print_a(actor * p, char * opt2){
  int num = atoi(opt2);
    while(p->next != NULL)
    {
      if(p->a_data.serial_number == num)
      {
        printf("%d, %s, %s, %s\n", num, p->a_data.name, &p->a_data.sex, p->a_data.birth);
        if(p->a_data.best_movies->next == NULL)
        {
          if(p->a_data.best_movies->same_title != NULL)
              printf("%s, %s, %s\n",p->a_data.best_movies->same_title->m_data.title,p->a_data.best_movies->same_title->m_data.year, p->a_data.best_movies->same_title->m_data.runtime);
        }
        else
        {
        while(p->a_data.best_movies->next != NULL)
        {
          if(p->a_data.best_movies->same_title != NULL)
              printf("%s, %s, %s\n",p->a_data.best_movies->same_title->m_data.title,p->a_data.best_movies->same_title->m_data.year, p->a_data.best_movies->same_title->m_data.runtime);
          p->a_data.best_movies=p->a_data.best_movies->next;
        }
        if(p->a_data.best_movies->same_title != NULL)
            printf("%s, %s, %s\n",p->a_data.best_movies->same_title->m_data.title,p->a_data.best_movies->same_title->m_data.year, p->a_data.best_movies->same_title->m_data.runtime);
      }
    }
      p=p->next;
    }
    if(p->a_data.serial_number == num)
    {
      printf("%d, %s, %s, %s\n", num, p->a_data.name, &p->a_data.sex, p->a_data.birth);
      if(p->a_data.best_movies->next == NULL)
      {
        if(p->a_data.best_movies->same_title != NULL)
            printf("%s, %s, %s\n",p->a_data.best_movies->same_title->m_data.title,p->a_data.best_movies->same_title->m_data.year, p->a_data.best_movies->same_title->m_data.runtime);
      }
      else
      {
      while(p->a_data.best_movies->next != NULL)
      {
        if(p->a_data.best_movies->same_title != NULL)
            printf("%s, %s, %s\n",p->a_data.best_movies->same_title->m_data.title,p->a_data.best_movies->same_title->m_data.year, p->a_data.best_movies->same_title->m_data.runtime);
        p->a_data.best_movies=p->a_data.best_movies->next;
      }
      if(p->a_data.best_movies->same_title != NULL)
          printf("%s, %s, %s\n",p->a_data.best_movies->same_title->m_data.title,p->a_data.best_movies->same_title->m_data.year, p->a_data.best_movies->same_title->m_data.runtime);
    }
  }
}


void print_m(movie * p, char * opt2)
{
  int num = atoi(opt2);
  int i;
    while(p->next != NULL)
    {
      if(p->m_data.serial_number == num)
      {
        printf("%d, %s, %s\n", num, p->m_data.title, p->m_data.genre);
        if(p->m_data.director->next == NULL)
        {
          if(p->m_data.director->same_director != NULL)
              printf("D : %s(%s)\n", p->m_data.director->same_director->d_data.name, p->m_data.director->same_director->d_data.birth);
        }
      if(p->m_data.director->next != NULL)
        {
        while(p->m_data.director->next != NULL)
        {
          if(p->m_data.director->same_director != NULL)
              printf("D : %s(%s)\n", p->m_data.director->same_director->d_data.name, p->m_data.director->same_director->d_data.birth);
          p->m_data.director=p->m_data.director->next;
        }
        if(p->m_data.director->same_director != NULL)
          printf("D : %s(%s)\n", p->m_data.director->same_director->d_data.name, p->m_data.director->same_director->d_data.birth);
        }
        if(p->m_data.actors->next == NULL)
        {
          if(p->m_data.actors->same_actor != NULL)
            printf("A1 : %s(%s)\n", p->m_data.actors->same_actor->a_data.name, p->m_data.actors->same_actor->a_data.birth);
        }
        if(p->m_data.actors->next != NULL)
          {
            for(int i = 1; p->m_data.actors->next != NULL; i++)
            {
              printf("A%d : %s(%s)\n", i,  p->m_data.actors->same_actor->a_data.name, p->m_data.actors->same_actor->a_data.birth);
            }
              printf("A%d : %s(%s)\n", i+1,  p->m_data.actors->same_actor->a_data.name, p->m_data.actors->same_actor->a_data.birth);
            }
    }
      p=p->next;
    }
    if(p->m_data.serial_number == num)
    {
      printf("%d, %s, %s\n", num, p->m_data.title, p->m_data.genre);
      if(p->m_data.director->next == NULL)
      {
        if(p->m_data.director->same_director != NULL)
            printf("D : %s(%s)\n", p->m_data.director->same_director->d_data.name, p->m_data.director->same_director->d_data.birth);
      }
      if(p->m_data.director->next != NULL)
      {
      while(p->m_data.director->next != NULL)
      {
        if(p->m_data.director->same_director != NULL)
            printf("D : %s(%s)\n", p->m_data.director->same_director->d_data.name, p->m_data.director->same_director->d_data.birth);
        p->m_data.director=p->m_data.director->next;
      }
        if(p->m_data.director->same_director != NULL)
          printf("D : %s(%s)\n", p->m_data.director->same_director->d_data.name, p->m_data.director->same_director->d_data.birth);
      }
      if(p->m_data.actors->next == NULL)
      {
        if(p->m_data.actors->same_actor != NULL)
            printf("A1 : %s(%s)\n", p->m_data.actors->same_actor->a_data.name, p->m_data.actors->same_actor->a_data.birth);
      }
      if(p->m_data.actors->next != NULL)
      {
        for(int i = 1; p->m_data.actors->next != NULL; i++)
        {
          printf("A%d : %s(%s)\n", i,  p->m_data.actors->same_actor->a_data.name, p->m_data.actors->same_actor->a_data.birth);
        }
        printf("A%d : %s(%s)\n", i+1,  p->m_data.actors->same_actor->a_data.name, p->m_data.actors->same_actor->a_data.birth);
      }
  }
}
