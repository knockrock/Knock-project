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
void delete_a(actor * p, char * opt2){
  int num = atoi(opt2);
   printf("%d\n",num);
  int number = Last_number_a(p);
   printf("%d\n", number);
  if(num > number){
    printf("No such record\n");
  }
  else if(num == 1)
  {
    actor * start = (actor *)malloc(sizeof(actor));
    FILE *fp1=fopen("actor_log","a");
  	fprintf(fp1,"add:");
  	fprintf(fp1,"%d:",p->a_data->serial_number);
  	fputs(p->a_data->name,fp1);
  	fprintf(fp1,":");
  	fputs(&p->a_data->sex,fp1);
  	fprintf(fp1,":");
  	fputs(p->a_data->birth,fp1);
  	fprintf(fp1,":");
  	fputs(p->a_data->best_movies->title,fp1);
  	p->a_data->best_movies=p->a_data->best_movies->next;

  	if(p->a_data->best_movies!=NULL)
  	{
  		while(1)
  		{
  			fprintf(fp1,",");
  			fputs(p->a_data->best_movies->title,fp1);
  			p->a_data->best_movies=p->a_data->best_movies->next;
  			if(p->a_data->best_movies==NULL)
  			break;
  		}
  	}
  	fprintf(fp1,"\n");
  	fclose(fp1);
    start = p -> next; // start에 p->next를 넣고 p를 반환한다면
    free(p);
      printf("@@Done\n");
  }
  else
  {
    int y;
    actor * tmp;
    for(y=1; y<num-1; y++)
    {
      p = p->next;
    }
    tmp  = p -> next;
    FILE *fp1=fopen("actor_log","a");
  	fprintf(fp1,"add:");
  	fprintf(fp1,"%d:",tmp->a_data->serial_number);
  	fputs(tmp->a_data->name,fp1);
  	fprintf(fp1,":");
  	fputs(&tmp->a_data->sex,fp1);
  	fprintf(fp1,":");
  	fputs(tmp->a_data->birth,fp1);
  	fprintf(fp1,":");
  	fputs(tmp->a_data->best_movies->title,fp1);
  	p->a_data->best_movies=p->a_data->best_movies->next;

  	if(p->a_data->best_movies!=NULL)
  	{
  		while(1)
  		{
  			fprintf(fp1,",");
  			fputs(p->a_data->best_movies->title,fp1);
  			p->a_data->best_movies=p->a_data->best_movies->next;
  			if(p->a_data->best_movies==NULL)
  			break;
  		}
  	}

  	fprintf(fp1,"\n");
  	fclose(fp1);
		p -> next = p -> next -> next;
    free(tmp);
    printf("Done@@\n");
	}
}
void delete_d(director * p, char * opt2){
  int num = atoi(opt2);
   printf("%d\n",num);
  int number = Last_number_d(p);
   printf("%d\n", number);
  if(num > number){
    printf("No such record\n");
  }
  else if(num == 1)
  {
      director * start;
      start = p;
		FILE *fp1=fopen("director_log","a");
		fprintf(fp1,"delete:");
		fprintf(fp1,"%d:",start->d_data->serial_number);
		fputs(start->d_data->name,fp1);
		fprintf(fp1,":");
		fputs(&start->d_data->sex,fp1);
		fprintf(fp1,":");
		fputs(start->d_data->birth,fp1);
		fprintf(fp1,":");
		fputs(start->d_data->best_movies->title,fp1);
		p->d_data->best_movies=p->d_data->best_movies->next;

		if(p->d_data->best_movies!=NULL)
		{
			while(1)
			{
				fprintf(fp1,",");
				fputs(p->d_data->best_movies->title,fp1);
				p->d_data->best_movies=p->d_data->best_movies->next;
				if(p->d_data->best_movies==NULL)
				break;
			}
		}
		fprintf(fp1,"\n");
		fclose(fp1);
		free(start);
    printf("Done@@\n");
	}
  else
  {
    int y;
    director * tmp;
    for(y=1; y<num-1; y++)
    {
      p = p->next;
    }
    tmp  = p -> next;
		FILE *fp1=fopen("director_log","a");
		fprintf(fp1,"delete:");
		fprintf(fp1,"%d:",tmp->d_data->serial_number);
		fputs(tmp->d_data->name,fp1);
		fprintf(fp1,":");
		fputs(&tmp->d_data->sex,fp1);
		fprintf(fp1,":");
		fputs(tmp->d_data->birth,fp1);
		fprintf(fp1,":");
		fputs(tmp->d_data->best_movies->title,fp1);
		p->d_data->best_movies=p->d_data->best_movies->next;

		if(p->d_data->best_movies!=NULL)
		{
			while(1)
			{
				fprintf(fp1,",");
				fputs(p->d_data->best_movies->title,fp1);
				p->d_data->best_movies=p->d_data->best_movies->next;
				if(p->d_data->best_movies==NULL)
				break;
			}
		}
		fprintf(fp1,"\n");
		fclose(fp1);
		free(tmp);
    printf("Done@@\n");
	}
}
void delete_m(movie * p, char * opt2){
	 int num = atoi(opt2);
	 printf("%d\n",num);
	 int number = Last_number_m(p);
	 printf("%d\n", number);
	 if(num > number){
		 printf("No such record\n");
	 }
	 else if(num == 1)
	 {
		 movie * start = p;
		 FILE *fp1=fopen("movie_log","a");
	 	fprintf(fp1,"delete:");
	 	fprintf(fp1,"%d:",start->m_data->serial_number);
	 	fputs(start->m_data->title,fp1);
	 	fprintf(fp1,":");
	 	fputs(start->m_data->genre,fp1);
	 	fprintf(fp1,":");
	 	fputs(start->m_data->director->director,fp1);
	 	fprintf(fp1,":");
	 	fputs(start->m_data->year,fp1);
	 	fprintf(fp1,":");
	 	fputs(start->m_data->runtime,fp1);
	 	fprintf(fp1,":");
	 	fputs(start->m_data->actors->actor,fp1);
	 	p->m_data->actors=p->m_data->actors->next;

	 	if(p->m_data->actors!=NULL)
	 	{
	 		while(1)
	 		{
	 			fprintf(fp1,",");
	 			fputs(p->m_data->actors->actor,fp1);
	 			p->m_data->actors=p->m_data->actors->next;
	 			if(p->m_data->actors==NULL)
	 				break;
	 		}
	 	}
	 	fprintf(fp1,"\n");
	 	fclose(fp1);
		 free(start);
		 printf("@@Done");
	 }
	 else
	 {
		 int y;
		 movie * tmp;
		 for(y=1; y<num-1; y++)
		 {
			 p = p->next;
		 }
		 tmp  = p -> next;
		 FILE *fp1=fopen("movie_log","a");
	 	fprintf(fp1,"delete:");
	 	fprintf(fp1,"%d:",tmp->m_data->serial_number);
	 	fputs(tmp->m_data->title,fp1);
	 	fprintf(fp1,":");
	 	fputs(tmp->m_data->genre,fp1);
	 	fprintf(fp1,":");
	 	fputs(tmp->m_data->director->director,fp1);
	 	fprintf(fp1,":");
	 	fputs(tmp->m_data->year,fp1);
	 	fprintf(fp1,":");
	 	fputs(tmp->m_data->runtime,fp1);
	 	fprintf(fp1,":");
	 	fputs(tmp->m_data->actors->actor,fp1);
	 	p->m_data->actors=p->m_data->actors->next;

	 	if(p->m_data->actors!=NULL)
	 	{
	 		while(1)
	 		{
	 			fprintf(fp1,",");
	 			fputs(p->m_data->actors->actor,fp1);
	 			p->m_data->actors=p->m_data->actors->next;
	 			if(p->m_data->actors==NULL)
	 				break;
	 		}
	 	}
	 	fprintf(fp1,"\n");
	 	fclose(fp1);
		 p -> next = p -> next -> next;
		 free(tmp);
		 printf("Done@@\n");
	 }
