#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void delete_log_a(actor *p, a_node * q)
{
  actor * tmp;
  if(p->a_data.serial_number==q->serial_number)
  {
    *p = *p->next;
  }
  else
  {
  while(p->next != NULL)
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

void delete_log_m(movie *p, m_node * q)
{
  movie * tmp;
  if(p->m_data.serial_number==q->serial_number)
  {
    *p = *p->next;
  }
  else
  {
  while(p->next != NULL)
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

void delete_log_d(director *p, d_node * q)
{
  director * tmp;
  if(p->d_data.serial_number==q->serial_number)
  {
    *p = *p->next;
  }
  else
  {
  while(p->next != NULL)
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
