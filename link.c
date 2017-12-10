#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void d_link(director *p, actor * q, movie * z)
{
  movie * tmp;
  tmp = z;
  while(p->next != NULL)
  {
    if(p->d_data.best_movies->next == NULL)
    {
      while(z->next != NULL)
      {
        if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
        {
          p->d_data.best_movies->same_title = z;
        }
        z=z->next;
      }
        if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
        {
          p->d_data.best_movies->same_title = z;
        }
        z = tmp;
    }
    else if(p->d_data.best_movies->next != NULL)
    {
    while(p->d_data.best_movies->next != NULL)
    {
      while(z->next != NULL)
      {
        if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
        {
          p->d_data.best_movies->same_title = z;
        }
        z=z->next;
      }
        if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
        {
          p->d_data.best_movies->same_title = z;
        }
        p->d_data.best_movies=p->d_data.best_movies->next;
        z = tmp;
    }
    while(z->next != NULL)
    {
      if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
      {
        p->d_data.best_movies->same_title = z;
      }
      z=z->next;
    }
      if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
      {
        p->d_data.best_movies->same_title = z;
      }
      z = tmp;
  }
        p=p->next;
}
if(p->d_data.best_movies->next == NULL)
{
  while(z->next != NULL)
  {
    if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
    {
      p->d_data.best_movies->same_title = z;
    }
    z=z->next;
  }
    if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
    {
      p->d_data.best_movies->same_title = z;
    }
    z = tmp;
}
else if(p->d_data.best_movies->next != NULL)
{
  while(p->d_data.best_movies->next != NULL)
  {
    while(z->next != NULL)
    {
      if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
      {
        p->d_data.best_movies->same_title = z;
      }
      z=z->next;
    }
      if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
      {
        p->d_data.best_movies->same_title = z;
      }
      p->d_data.best_movies=p->d_data.best_movies->next;
      z = tmp;
  }
  while(z->next != NULL)
  {
    if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
    {
      p->d_data.best_movies->same_title = z;
    }
    z=z->next;
  }
    if(strcmp(p->d_data.best_movies->title, z->m_data.title) == 0)
    {
      p->d_data.best_movies->same_title = z;
    }
    z = tmp;
}
}

void a_link(actor *p, director * q, movie * z)
{
  movie * tmp;
  tmp = z;
  while(p->next != NULL)
  {
    if(p->a_data.best_movies->next == NULL)
    {
      while(z->next != NULL)
      {
        if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
        {
          p->a_data.best_movies->same_title = z;
        }
        z=z->next;
      }
        if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
        {
          p->a_data.best_movies->same_title = z;
        }
        z=tmp;
    }
    else if(p->a_data.best_movies->next != NULL)
    {
    while(p->a_data.best_movies->next != NULL)
    {
      while(z->next != NULL)
      {
        if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
        {
          p->a_data.best_movies->same_title = z;
        }
        z=z->next;
      }
        if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
        {
          p->a_data.best_movies->same_title = z;
        }
        p->a_data.best_movies=p->a_data.best_movies->next;
        z=tmp;
    }
    while(z->next != NULL)
    {
      if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
      {
        p->a_data.best_movies->same_title = z;
      }
      z=z->next;
    }
      if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
      {
        p->a_data.best_movies->same_title = z;
      }
      z=tmp;
  }
        p=p->next;
}
if(p->a_data.best_movies->next == NULL)
{
  while(z->next != NULL)
  {
    if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
    {
      p->a_data.best_movies->same_title = z;
    }
    z=z->next;
  }
    if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
    {
      p->a_data.best_movies->same_title = z;
    }
    z=tmp;
}
else if(p->a_data.best_movies->next != NULL)
{
  while(p->a_data.best_movies->next != NULL)
  {
    while(z->next != NULL)
    {
      if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
      {
        p->a_data.best_movies->same_title = z;
      }
      z=z->next;
    }
      if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
      {
        p->a_data.best_movies->same_title = z;
      }
      p->a_data.best_movies=p->a_data.best_movies->next;
      z=tmp;
  }
  while(z->next != NULL)
  {
    if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
    {
      p->a_data.best_movies->same_title = z;
    }
    z=z->next;
  }
    if(strcmp(p->a_data.best_movies->title, z->m_data.title) == 0)
    {
      p->a_data.best_movies->same_title = z;
    }
    z=tmp;
}
}

