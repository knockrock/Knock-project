#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void m_update(movie * M_L, int optcnt, char * opt2, int opt3)
{
	if(optcnt!=3)
		printf("Please enter the all options.\n"); //옵션 갯수가 3개가 아니면 실행x
	else
	{
		int num = opt3;
		movie * tmp_M_L;
		tmp_M_L = M_L;
		while(1)
		{
			if(M_L->m_data.serial_number==num)
				break;
			if(M_L->m_data.serial_number>num||(M_L->next==NULL&&num>M_L->m_data.serial_number))
				{
					printf("@@ No such record.\n");
					return ;
				}
			M_L=M_L->next;
		}
		FILE * fp = fopen("movie_log","a");
		fprintf(fp,"update:%d:",M_L->m_data.serial_number);
		if(strchr(opt2,'t')!=NULL||strchr(opt2,'g')!=NULL||strchr(opt2,'d')!=NULL||strchr(opt2,'y')!=NULL||strchr(opt2,'r')!=NULL||strchr(opt2,'a')!=NULL)
		{
			if(strchr(opt2,'t')!=NULL)
			{
				char * af_title = (char*)malloc(100);
				printf("title > ");
				gets(af_title);
				M_L=tmp_M_L;
				while(M_L->next!=NULL)
				{
					if(strcmp(M_L->m_data.title, af_title) == 0)
					{
						printf("@@ You have the same record in movie list.\n");
						printf("%d:%s:%s:%s:%s:%s:",M_L->m_data.serial_number,M_L->m_data.title,M_L->m_data.genre,M_L->m_data.director->director,M_L->m_data.year,M_L->m_data.runtime);
						printf("%s",M_L->m_data.actors->actor);
						while(M_L->m_data.actors->next!=NULL)
						{
							printf(",");
							printf("%s",M_L->m_data.actors->next->actor);
							M_L->m_data.actors=M_L->m_data.actors->next;
						}
						printf("\n");
						printf("@@ Do you want to update any way?(Yes/No) ");
						char *c = (char*)malloc(sizeof(char*)*10);
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
							free(af_title);
							return;
						}
						else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
						{
							M_L=M_L->next;
							continue;
						}
					}
					M_L=M_L->next;
				}
				M_L=tmp_M_L;
				while(M_L->m_data.serial_number!=num)
					M_L=M_L->next;
				free(M_L->m_data.title);
				M_L->m_data.title = af_title;
				fprintf(fp,"%s:",M_L->m_data.title);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'g')!=NULL)
			{
				char * af_genre = (char*)malloc(100);
				printf("genre > ");
				gets(af_genre);
				M_L->m_data.genre = af_genre;
				fprintf(fp,"%s:",M_L->m_data.genre);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'d')!=NULL)
			{
				char * af_director = (char*)malloc(100);
				printf("director > ");
				gets(af_director);
				M_L->m_data.director->director = af_director;
				fprintf(fp,"%s:",M_L->m_data.director->director);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'y')!=NULL)
			{
				char * af_year = (char *)malloc(100);
				printf("year > ");
				gets(af_year);
				M_L->m_data.year = af_year;
				fprintf(fp,"%s:",M_L->m_data.year);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'r')!=NULL)
			{
				char * af_runtime = (char*)malloc(100);
				printf("runtime > ");
				gets(af_runtime);
				M_L->m_data.runtime = af_runtime;
				fprintf(fp,"%s:",M_L->m_data.runtime);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'a')!=NULL)
			{
				char * af_actors = (char*)malloc(sizeof(char)*100);
				to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
				tmp->actor = NULL;
				tmp->next=NULL;
				tmp = M_L->m_data.actors;
				movie * tmp_M_L = M_L;
				printf("actors > ");
				gets(af_actors);
				fprintf(fp,"%s\n",af_actors);
				if(M_L->m_data.actors->next!=NULL)
				{
					while(1)
					{
						while(M_L->m_data.actors->next->next!=NULL)
							M_L->m_data.actors=M_L->m_data.actors->next;
						free(M_L->m_data.actors->next);
						M_L->m_data.actors->next=NULL;
						M_L->m_data.actors=tmp;
						if(M_L->m_data.actors->next==NULL)
							break;
					}
				}
				M_L->m_data.actors -> actor = strtok(af_actors,",");

				while(1)
				{
					link_actor(M_L->m_data.actors);
					while(M_L->m_data.actors->next->next!=NULL)
						M_L->m_data.actors=M_L->m_data.actors->next;
					if(M_L->m_data.actors->next->actor == NULL)
					{
						free(M_L->m_data.actors->next);
						M_L->m_data.actors->next=NULL;
						break;
					}
				}
				M_L->m_data.actors=tmp;
			}
			else
				fprintf(fp,"=\n");
		}
		else
			printf("Please enter the option correctly.\n");
	}
}

