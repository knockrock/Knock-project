#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void end(movie * M_L,director * D_L, actor * A_L)
{
  char *c=(char*)malloc(10);
  printf("@@ Do you want to save? (y/n) ");
  gets(c);
  while(1)
  {
    if(strcmp(c,"No") == 0 ||  strcmp(c,"N") == 0 || strcmp(c,"no") ==0 || strcmp(c,"n") == 0)
      break;
    else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
      break;
    else
    {
      printf("@@ Wrong answer. Put again. ");
      gets(c);
    }
  }
  if(strcmp(c,"No") == 0 ||  strcmp(c,"N") == 0 || strcmp(c,"no") == 0 || strcmp(c,"n") == 0)
  {
    exit(1);
  }
  else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
  {
    FILE * fp = fopen("movie_list","w");
		while(M_L!=NULL)
		{
			to_actor * tmp = (to_actor*)malloc(sizeof(to_actor));
			tmp = M_L->m_data.actors;
			fprintf(fp,"%d",M_L->m_data.serial_number);
			fprintf(fp,":");
			fputs(M_L->m_data.title,fp);
			fprintf(fp,":");
			fputs(M_L->m_data.genre,fp);
			fprintf(fp,":");
			fputs(M_L->m_data.director->director,fp);
			fprintf(fp,":");
			fputs(M_L->m_data.year,fp);
			fprintf(fp,":");
			fputs(M_L->m_data.runtime,fp);
			fprintf(fp,":");
			fputs(M_L->m_data.actors->actor,fp);
			while(M_L->m_data.actors->next!=NULL)
			{
				fprintf(fp,",%s",M_L->m_data.actors->next->actor);
				M_L->m_data.actors=M_L->m_data.actors->next;
			}
			M_L->m_data.actors = tmp;
			fprintf(fp,"\n");
			M_L= M_L->next;
		}
		fclose(fp);

    FILE * fp1 = fopen("director_list","w");
		while(D_L!=NULL)
		{
			to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
			tmp = D_L->d_data.best_movies;
			fprintf(fp1,"%d",D_L->d_data.serial_number);
			fprintf(fp1,":");
			fputs(D_L->d_data.name,fp1);
			fprintf(fp1,":");
			fputs(&D_L->d_data.sex,fp1);
			fprintf(fp1,":");
			fputs(D_L->d_data.birth,fp1);
			fprintf(fp1,":");
			fputs(D_L->d_data.best_movies->title,fp1);
			while(D_L->d_data.best_movies->next!=NULL)
			{
				fprintf(fp1,",%s",D_L->d_data.best_movies->next->title);
				D_L->d_data.best_movies=D_L->d_data.best_movies->next;
			}
			D_L->d_data.best_movies = tmp;
			fprintf(fp1,"\n");
			D_L= D_L->next;
		}
		fclose(fp1);

    FILE * fp2 = fopen("actor_list","w");
		while(A_L!=NULL)
		{
			to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
			tmp = A_L->a_data.best_movies;
			fprintf(fp2,"%d",A_L->a_data.serial_number);
			fprintf(fp2,":");
			fputs(A_L->a_data.name,fp2);
			fprintf(fp2,":");
			fputs(&A_L->a_data.sex,fp2);
			fprintf(fp2,":");
			fputs(A_L->a_data.birth,fp2);
			fprintf(fp2,":");
			fputs(A_L->a_data.best_movies->title,fp2);
			while(A_L->a_data.best_movies->next!=NULL)
			{
				fprintf(fp2,",%s",A_L->a_data.best_movies->next->title);
				A_L->a_data.best_movies=A_L->a_data.best_movies->next;
			}
			A_L->a_data.best_movies = tmp;
			fprintf(fp2,"\n");
			A_L= A_L->next;
		}
		fclose(fp2);
    exit(1);
  }
}
