#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void m_save(movie *M_L, int optcnt, char * opt2, char* opt3, char* opt4) //movie 리스트 파일에 저장
{
	if(optcnt==1)
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
		printf("@@ Done\n");
		fclose(fp);
	} // 받은 옵션이 하나일 경우 실행, movie_list파일을 열어 첫 노드부터 마지막 노드까지 파일출력.
	if(optcnt==2)
	{
		FILE * fp = fopen("movie_list","w");
		while(M_L!=NULL)
		{
			if(strchr(opt2,'t')!=NULL||strchr(opt2,'g')!=NULL||strchr(opt2,'d')!=NULL||strchr(opt2,'y')!=NULL||strchr(opt2,'r')!=NULL||strchr(opt2,'a')!=NULL)
			{
				fprintf(fp,"%d",M_L->m_data.serial_number);
				if(strchr(opt2,'t')!=NULL)
				{
					fprintf(fp,":");
					fputs(M_L->m_data.title,fp);
				}
				if(strchr(opt2,'g')!=NULL)
				{
					fprintf(fp,":");
					fputs(M_L->m_data.genre,fp);
				}
				if(strchr(opt2,'d')!=NULL)
				{
					fprintf(fp,":");
					fputs(M_L->m_data.director->director,fp);
				}
				if(strchr(opt2,'y')!=NULL)
				{
					fprintf(fp,":");
					fputs(M_L->m_data.year,fp);
				}
				if(strchr(opt2,'r')!=NULL)
				{
					fprintf(fp,":");
					fputs(M_L->m_data.runtime,fp);
				}
				if(strchr(opt2,'a')!=NULL)
				{
					to_actor * tmp = (to_actor*)malloc(sizeof(to_actor));
					tmp = M_L->m_data.actors;
					fprintf(fp,":");
					fputs(M_L->m_data.actors->actor,fp);
					while(M_L->m_data.actors->next!=NULL)
					{
						fprintf(fp,",%s",M_L->m_data.actors->next->actor);
						M_L->m_data.actors=M_L->m_data.actors->next;
					}
					M_L->m_data.actors = tmp;
				}
			}
			else
			{
				printf("@@ Please enter the option correctly. (t/g/d/y/r/a)\n");
				return ;
			}
			fprintf(fp,"\n");
			M_L= M_L->next;
		}
		printf("@@ Done\n");
		fclose(fp);
	}// 받은 option 이 두 개일 때 실행, 두번째 옵션의 값에 따라 필요한 데이터만을 movie_list에 파일출력
	if(optcnt==3)
	{
		if(strcmp(opt2,"-f")!=0)
		{
			printf("@@ Please enter the option correctly.\n");
		}
		else
		{
			FILE * fp = fopen(opt3,"w");
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
			printf("@@ Done\n");
			fclose(fp);
		}
	}//옵션이 3개일 때 실행, 첫 노드부터 마지막 노드까지 모든 데이터를 지정한 파일에 파일출력
	if(optcnt==4)
	{
		if(strcmp(opt3,"-f")!=0)
		{
			printf("@@ Please enter the option correctly.\n");
		}
		else
		{
			FILE * fp = fopen(opt4,"w");
			while(M_L!=NULL)
			{
				if(strchr(opt2,'t')!=NULL||strchr(opt2,'g')!=NULL||strchr(opt2,'d')!=NULL||strchr(opt2,'y')!=NULL||strchr(opt2,'r')!=NULL||strchr(opt2,'a')!=NULL)
				{
					fprintf(fp,"%d",M_L->m_data.serial_number);
					if(strchr(opt2,'t')!=NULL)
					{
						fprintf(fp,":");
						fputs(M_L->m_data.title,fp);
					}
					if(strchr(opt2,'g')!=NULL)
					{
						fprintf(fp,":");
						fputs(M_L->m_data.genre,fp);
					}
					if(strchr(opt2,'d')!=NULL)
					{
						fprintf(fp,":");
						fputs(M_L->m_data.director->director,fp);
					}
					if(strchr(opt2,'y')!=NULL)
					{
						fprintf(fp,":");
						fputs(M_L->m_data.year,fp);
					}
					if(strchr(opt2,'r')!=NULL)
					{
						fprintf(fp,":");
						fputs(M_L->m_data.runtime,fp);
					}
					if(strchr(opt2,'a')!=NULL)
					{
						to_actor * tmp = (to_actor*)malloc(sizeof(to_actor));
						tmp = M_L->m_data.actors;
						fprintf(fp,":");
						fputs(M_L->m_data.actors->actor,fp);
						while(M_L->m_data.actors->next!=NULL)
						{
							fprintf(fp,",%s",M_L->m_data.actors->next->actor);
							M_L->m_data.actors=M_L->m_data.actors->next;
						}
						M_L->m_data.actors = tmp;
					}
				}
				else
				{
					printf("@@ Please enter the option correctly. (t/g/d/y/r/a)\n");
					return ;
				}
				fprintf(fp,"\n");
				M_L= M_L->next;
			}
			printf("@@ Done\n");
			fclose(fp);
		}
	}//옵션이 4개일 때 실행, 지정한 파일에 요구하는 옵션에 맞는 데이터를 모든 노드에 걸쳐 파일출력
}
void d_save(director * D_L, int optcnt, char * opt2, char* opt3, char* opt4) //director 리스트 파일에 저장
{
	if(optcnt==1)
	{
		FILE * fp = fopen("director_list","w");
		while(D_L!=NULL)
		{
			to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
			tmp = D_L->d_data.best_movies;
			fprintf(fp,"%d",D_L->d_data.serial_number);
			fprintf(fp,":");
			fputs(D_L->d_data.name,fp);
			fprintf(fp,":");
			fputs(&D_L->d_data.sex,fp);
			fprintf(fp,":");
			fputs(D_L->d_data.birth,fp);
			fprintf(fp,":");
			fputs(D_L->d_data.best_movies->title,fp);
			while(D_L->d_data.best_movies->next!=NULL)
			{
				fprintf(fp,",%s",D_L->d_data.best_movies->next->title);
				D_L->d_data.best_movies=D_L->d_data.best_movies->next;
			}
			D_L->d_data.best_movies = tmp;
			fprintf(fp,"\n");
			D_L= D_L->next;
		}
		printf("@@ Done\n");
		fclose(fp);
	}// 받은 옵션이 하나일 경우 실행, director_list파일을 열어 첫 노드부터 마지막 노드까지 파일출력.
	if(optcnt==2)
	{
		FILE * fp = fopen("director_list","w");
		while(D_L!=NULL)
		{
			if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
			{
				fprintf(fp,"%d",D_L->d_data.serial_number);
				if(strchr(opt2,'n')!=NULL)
				{
					fprintf(fp,":");
					fputs(D_L->d_data.name,fp);
				}
				if(strchr(opt2,'s')!=NULL)
				{
					fprintf(fp,":");
					fputs(&D_L->d_data.sex,fp);
				}
				if(strchr(opt2,'b')!=NULL)
				{
					fprintf(fp,":");
					fputs(D_L->d_data.birth,fp);
				}
				if(strchr(opt2,'m')!=NULL)
				{
					to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
					tmp = D_L->d_data.best_movies;
					fprintf(fp,":");
					fputs(D_L->d_data.best_movies->title,fp);
					while(D_L->d_data.best_movies->next!=NULL)
					{
						fprintf(fp,",%s",D_L->d_data.best_movies->next->title);
						D_L->d_data.best_movies=D_L->d_data.best_movies->next;
					}
					D_L->d_data.best_movies = tmp;
				}
			}
			else
			{
				printf("@@ Please enter the option correctly. (n/s/b/m)\n");
				return ;
			}
			fprintf(fp,"\n");
			D_L= D_L->next;
		}
		printf("@@ Done\n");
		fclose(fp);
	}// 받은 option 이 두 개일 때 실행, 두번째 옵션의 값에 따라 필요한 데이터만을 director_list에 파일출력
	if(optcnt==3)
	{
		if(strcmp(opt2,"-f")!=0)
		{
			printf("@@ Please enter the option correctly.\n");
		}
		else
		{
			FILE * fp = fopen(opt3,"w");
			while(D_L!=NULL)
			{
				to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
				tmp = D_L->d_data.best_movies;
				fprintf(fp,"%d",D_L->d_data.serial_number);
				fprintf(fp,":");
				fputs(D_L->d_data.name,fp);
				fprintf(fp,":");
				fputs(&D_L->d_data.sex,fp);
				fprintf(fp,":");
				fputs(D_L->d_data.birth,fp);
				fprintf(fp,":");
				fputs(D_L->d_data.best_movies->title,fp);
				while(D_L->d_data.best_movies->next!=NULL)
				{
					fprintf(fp,",%s",D_L->d_data.best_movies->next->title);
					D_L->d_data.best_movies=D_L->d_data.best_movies->next;
				}
				D_L->d_data.best_movies = tmp;
				fprintf(fp,"\n");
				D_L= D_L->next;
			}
			printf("@@ Done\n");
			fclose(fp);
		}
	}//옵션이 3개일 때 실행, 첫 노드부터 마지막 노드까지 모든 데이터를 지정한 파일에 파일출력
	if(optcnt==4)
	{
		if(strcmp(opt3,"-f")!=0)
		{
			printf("@@ Please enter the option correctly.\n");
		}
		else
		{
			FILE * fp = fopen(opt4,"w");
			while(D_L!=NULL)
			{
				if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
				{
					fprintf(fp,"%d",D_L->d_data.serial_number);
					if(strchr(opt2,'n')!=NULL)
					{
						fprintf(fp,":");
						fputs(D_L->d_data.name,fp);
					}
					if(strchr(opt2,'s')!=NULL)
					{
						fprintf(fp,":");
						fputs(&D_L->d_data.sex,fp);
					}
					if(strchr(opt2,'b')!=NULL)
					{
						fprintf(fp,":");
						fputs(D_L->d_data.birth,fp);
					}
					if(strchr(opt2,'m')!=NULL)
					{
						to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
						tmp = D_L->d_data.best_movies;
						fprintf(fp,":");
						fputs(D_L->d_data.best_movies->title,fp);
						while(D_L->d_data.best_movies->next!=NULL)
						{
							fprintf(fp,",%s",D_L->d_data.best_movies->next->title);
							D_L->d_data.best_movies=D_L->d_data.best_movies->next;
						}
						D_L->d_data.best_movies = tmp;
					}
				}
				else
				{
					printf("@@ Please enter the option correctly. (n/s/b/m)\n");
					return ;
				}
				fprintf(fp,"\n");
				D_L= D_L->next;
			}
			printf("@@ Done\n");
			fclose(fp);
		}
	}//옵션이 4개일 때 실행, 지정한 파일에 요구하는 옵션에 맞는 데이터를 모든 노드에 걸쳐 파일출력
}
void a_save(actor * A_L, int optcnt, char * opt2, char* opt3, char* opt4) //actor 리스트 파일에 저장
{
	if(optcnt==1)
	{
		FILE * fp = fopen("actor_list","w");
		while(A_L!=NULL)
		{
			to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
			tmp = A_L->a_data.best_movies;
			fprintf(fp,"%d",A_L->a_data.serial_number);
			fprintf(fp,":");
			fputs(A_L->a_data.name,fp);
			fprintf(fp,":");
			fputs(&A_L->a_data.sex,fp);
			fprintf(fp,":");
			fputs(A_L->a_data.birth,fp);
			fprintf(fp,":");
			fputs(A_L->a_data.best_movies->title,fp);
			while(A_L->a_data.best_movies->next!=NULL)
			{
				fprintf(fp,",%s",A_L->a_data.best_movies->next->title);
				A_L->a_data.best_movies=A_L->a_data.best_movies->next;
			}
			A_L->a_data.best_movies = tmp;
			fprintf(fp,"\n");
			A_L= A_L->next;
		}
		printf("@@ Done\n");
		fclose(fp);
	}// 받은 옵션이 하나일 경우 실행, actor_list파일을 열어 첫 노드부터 마지막 노드까지 파일출력.
	if(optcnt==2)
	{
		FILE * fp = fopen("actor_list","w");
		while(A_L!=NULL)
		{
			if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
			{
				fprintf(fp,"%d",A_L->a_data.serial_number);
				if(strchr(opt2,'n')!=NULL)
				{
					fprintf(fp,":");
					fputs(A_L->a_data.name,fp);
				}
				if(strchr(opt2,'s')!=NULL)
				{
					fprintf(fp,":");
					fputs(&A_L->a_data.sex,fp);
				}
				if(strchr(opt2,'b')!=NULL)
				{
					fprintf(fp,":");
					fputs(A_L->a_data.birth,fp);
				}
				if(strchr(opt2,'m')!=NULL)
				{
					to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
					tmp = A_L->a_data.best_movies;
					fprintf(fp,":");
					fputs(A_L->a_data.best_movies->title,fp);
					while(A_L->a_data.best_movies->next!=NULL)
					{
						fprintf(fp,",%s",A_L->a_data.best_movies->next->title);
						A_L->a_data.best_movies=A_L->a_data.best_movies->next;
					}
					A_L->a_data.best_movies = tmp;
				}
			}
			else
			{
				printf("@@ Please enter the option correctly. (n/s/b/m)\n");
				return ;
			}
			fprintf(fp,"\n");
			A_L= A_L->next;
		}
		printf("@@ Done\n");
		fclose(fp);
	}// 받은 option 이 두 개일 때 실행, 두번째 옵션의 값에 따라 필요한 데이터만을 actor_list에 파일출력
	if(optcnt==3)
	{
		if(strcmp(opt2,"-f")!=0)
		{
			printf("@@ Please enter the option correctly.\n");
		}
		else
		{
			FILE * fp = fopen(opt3,"w");
			while(A_L!=NULL)
			{
				to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
				tmp = A_L->a_data.best_movies;
				fprintf(fp,"%d",A_L->a_data.serial_number);
				fprintf(fp,":");
				fputs(A_L->a_data.name,fp);
				fprintf(fp,":");
				fputs(&A_L->a_data.sex,fp);
				fprintf(fp,":");
				fputs(A_L->a_data.birth,fp);
				fprintf(fp,":");
				fputs(A_L->a_data.best_movies->title,fp);
				while(A_L->a_data.best_movies->next!=NULL)
				{
					fprintf(fp,",%s",A_L->a_data.best_movies->next->title);
					A_L->a_data.best_movies=A_L->a_data.best_movies->next;
				}
				A_L->a_data.best_movies = tmp;
				fprintf(fp,"\n");
				A_L= A_L->next;
			}
			printf("@@ Done\n");
			fclose(fp);
		}
	}//옵션이 3개일 때 실행, 첫 노드부터 마지막 노드까지 모든 데이터를 지정한 파일에 파일출력
	if(optcnt==4)
	{
		if(strcmp(opt3,"-f")!=0)
		{
			printf("@@ Please enter the option correctly.\n");
		}
		else
		{
			FILE * fp = fopen(opt4,"w");
			while(A_L!=NULL)
			{
				if(strchr(opt2,'n')!=NULL||strchr(opt2,'s')!=NULL||strchr(opt2,'b')!=NULL||strchr(opt2,'m')!=NULL)
				{
					fprintf(fp,"%d",A_L->a_data.serial_number);
					if(strchr(opt2,'n')!=NULL)
					{
						fprintf(fp,":");
						fputs(A_L->a_data.name,fp);
					}
					if(strchr(opt2,'s')!=NULL)
					{
						fprintf(fp,":");
						fputs(&A_L->a_data.sex,fp);
					}
					if(strchr(opt2,'b')!=NULL)
					{
						fprintf(fp,":");
						fputs(A_L->a_data.birth,fp);
					}
					if(strchr(opt2,'m')!=NULL)
					{
						to_movie * tmp = (to_movie*)malloc(sizeof(to_movie));
						tmp = A_L->a_data.best_movies;
						fprintf(fp,":");
						fputs(A_L->a_data.best_movies->title,fp);
						while(A_L->a_data.best_movies->next!=NULL)
						{
							fprintf(fp,",%s",A_L->a_data.best_movies->next->title);
							A_L->a_data.best_movies=A_L->a_data.best_movies->next;
						}
						A_L->a_data.best_movies = tmp;
					}
				}
				else
				{
					printf("@@ Please enter the option correctly. (n/s/b/m)\n");
					return ;
				}
				fprintf(fp,"\n");
				A_L= A_L->next;
			}
			printf("@@ Done\n");
			fclose(fp);
		}
	}//옵션이 4개일 때 실행, 지정한 파일에 요구하는 옵션에 맞는 데이터를 모든 노드에 걸쳐 파일출력
}