void m_d_link(director *p, actor * q, movie * z)
{
  director * tmp;
  tmp = p;
  while(z->next != NULL)
  {
    if(z->m_data.director->next == NULL)
    {
      while(p->next != NULL)
      {
        if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
        {
          z->m_data.director->same_director = p;
        }
        p=p->next;
      }
        if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
        {
          z->m_data.director->same_director = p;
        }
        p=tmp;
    }
    else if(z->m_data.director->next != NULL)
    {
      while(z->m_data.director->next != NULL)
      {
        while(p->next != NULL)
        {
          if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
          {
            z->m_data.director->same_director = p;
          }
          p=p->next;
        }
          if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
          {
            z->m_data.director->same_director = p;
          }
          z->m_data.director=z->m_data.director->next;
          p=tmp;
      }
      while(p->next != NULL)
      {
        if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
        {
          z->m_data.director->same_director = p;
        }
        p=p->next;
      }
        if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
        {
          z->m_data.director->same_director = p;
        }
        p=tmp;
    }
    z=z->next;
  }
    if(z->m_data.director->next == NULL)
    {
      while(p->next != NULL)
      {
        if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
        {
          z->m_data.director->same_director = p;
        }
        p=p->next;
      }
        if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
        {
          z->m_data.director->same_director = p;
        }
        p=tmp;
    }
    else if(z->m_data.director->next != NULL)
    {
      while(z->m_data.director->next != NULL)
      {
        while(p->next != NULL)
        {
          if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
          {
            z->m_data.director->same_director = p;
          }
          p=p->next;
        }
          if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
          {
            z->m_data.director->same_director = p;
          }
          z->m_data.director=z->m_data.director->next;
          p=tmp;
      }
      while(p->next != NULL)
      {
        if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
        {
          z->m_data.director->same_director = p;
        }
        p=p->next;
      }
        if(strcmp(z->m_data.director->director, p->d_data.name) == 0)
        {
          z->m_data.director->same_director = p;
        }
        p=tmp;
    }
}
void m_a_link(actor * p, director * q, movie * z)
{
  actor * tmp;
  tmp = p;
  while(z->next != NULL)
  {
    if(z->m_data.actors->next == NULL)
    {
      while(p->next != NULL)
      {
        if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
        {
          z->m_data.actors->same_actor = p;
        }
        p=p->next;
      }
        if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
        {
          z->m_data.actors->same_actor = p;
        }
        p=tmp;
    }
    else if(z->m_data.actors->next != NULL)
    {
      while(z->m_data.actors->next != NULL)
      {
        while(p->next != NULL)
        {
          if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
          {
            z->m_data.actors->same_actor = p;
          }
          p=p->next;
        }
          if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
          {
            z->m_data.actors->same_actor = p;
          }
          z->m_data.actors=z->m_data.actors->next;
          p=tmp;
      }
      while(p->next != NULL)
      {
        if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
        {
          z->m_data.actors->same_actor = p;
        }
        p=p->next;
      }
        if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
        {
          z->m_data.actors->same_actor = p;
        }
          p=tmp;
    }
    z=z->next;
  }
    if(z->m_data.actors->next == NULL)
    {
      while(p->next != NULL)
      {
        if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
        {
          z->m_data.actors->same_actor = p;
        }
        p=p->next;
      }
        if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
        {
          z->m_data.actors->same_actor = p;
        }
          p=tmp;
    }
    else if (z->m_data.actors->next != NULL)
    {
      while(z->m_data.actors->next != NULL)
      {
        while(p->next != NULL)
        {
          if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
          {
            z->m_data.actors->same_actor = p;
          }
          p=p->next;
        }
          if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
          {
            z->m_data.actors->same_actor = p;
          }
          z->m_data.actors=z->m_data.actors->next;
            p=tmp;
      }
      while(p->next != NULL)
      {
        if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
        {
          z->m_data.actors->same_actor = p;
        }
        p=p->next;
      }
        if(strcmp(z->m_data.actors->actor, p->a_data.name) == 0)
        {
          z->m_data.actors->same_actor = p;
        }
          p=tmp;
    }
}