void d_update(director * D_L, int optcnt, char * opt2, int opt3)
{
	if(optcnt!=3)
		printf("Please enter the all options.\n");
	else
	{
		int num = opt3;
		director * tmp_D_L;
		tmp_D_L = D_L;
		while(D_L->next!=NULL)
			D_L=D_L->next;
		if(num>D_L->d_data.serial_number)
		{
			printf("@@ No such record.\n");
			return ;
		}
		D_L=tmp_D_L;
		while(D_L->d_data.serial_number!=num)
			D_L=D_L->next;
		FILE * fp = fopen("director_log","a");
		fprintf(fp,"update:%d:",D_L->d_data.serial_number);
		if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
		{
			if(strchr(opt2,'n')!=NULL)
			{
				char * af_name = (char*)malloc(100);
				printf("name > ");
				gets(af_name);
				D_L=tmp_D_L;
				while(D_L->next!=NULL)
				{
					if(strcmp(D_L->d_data.name, af_name) == 0)
					{
						printf("@@ You have the same record in director list.\n");
						printf("%d:%s:%s:%s:",D_L->d_data.serial_number,D_L->d_data.name,&D_L->d_data.sex,D_L->d_data.birth);
						printf("%s",D_L->d_data.best_movies->title);
						while(D_L->d_data.best_movies->next!=NULL)
						{
							printf(",");
							printf("%s",D_L->d_data.best_movies->next->title);
							D_L->d_data.best_movies=D_L->d_data.best_movies->next;
						}
						printf("\n");
						printf("@@ Do you want to update any way?(Yes/No) ");
						char *c = (char*)malloc(sizeof(char*)*10);
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
							free(af_name);
							return;
						}
						else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
						{
							D_L=D_L->next;
							continue;
						}
					}
					D_L=D_L->next;
				}
				D_L=tmp_D_L;
				while(D_L->d_data.serial_number!=num)
					D_L=D_L->next;
				free(D_L->d_data.name);
				D_L->d_data.name = af_name;
				fprintf(fp,"%s:",D_L->d_data.name);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'s')!=NULL)
			{
				char af_sex;
				printf("sex > ");
				gets(&af_sex);
				D_L->d_data.sex = af_sex;
				fprintf(fp,"%c:",D_L->d_data.sex);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'b')!=NULL)
			{
				char * af_birth = (char*)malloc(100);
				printf("birth > ");
				gets(af_birth);
				D_L->d_data.birth = af_birth;
				fprintf(fp,"%s:",D_L->d_data.birth);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'m')!=NULL)
			{
				char * af_best_movies = (char*)malloc(sizeof(char)*100);
				to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
				tmp->title = NULL;
				tmp->next=NULL;
				tmp = D_L->d_data.best_movies;
				director * tmp_D_L = D_L;
				printf("best_movies > ");
				gets(af_best_movies);
				fprintf(fp,"%s\n",af_best_movies);
				if(D_L->d_data.best_movies->next!=NULL)
				{
					while(1)
					{
						while(D_L->d_data.best_movies->next->next!=NULL)
							D_L->d_data.best_movies=D_L->d_data.best_movies->next;
						free(D_L->d_data.best_movies->next);
						D_L->d_data.best_movies->next=NULL;
						D_L->d_data.best_movies=tmp;
						if(D_L->d_data.best_movies->next==NULL)
							break;
					}
				}
				D_L->d_data.best_movies -> title = strtok(af_best_movies,",");

				while(1)
				{
					link_title(D_L->d_data.best_movies);
					while(D_L->d_data.best_movies->next->next!=NULL)
						D_L->d_data.best_movies=D_L->d_data.best_movies->next;
					if(D_L->d_data.best_movies->next->title == NULL)
					{
						free(D_L->d_data.best_movies->next);
						D_L->d_data.best_movies->next=NULL;
						break;
					}
				}
				D_L->d_data.best_movies=tmp;
			}
			else
				fprintf(fp,"=\n");
		}
		else
			printf("Please enter the option correctly.\n");
	}
}

