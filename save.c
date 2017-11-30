#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void m_save(movie *M_L, char * opt2, char* opt3, char* opt4) //movie 리스트 파일에 저장
{
	if(opt3!=NULL)
		if(strcmp(opt3,"-f")!=0)
		{
			opt4 = "movie_list";
		}
	FILE * fp = fopen(opt4,"w");

	while(M_L!=NULL)
	{
		fprintf(fp,"%d",M_L->m_data->serial_number);
		if(strchr(opt2,'t')!=NULL)
		{
			fprintf(fp,":");
			fputs(M_L->m_data->title,fp);
		}
		if(strchr(opt2,'g')!=NULL)
		{
			fprintf(fp,":");
			fputs(M_L->m_data->genre,fp);
		}
		if(strchr(opt2,'d')!=NULL)
		{
			fprintf(fp,":");
			fputs(M_L->m_data->director->director,fp);
		}
		if(strchr(opt2,'y')!=NULL)
		{
			fprintf(fp,":");
			fputs(M_L->m_data->year,fp);
		}
		if(strchr(opt2,'r')!=NULL)
		{
			fprintf(fp,":");
			fputs(M_L->m_data->runtime,fp);
		}
		if(strchr(opt2,'a')!=NULL)
		{
			to_actor * tmp = (to_actor*)malloc(sizeof(to_actor));
			tmp = M_L->m_data->actors;
			fprintf(fp,":");
			fputs(M_L->m_data->actors->actor,fp);
			while(M_L->m_data->actors->next!=NULL)
				{
					M_L->m_data->actors=M_L->m_data->actors->next;
					fputs(M_L->m_data->actors->actor,fp);
					fprintf(fp,",");
				}
				fputs(M_L->m_data->actors->actor,fp);
				M_L->m_data->actors = tmp;
		}
		if(opt2==NULL)
		{
			to_actor * tmp = (to_actor*)malloc(sizeof(to_actor));
			tmp = M_L->m_data->actors;
			fprintf(fp,":");
			fputs(M_L->m_data->title,fp);
			fprintf(fp,":");
			fputs(M_L->m_data->genre,fp);
			fprintf(fp,":");
			fputs(M_L->m_data->director->director,fp);
			fprintf(fp,":");
			fputs(M_L->m_data->year,fp);
			fprintf(fp,":");
			fputs(M_L->m_data->runtime,fp);
			fprintf(fp,":");
			fputs(M_L->m_data->actors->actor,fp);
			while(M_L->m_data->actors->next!=NULL)
				{
					M_L->m_data->actors=M_L->m_data->actors->next;
					fputs(M_L->m_data->actors->actor,fp);
					fprintf(fp,",");
				}
				fputs(M_L->m_data->actors->actor,fp);
				M_L->m_data->actors = tmp;
		}
		fprintf(fp,"\n");
		M_L= M_L->next;
	}
}
void d_save(director * D_L, char * opt2, char* opt3, char* opt4) //director 리스트 파일에 저장
{
	if(opt3!=NULL)
	{
		if(strcmp(opt3,"-f")!=0)
		{
			opt4 = "movie_list";
		}
		FILE * fp = fopen(opt4,"w");

		while(D_L!=NULL)
		{
			fprintf(fp,"%d",D_L->d_data->serial_number);
			if(strchr(opt2,'n')!=NULL)
			{
				fprintf(fp,":");
				fputs(D_L->d_data->name,fp);
			}
			if(strchr(opt2,'s')!=NULL)
			{
				fprintf(fp,":");
				fputs(&D_L->d_data->sex,fp);
			}
			if(strchr(opt2,'b')!=NULL)
			{
				fprintf(fp,":");
				fputs(D_L->d_data->birth,fp);
			}
			if(strchr(opt2,'m')!=NULL)
			{
				to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
				tmp = D_L->d_data->best_movies;
				fprintf(fp,":");
				fputs(D_L->d_data->best_movies->title,fp);
				while(D_L->d_data->best_movies->next!=NULL)
					{
						D_L->d_data->best_movies=D_L->d_data->best_movies->next;
						fputs(D_L->d_data->best_movies->title,fp);
						fprintf(fp,",");
					}
					fputs(D_L->d_data->best_movies->title,fp);
					D_L->d_data->best_movies = tmp;
			}
			if(opt2==NULL)
			{
				fprintf(fp,":");
				fputs(D_L->d_data->name,fp);
				fprintf(fp,":");
				fputs(&D_L->d_data->sex,fp);
				fprintf(fp,":");
				fputs(D_L->d_data->birth,fp);
				to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
				tmp = D_L->d_data->best_movies;
				fprintf(fp,":");
				fputs(D_L->d_data->best_movies->title,fp);
				while(D_L->d_data->best_movies->next!=NULL)
					{
						D_L->d_data->best_movies=D_L->d_data->best_movies->next;
						fputs(D_L->d_data->best_movies->title,fp);
						fprintf(fp,",");
					}
					fputs(D_L->d_data->best_movies->title,fp);
					D_L->d_data->best_movies = tmp;
			}
			fprintf(fp,"\n");
			D_L = D_L->next;
		}
	}
}
void a_save(actor * A_L, char * opt2, char* opt3, char* opt4) //actor 리스트 파일에 저장
{
	if(opt3!=NULL)
	{
		if(strcmp(opt3,"-f")!=0)
		{
			opt4 = "movie_list";
		}
		FILE * fp = fopen(opt4,"w");

		while(A_L!=NULL)
		{
			fprintf(fp,"%d",A_L->a_data->serial_number);
			if(strchr(opt2,'n')!=NULL)
			{
				fprintf(fp,":");
				fputs(A_L->a_data->name,fp);
			}
			if(strchr(opt2,'s')!=NULL)
			{
			fprintf(fp,":");
			fputs(&A_L->a_data->sex,fp);
			}
			if(strchr(opt2,'b')!=NULL)
			{
				fprintf(fp,":");
				fputs(A_L->a_data->birth,fp);
			}
			if(strchr(opt2,'m')!=NULL)
			{
				to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
				tmp = A_L->a_data->best_movies;
				fprintf(fp,":");
				fputs(A_L->a_data->best_movies->title,fp);
				while(A_L->a_data->best_movies->next!=NULL)
					{
						A_L->a_data->best_movies=A_L->a_data->best_movies->next;
						fputs(A_L->a_data->best_movies->title,fp);
						fprintf(fp,",");
					}
					fputs(A_L->a_data->best_movies->title,fp);
					A_L->a_data->best_movies = tmp;
			}
			if(opt2==NULL)
			{
				fprintf(fp,":");
				fputs(A_L->a_data->name,fp);
				fprintf(fp,":");
				fputs(&A_L->a_data->sex,fp);
				fprintf(fp,":");
				fputs(A_L->a_data->birth,fp);
				to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
				tmp = A_L->a_data->best_movies;
				fprintf(fp,":");
				fputs(A_L->a_data->best_movies->title,fp);
				while(A_L->a_data->best_movies->next!=NULL)
					{
						A_L->a_data->best_movies=A_L->a_data->best_movies->next;
						fputs(A_L->a_data->best_movies->title,fp);
						fprintf(fp,",");
					}
					fputs(A_L->a_data->best_movies->title,fp);
					A_L->a_data->best_movies = tmp;
			}
			fprintf(fp,"\n");
			A_L = A_L->next;
		}
	}
}
