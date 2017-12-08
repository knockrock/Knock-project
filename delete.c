#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void delete_d(director *p, char * opt2)
{
  int num = atoi(opt2);
  director * tmp;
  if(p->d_data.serial_number==num)
  {
    FILE *fp1=fopen("director_log","a");
    fprintf(fp1,"delete:");
    fprintf(fp1,"%d:",p->d_data.serial_number);
    fputs(p->d_data.name,fp1);
    fprintf(fp1,":");
    fputs(&p->d_data.sex,fp1);
    fprintf(fp1,":");
    fputs(p->d_data.birth,fp1);
    fprintf(fp1,":");
    fputs(p->d_data.best_movies->title,fp1);
    fprintf(fp1,"\n");
    fclose(fp1);
    tmp = p;
    free(tmp);
    p=p->next;
    printf("@@Done\n");
  }
  else
  {
  while(p->next != NULL)
  {
    if(p->next->d_data.serial_number == num)
    {
      tmp=p->next;
      p->next = tmp->next;
      FILE *fp1=fopen("director_log","a");
      fprintf(fp1,"delete:");
      fprintf(fp1,"%d:",tmp->d_data.serial_number);
      fputs(tmp->d_data.name,fp1);
      fprintf(fp1,":");
      fputs(&tmp->d_data.sex,fp1);
      fprintf(fp1,":");
      fputs(tmp->d_data.birth,fp1);
      fprintf(fp1,":");
      fputs(tmp->d_data.best_movies->title,fp1);
      tmp->d_data.best_movies=tmp->d_data.best_movies->next;

      if(tmp->d_data.best_movies!=NULL)
      {
        while(1)
        {
          fprintf(fp1,",");
          fputs(tmp->d_data.best_movies->title,fp1);
          tmp->d_data.best_movies=tmp->d_data.best_movies->next;
          if(tmp->d_data.best_movies==NULL)
          break;
        }
      }
      fprintf(fp1,"\n");
      fclose(fp1);
      free(tmp);
      printf("Done@@\n");
      return;
    }
    p=p->next;
  }
    printf("No such record.\n");
    return;
}
}

void delete_a(actor *p, char * opt2)
{
  int num = atoi(opt2);
  actor * tmp;
  if(p->a_data.serial_number==num)
  {
    FILE *fp1=fopen("actor_log","a");
  	fprintf(fp1,"delete:");
  	fprintf(fp1,"%d:",p->a_data.serial_number);
  	fputs(p->a_data.name,fp1);
  	fprintf(fp1,":");
  	fputs(&p->a_data.sex,fp1);
  	fprintf(fp1,":");
  	fputs(p->a_data.birth,fp1);
  	fprintf(fp1,":");
  	fputs(p->a_data.best_movies->title,fp1);
  	fprintf(fp1,"\n");
  	fclose(fp1);
    tmp = p;
    free(tmp);
    p=p->next;
    printf("@@Done\n");
    return ;
  }
  else
  {
  while(p->next != NULL)
  {
    if(p->next->a_data.serial_number == num)
    {
      tmp=p->next;
      p->next = tmp->next;
      FILE *fp1=fopen("actor_log","a");
    	fprintf(fp1,"delete:");
    	fprintf(fp1,"%d:",tmp->a_data.serial_number);
    	fputs(tmp->a_data.name,fp1);
    	fprintf(fp1,":");
    	fputs(&tmp->a_data.sex,fp1);
    	fprintf(fp1,":");
    	fputs(tmp->a_data.birth,fp1);
    	fprintf(fp1,":");
    	fputs(tmp->a_data.best_movies->title,fp1);
    	tmp->a_data.best_movies=tmp->a_data.best_movies->next;
    	if(tmp->a_data.best_movies!=NULL)
    	{
    		while(1)
    		{
    			fprintf(fp1,",");
    			fputs(tmp->a_data.best_movies->title,fp1);
    			tmp->a_data.best_movies=tmp->a_data.best_movies->next;
    			if(tmp->a_data.best_movies==NULL)
    			break;
    		}
    	}
    	fprintf(fp1,"\n");
    	fclose(fp1);
      free(tmp);
      printf("Done@@\n");
      return;
    }
    p=p->next;
  }
    printf("No such record.\n");
    return;
}
}

void delete_m(movie *p, char * opt2)
{
  int num = atoi(opt2);
  movie * tmp;
  if(p->m_data.serial_number==num)
  {
    FILE *fp1=fopen("movie_log","a");
   fprintf(fp1,"delete:");
   fprintf(fp1,"%d:",p->m_data.serial_number);
   fputs(p->m_data.title,fp1);
   fprintf(fp1,":");
   fputs(p->m_data.genre,fp1);
   fprintf(fp1,":");
   fputs(p->m_data.director->director,fp1);
   fprintf(fp1,":");
   fputs(p->m_data.year,fp1);
   fprintf(fp1,":");
   fputs(p->m_data.runtime,fp1);
   fprintf(fp1,":");
   fputs(p->m_data.actors->actor,fp1);
   fprintf(fp1,"\n");
   fclose(fp1);
    tmp = p;
    free(tmp);
    p=p->next;
    printf("@@Done\n");
  }
  else
  {
  while(p->next != NULL)
  {
    if(p->next->m_data.serial_number == num)
    {
      tmp=p->next;
      p->next = tmp->next;
      FILE *fp1=fopen("movie_log","a");
 	 	fprintf(fp1,"delete:");
 	 	fprintf(fp1,"%d:",tmp->m_data.serial_number);
 	 	fputs(tmp->m_data.title,fp1);
 	 	fprintf(fp1,":");
 	 	fputs(tmp->m_data.genre,fp1);
 	 	fprintf(fp1,":");
 	 	fputs(tmp->m_data.director->director,fp1);
 	 	fprintf(fp1,":");
 	 	fputs(tmp->m_data.year,fp1);
 	 	fprintf(fp1,":");
 	 	fputs(tmp->m_data.runtime,fp1);
 	 	fprintf(fp1,":");
 	 	fputs(tmp->m_data.actors->actor,fp1);
 	 	tmp->m_data.actors=tmp->m_data.actors->next;

 	 	if(tmp->m_data.actors!=NULL)
 	 	{
 	 		while(1)
 	 		{
 	 			fprintf(fp1,",");
 	 			fputs(tmp->m_data.actors->actor,fp1);
 	 			tmp->m_data.actors=tmp->m_data.actors->next;
 	 			if(tmp->m_data.actors==NULL)
 	 				break;
 	 		}
 	 	}
 	 	fprintf(fp1,"\n");
 	 	fclose(fp1);
      free(tmp);
      printf("Done@@\n");
      return;
    }
    p=p->next;
  }
    printf("No such record.\n");
    return;
}
}