void a_update(actor * A_L, int optcnt, char * opt2, int opt3)
{
	if(optcnt!=3)
		printf("Please enter the all options.\n");
	else
	{
		int num = opt3;
		actor * tmp_A_L;
		tmp_A_L = A_L;
		while(A_L->next!=NULL)
			A_L=A_L->next;
		if(num>A_L->a_data.serial_number)
		{
			printf("@@ No such record.\n");
			return ;
		}
		A_L=tmp_A_L;
		while(A_L->a_data.serial_number!=num)
			A_L=A_L->next;
		FILE * fp = fopen("actor_log","a");
		fprintf(fp,"update:%d:",A_L->a_data.serial_number);
		if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
		{
			if(strchr(opt2,'n')!=NULL)
			{
				char * af_name = (char*)malloc(100);
				printf("name > ");
				gets(af_name);
				A_L=tmp_A_L;
				while(A_L->next!=NULL)
				{
					if(strcmp(A_L->a_data.name, af_name) == 0)
					{
						printf("@@ You have the same record in director list.\n");
						printf("%d:%s:%s:%s:",A_L->a_data.serial_number,A_L->a_data.name,&A_L->a_data.sex,A_L->a_data.birth);
						printf("%s",A_L->a_data.best_movies->title);
						while(A_L->a_data.best_movies->next!=NULL)
						{
							printf(",");
							printf("%s",A_L->a_data.best_movies->next->title);
							A_L->a_data.best_movies=A_L->a_data.best_movies->next;
						}
						printf("\n");
						printf("@@ Do you want to update any way?(Yes/No) ");
						char *c = (char*)malloc(sizeof(char*)*10);
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
							free(af_name);
							return;
						}
						else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
						{
							A_L=A_L->next;
							continue;
						}
					}
					A_L=A_L->next;
				}
				A_L=tmp_A_L;
				while(A_L->a_data.serial_number!=num)
					A_L=A_L->next;
				free(A_L->a_data.name);
				A_L->a_data.name = af_name;
				fprintf(fp,"%s:",A_L->a_data.name);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'s')!=NULL)
			{
				char af_sex;
				printf("sex > ");
				gets(&af_sex);
				A_L->a_data.sex = af_sex;
				fprintf(fp,"%c:",A_L->a_data.sex);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'b')!=NULL)
			{
				char * af_birth = (char*)malloc(100);
				printf("birth > ");
				gets(af_birth);
				A_L->a_data.birth = af_birth;
				fprintf(fp,"%s:",A_L->a_data.birth);
			}
			else
				fprintf(fp,"=:");
			if(strchr(opt2,'m')!=NULL)
			{
				char * af_best_movies = (char*)malloc(sizeof(char)*100);
				to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
				tmp->title = NULL;
				tmp->next=NULL;
				tmp = A_L->a_data.best_movies;
				actor * tmp_a_L = A_L;
				printf("best_movies > ");
				gets(af_best_movies);
				fprintf(fp,"%s\n",af_best_movies);
				if(A_L->a_data.best_movies->next!=NULL)
				{
					while(1)
					{
						while(A_L->a_data.best_movies->next->next!=NULL)
							A_L->a_data.best_movies=A_L->a_data.best_movies->next;
						free(A_L->a_data.best_movies->next);
						A_L->a_data.best_movies->next=NULL;
						A_L->a_data.best_movies=tmp;
						if(A_L->a_data.best_movies->next==NULL)
							break;
					}
				}
				A_L->a_data.best_movies -> title = strtok(af_best_movies,",");

				while(1)
				{
					link_title(A_L->a_data.best_movies);
					while(A_L->a_data.best_movies->next->next!=NULL)
						A_L->a_data.best_movies=A_L->a_data.best_movies->next;
					if(A_L->a_data.best_movies->next->title == NULL)
					{
						free(A_L->a_data.best_movies->next);
						A_L->a_data.best_movies->next=NULL;
						break;
					}
				}
				A_L->a_data.best_movies=tmp;
			}
			else
				fprintf(fp,"=\n");
		}
		else
			printf("Please enter the option correctly.\n");
	}
}
