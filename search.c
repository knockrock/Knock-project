#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int search(char *origin, char *search)
{
  int search_length;
  search_lenght = strlen(*search);
  int origin_length;
  origin_length = strlen(*origin);

  int k = 0;
  
  if(*search == '*')
  {
    if(*(search + search_length) == '*')
    {
      // int search_length_tmp = search_length -1;

      int flag1 = 0;
      int flag2 = 0;

      for(int i = 0; i < search_length -2; i++)
      {
        for(int j = 0; j < search_length; j++)
        {
          if(*(origin + j) == *(search + i + 1))
          {
            int current_search_length = search_length - 3;

            for(int k = i; k < current_search_length; k++)
            {
              if(*(string_search + k + 1) == '?')
              {
                
              }

              else
              {
                if(*(string_origin + j + ))
              }
            }
            
          }
        }
      }
    }

    else
    {
      
    }
  }
  
  else if(*(search + search_length) == '*')
  {
    
  }
  else
  {
    
  }
}

int search_movie(structr movie_node* movie, char * search_sentence)
{
  int flag = 0;
  int decide_flag = 0;

  while(movie != NULL)
  {
    decide_flag = search(movie -> title, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }

    decide_flag = search(movie -> genre, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }


    decide_flag = search(movie -> director, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }

    decide_flag = search(movie -> actors, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }

    movie = movie -> movie_next;

    if(flag == 0)
    {
      printf("@@ No such record\n");
      return 0;
    }

    else
    {
      return 1;
    }
  }

}

int search_director(struct director_node* director, char * search_sentence)
{
  int flag = 0;
  int decide_flag = 0;
  
  while(director != NULL)
  {
    decide_flag = search(director -> name, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }
  
    decide_flag = search(director -> birth, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }
  
  
    decide_flag = search(director -> best_movie, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }
  

    director = director -> director_next;
  
    if(flag == 0)
    {
      printf("@@ No such record\n");
      return 0;
    }
  
    else
    {
      return 1;
    }
  }

}


int search_actor(struct actor_node* actir, char * search_sentence)
{
  int flag = 0;
  int decide_flag = 0;
  
  while(actor != NULL)
  {
    decide_flag = search(actor -> name, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }
  
    decide_flag = search(actor -> birth, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }
  
  
    decide_flag = search(actor -> best_movie, search_sentence);
    if(flag == 0)
    {
      flag = decide_flag;
    }
  

    actor = actor -> actor_next;
  
    if(flag == 0)
    {
      printf("@@ No such record\n");
      return 0;
    }
  
    else
    {
      return 1;
    }
  }

}

    
    
  
  
