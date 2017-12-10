#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movie_manage_program.h"


int search_algorithm(char *origin, char *search);//search flag 함수
int search_movie(movie* movie, char * search_sentence);//movie 레코드에서 서치
int search_director(director* director, char * search_sentence);//director 레코드에서 서치
int search_actor(actor* actor, char * search_sentence);//actor 레코드에서 서치



int search_algorithm(char *origin, char *search)
{
  int search_length;
  search_length = strlen(search);
  int origin_length;
  origin_length = strlen(origin);


  if(*search == '*')//맨 앞에 * 가 있고
  {
    if(*(search + search_length - 1) == '*')//맨 뒤에 *가 있을 때
    {
      int flag = 0;
      int flag_tmp = 0;

      for(int i = 0; i < search_length -2; i++)
      {
        for(int j = 0; j < origin_length; j++) // 문자열을 비교
        {
          if(*(search + i + 1) == *(origin + j))//같으면
          {
            int current_search_length = search_length - 3;
            int origin_end = 0;

            for(int k = i + 1; k < search_length - 1; k++)//*바로 전까지 다 같으면 같은것
            {
              if(*(search + k) == '?')//?는 넘김
              {
                current_search_length--;
              }

              else
              {
                if(*(origin + origin_end + j) != *(search + k))
                {
                  flag = 1;
                }
                else
                {
                  current_search_length--;
                }
              }
              origin_end++;
            }

            if(flag ==0)
            {
              if(current_search_length == 0)
              {
                flag_tmp = 1;
                return 1;
                break;
              }
            }
          }

          if(flag_tmp == 1)
          {
            break;
          }
        }
        if(flag_tmp == 1)
        {
          break;
        }
      }
      return 0;
    }

    else//맨 앞에만 *이 있을 때
    {
      int flag = 0;
      int flag_tmp = 0;

      for(int i = 0; i < search_length - 2; i++)//같은거 나올 때 까지 비교함
      {
        for(int j = 0; j < origin_length; j ++)
        {
          if(*(search + i + 1) == *(origin + i))
          {
            int current_search_length = search_length - 3;
            int origin_end;

            for(int k = i + 1; k < search_length - 1; k++)
            {
              if(*(search + k) == '?')
              {
                current_search_length--;
              }
              else
              {
                if(*(origin + j + origin_end) != *(search + k))
                {
                  flag = 1;
                }
                else
                {
                  current_search_length--;
                }
              }
              origin_end++;
            }
            if(flag == 0)
            {
              if(current_search_length == 0)
              {
                flag_tmp = 1;
                return 1;
                break;
              }
              else
              {
                flag = 1;
              }
            }
          }
          if(flag_tmp == 1)
          {
            break;
          }
        }
        if(flag_tmp == 1)
        {
          break;
        }
      }
      return 0;
    }
  }

  else if(*(search + search_length - 1) == '*')//맨 뒤에만 *가 올 때
  {
    int flag = 0;
    int flag_tmp = 0;

    for(int i = 0; i < search_length - 1; i++)//위의 방식과 동일
    {
      for(int j = 0; j < origin_length; i++)
      {
        if(*(search + i) == *(origin + j))
        {
          int origin_end = 0;
          int current_search_length = search_length - 1;

          for(int k = 0; k < search_length - 1; k++)
          {
            if(*(search + k) == '?')//'?'는 그냥 넘김
            {
              current_search_length--;
            }

            else
            {
             if(*(search + k) == *(origin + origin_end + j))
             {
               flag = 1;
             }

             else
             {
               current_search_length--;
             }
            }
            origin_end ++;
          }
          if(flag == 0)
          {
            for(int l = 0; l <search_length - 1; l++)
            {
              if((*search + l) != *(origin + l))
              {
                break;
              }
            }
          }
        }
      }
      if(flag_tmp == 1)
      {
        break;
      }
    }
  }
  else//완벽하게 같을 때
  {
    int flag = 0;
    int flag_tmp = 0;

    for(int i=0; i < search_length; i++)
    {
      if(*(origin + i) != '?')
      {
        if(*(origin + i) != *(search + i))
        {
          flag = 1;
        }
      }
    }
    if(flag == 0)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return 0;
}

int search_movie(movie* movie, char * search_sentence)//movie record, flag가 1 일때 구조체 출력
{
  int flag = 0;
  int decide_flag = 0;

  while((movie -> next) != NULL)
  {
    int success_flag = 0;
    decide_flag = search_algorithm(movie -> m_data.title, search_sentence);
    if(success_flag == 0)
    {
      success_flag = decide_flag;
    }
    if(flag == 0)
    {
      flag = decide_flag;
    }

    decide_flag = search_algorithm(movie -> m_data.genre, search_sentence);
    if(success_flag == 0)
    {
      success_flag = decide_flag;
    }
    if(flag == 0)
    {
      flag = decide_flag;
    }


    decide_flag = search_algorithm(movie -> m_data.director -> director, search_sentence);
    if(success_flag == 0)
    {
      success_flag = decide_flag;
    }
    if(flag == 0)
    {
      flag = decide_flag;
    }


    // movie_actor -> m_data.actors -> actor;

    while(movie -> m_data.actors -> next != NULL)
    {
      decide_flag = search_algorithm(movie -> m_data.actors -> actor, search_sentence);
      if(success_flag == 0)
      {
        success_flag = decide_flag;
      }
      if(flag == 0)
      {
        flag = decide_flag;
      }
      movie -> m_data.actors = movie -> m_data.actors -> next;
    }

    //레코드에 있는 문자열과 비교
    if(success_flag == 1)//일치하는것을 찾으면
    {
      printf("%d:%s:%s:%s:%d:%d:", movie -> m_data.serial_number, movie -> m_data.title, movie -> m_data.genre, movie -> m_data.director , movie -> m_data.year, movie -> m_data.runtime); // 출력
    }

    while(movie -> m_data.actors -> next != NULL)
    {
      printf("%s ", movie -> m_data.actors -> actor);
      movie -> m_data.actors = movie -> m_data.actors -> next;
    }
    printf("\n");

    movie = movie -> next;//다음 레코드로 넘어간다



  }
  if(flag == 1) // 찾으면 1 리턴
  {
    return 1;
  }

  else // 없으면 0 리턴
  {
    return 0;
  }

}

int search_director(director* director, char * search_sentence)//director record 방식은 위와 동일
{
  int flag = 0;
  int decide_flag = 0;

  while(director -> next != NULL)
  {
    int success_flag = 0;
    decide_flag = search_algorithm(director -> d_data.name, search_sentence);
    if(success_flag == 0)
    {
      success_flag = decide_flag;
    }
    if(flag == 0)
    {
      flag = decide_flag;
    }

    decide_flag = search_algorithm(director -> d_data.birth, search_sentence);
    if(success_flag == 0)
    {
      success_flag = decide_flag;
    }
    if(flag == 0)
    {
      flag = decide_flag;
    }




    while(director -> d_data.best_movies -> next != NULL)
    {
      decide_flag = search_algorithm(director -> d_data.best_movies -> title, search_sentence);

      if(success_flag == 0)
      {
        success_flag = decide_flag;
      }
      if(flag == 0)
      {
        flag = decide_flag;
      }
      director -> d_data.best_movies = director -> d_data.best_movies -> next;
    }



    if(success_flag == 1)
    {
      printf("%d:%s:%c:%s:", director -> d_data.serial_number, director -> d_data.name, director -> d_data.sex, director -> d_data.birth);
      return 1;


      while(director -> d_data.best_movies -> next != NULL)
      {
        printf("%s ", director -> d_data.best_movies -> title);
        director -> d_data.best_movies = director -> d_data.best_movies -> next;
      }
      printf("\n");

    }


    director = director -> next;



  }
  if(flag == 1)
  {
    return 1;
  }

  else
  {
    return 0;
  }

}


int search_actor(actor* actor, char * search_sentence)//actor record 방식의 위와 동일
{
  int flag = 0;
  int decide_flag = 0;

  while(actor -> next != NULL)
  {
    int success_flag = 0;
    decide_flag = search_algorithm(actor -> a_data.name, search_sentence);
    if(success_flag == 0)
    {
      success_flag = decide_flag;
    }
    if(flag == 0)
    {
      flag = decide_flag;
    }

    decide_flag = search_algorithm(actor -> a_data.birth, search_sentence);
    if(success_flag == 0)
    {
      success_flag = decide_flag;
    }
    if(flag == 0)
    {
      flag = decide_flag;
    }


    while(actor -> a_data.best_movies -> next != NULL)
    {
      decide_flag = search_algorithm(actor -> a_data.best_movies -> title, search_sentence);
      actor -> a_data.best_movies = actor -> a_data.best_movies -> next;
    }

    if(success_flag == 0)
    {
      success_flag = decide_flag;
    }
    if(flag == 0)
    {
      flag = decide_flag;
    }

    if(success_flag == 1)
    {
      printf("%d:%s:%c:%s:", actor -> a_data.serial_number, actor -> a_data.name, actor -> a_data.sex, actor -> a_data.birth);
    }



    while(actor -> a_data.best_movies -> next != NULL)
    {
      printf("%s ", actor -> a_data.best_movies -> title);
      actor -> a_data.best_movies = actor -> a_data.best_movies -> next;
    }
    printf("\n");




    actor = actor -> next;

  }

  if(flag == 1)
  {
    return 1;
  }

  else
  {
    return 0;
  }

}
