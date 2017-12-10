#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void delete_log_a(actor *p, a_node * q) // actor_log 읽으면서 tag가 delete면 삭제
{
  actor * tmp;
  if(p->a_data.serial_number==q->serial_number)// serial_number가 1이면 실행
  {
    *p = *p->next;
  }
  else
  {
  while(p->next != NULL) // serial_number가 1이 아니면 실행
  {
    if(p->next->a_data.serial_number == q->serial_number)
    {
      tmp=p->next;
      p->next = tmp->next;
      free(tmp);
      return;
    }
    p=p->next;
  }
}
}

void delete_log_m(movie *p, m_node * q)// movie_log 읽으면서 tag가 delete면 삭제
{
  movie * tmp;
  if(p->m_data.serial_number==q->serial_number) // serial_number가 1이면 실행
  {
    *p = *p->next;
  }
  else
  {
  while(p->next != NULL)// serial_number가 1이 아니면 실행
  {
    if(p->next->m_data.serial_number == q->serial_number)
    {
      tmp=p->next;
      p->next = tmp->next;
      free(tmp);
      return;
    }
    p=p->next;
  }
}
}

void delete_log_d(director *p, d_node * q) // director_log 읽으면서 tag가 delete면 삭제
{
  director * tmp;
  if(p->d_data.serial_number==q->serial_number) // serial_number가 1이면 실행
  {
    *p = *p->next;
  }
  else
  {
  while(p->next != NULL)//serial_number가 1이 아니면 실행
  {
    if(p->next->d_data.serial_number == q->serial_number)
    {
      tmp=p->next;
      p->next = tmp->next;
      free(tmp);
      return;
    }
    p=p->next;
  }
}
}
