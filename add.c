#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void link_actor(to_actor * actor) //배우 리스트 연결
{
	while(actor->next!=NULL)
		actor=actor->next;
	actor->next = (to_actor *)malloc(sizeof(to_actor));
	actor->next->actor = (char *)malloc(sizeof(char)*100);
	actor->next->actor = strtok(NULL,",");
	actor->next->next = NULL;
}
void movie_log(movie * M_L) // movie에 add 로그 기록
{
	to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
	tmp->actor = NULL;
	tmp->next=NULL;
	tmp = M_L->m_data.actors;

	while(M_L->next!=NULL)
		M_L=M_L->next;
	FILE *fp1=fopen("movie_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",M_L->m_data.serial_number);
	fputs(M_L->m_data.title,fp1);
	fprintf(fp1,":");
	fputs(M_L->m_data.genre,fp1);
	fprintf(fp1,":");
	fputs(M_L->m_data.director->director,fp1);
	fprintf(fp1,":");
	fputs(M_L->m_data.year,fp1);
	fprintf(fp1,":");
	fputs(M_L->m_data.runtime,fp1);
	fprintf(fp1,":");
	fputs(M_L->m_data.actors->actor,fp1);
	M_L->m_data.actors=M_L->m_data.actors->next;

	if(M_L->m_data.actors!=NULL)
	{
		while(1)
		{
			fprintf(fp1,",");
			fputs(M_L->m_data.actors->actor,fp1);
			M_L->m_data.actors=M_L->m_data.actors->next;
			if(M_L->m_data.actors==NULL)
				break;
		}
	}
	M_L->m_data.actors = tmp;
	fprintf(fp1,"\n");
	fclose(fp1);
}
m_node * input_M_node() // movie 노드 추가
{
	m_node * newnode=(m_node*)malloc(sizeof(m_node));
	newnode->serial_number=1;
	newnode->title=(char*)malloc(sizeof(char)*100);
	newnode->genre=(char*)malloc(sizeof(char)*100);
	newnode->year=(char*)malloc(sizeof(char)*100);
	newnode->runtime=(char*)malloc(sizeof(char)*100);
	char * tmp_actors = (char*)malloc(sizeof(char)*100);
	newnode->actors = (to_actor *)malloc(sizeof(to_actor));
	newnode->actors -> actor  = (char*)malloc(sizeof(char)*100);
	newnode->actors -> next = NULL;
	newnode->actors->same_actor = NULL;
	newnode->director = (to_director *)malloc(sizeof(to_director));
	newnode->director->director = (char*)malloc(sizeof(char)*100);
	newnode->director->same_director = NULL;
	to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
	tmp->actor = NULL;
	tmp->next=NULL;
	tmp = newnode->actors;

	printf("title > ");
	gets(newnode->title);
	printf("genre > ");
	gets(newnode->genre);
	printf("director > ");
	gets(newnode->director->director);
	printf("year > ");
	gets(newnode->year);
	printf("runtime > ");
	gets(newnode->runtime);
	printf("actors > ");
	gets(tmp_actors);
	printf("@@ Done\n");
	newnode->actors -> actor = strtok(tmp_actors,",");

	while(1)
	{
		link_actor(newnode->actors);
		while(newnode->actors->next->next!=NULL)
			newnode->actors=newnode->actors->next;
		if(newnode->actors->next->actor == NULL)
		{
			free(newnode->actors->next);
			newnode->actors->next=NULL;
			break;
		}
	}
	newnode->actors=tmp;

	char * string = (char*)malloc(200);
	FILE * rfp = fopen("movie_log","r");
	int a=(fseek(rfp,0,0),ftell(rfp)), b=(fseek(rfp,0,2),ftell(rfp));
	if(a==b)
	{
		newnode->serial_number=1;
	}
	else
	{
		rewind(rfp);
		char c;
		while((c=fgetc(rfp))!=EOF)
		{
			fseek(rfp,-1,SEEK_CUR);
			fgets(string,175,rfp);
			if(strcmp(strtok(string,":"),"add") == 0)
			{
				newnode->serial_number+=1;
			}
		}
	}
	fclose(rfp);
	return newnode;
}
void init_M_node(movie ** Movie, m_node * newnode) // 처음 movie 노드 리스트에 연결
{
	*Movie = (movie *)malloc(sizeof(movie));
	(*Movie)->m_data = (*newnode);
	(*Movie)->next = NULL;
}
void link_M_node(movie * M_L, m_node * newnode) // 처음이 아닌 movie 노드 리스트에 연결
{
	while(M_L->next!=NULL)
		M_L=M_L->next;
	M_L->next = (movie*)malloc(sizeof(movie));
	M_L->next->m_data = (*newnode);
	M_L->next->next = NULL;
}
void check_m_node(movie * M_L, m_node * newnode) // movie 연결리스트에 중복인지 아닌지 확인
{
	to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
	movie * tmp_M_L = (movie*)malloc(sizeof(movie));
	tmp->next=NULL;
	tmp_M_L = M_L;
	while(M_L->next!=NULL)
		M_L=M_L->next;
	tmp = M_L->m_data.actors;
	M_L = tmp_M_L;
	while(M_L->next!=NULL)
	{
		if(strcmp(M_L->m_data.title, newnode->title) == 0) //기존의 존재하는 노드의 데이터와 새로 받은 노드의 데이터가 같은지 확인
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
			printf("@@ Do you want to add any way?(Yes/No) ");
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
				while(M_L->next->next!=NULL)
				{
					M_L=M_L->next;
				}
				free(M_L->next);
				M_L->next=NULL;
				M_L->m_data.actors=tmp;
				return;
			}//n일 경우 함수 리턴
			else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
			{
				M_L=M_L->next;
				continue;
			}//y일 경우 그대로 반복문 진행
		}
		M_L=M_L->next;
	}
	M_L->m_data.actors=tmp;
	movie_log(M_L);
}

void link_title(to_movie * title) //영화 제목 리스트 연결
{
	while(title->next!=NULL)
		title=title->next;
	title->next = (to_movie *)malloc(sizeof(to_movie));
	title->next->title = (char *)malloc(sizeof(char)*100);
	title->next->title = strtok(NULL,",");
	title->next->next = NULL;
}
void director_log(director * D_L) // director에 add 로그 기록
{
	to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
	tmp->title = NULL;
	tmp->next=NULL;
	tmp = D_L->d_data.best_movies;

	while(D_L->next!=NULL)
		D_L=D_L->next;
	FILE *fp1=fopen("director_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",D_L->d_data.serial_number);
	fputs(D_L->d_data.name,fp1);
	fprintf(fp1,":");
	fputs(&D_L->d_data.sex,fp1);
	fprintf(fp1,":");
	fputs(D_L->d_data.birth,fp1);
	fprintf(fp1,":");
	fputs(D_L->d_data.best_movies->title,fp1);
	D_L->d_data.best_movies=D_L->d_data.best_movies->next;

	if(D_L->d_data.best_movies!=NULL)
	{
		while(1)
		{
			fprintf(fp1,",");
			fputs(D_L->d_data.best_movies->title,fp1);
			D_L->d_data.best_movies=D_L->d_data.best_movies->next;
			if(D_L->d_data.best_movies==NULL)
				break;
		}
	}
	D_L->d_data.best_movies=tmp;
	fprintf(fp1,"\n");
	fclose(fp1);
}
d_node * input_D_node() //director 노드 추가
{
	d_node * newnode=(d_node*)malloc(sizeof(d_node));
	newnode->serial_number=1;
	newnode->name=(char*)malloc(sizeof(char)*100);
	newnode->birth=(char*)malloc(sizeof(char)*100);
	char * tmp_best_movies = (char*)malloc(sizeof(char)*100);
	newnode->best_movies = (to_movie *)malloc(sizeof(to_movie));
	newnode->best_movies->title  = (char*)malloc(sizeof(char)*100);
	newnode->best_movies -> next = NULL;
	newnode->best_movies->same_title = NULL;
	to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
	tmp->title = NULL;
	tmp->next=NULL;
	tmp = newnode->best_movies;

	printf("name > ");
	gets(newnode->name);
	printf("sex > ");
	gets(&newnode->sex);
	printf("birth > ");
	gets(newnode->birth);
	printf("best_movies > ");
	gets(tmp_best_movies);
	printf("@@ Done\n");
	newnode->best_movies->title = strtok(tmp_best_movies,",");

	while(1)
	{
		link_title(newnode->best_movies);
		while(newnode->best_movies->next->next!=NULL)
			newnode->best_movies=newnode->best_movies->next;
		if(newnode->best_movies->next->title == NULL)
		{
			free(newnode->best_movies->next);
			newnode->best_movies->next=NULL;
			break;
		}
	}
	newnode->best_movies=tmp;

	char * string = (char*)malloc(200);
	FILE * rfp = fopen("director_log","r");
	int a=(fseek(rfp,0,0),ftell(rfp)), b=(fseek(rfp,0,2),ftell(rfp));
	if(a==b)
	{
		newnode->serial_number=1;
	}
	else
	{
		rewind(rfp);
		char c;
		while((c=fgetc(rfp))!=EOF)
		{
			fseek(rfp,-1,SEEK_CUR);
			fgets(string,175,rfp);
			if(strcmp(strtok(string,":"),"add") == 0)
			{
				newnode->serial_number+=1;
			}
		}
	}
	fclose(rfp);
	return newnode;
}
void init_D_node(director ** Director, d_node * newnode) //처음 director 노드 리스트에 연결
{
	*Director = (director *)malloc(sizeof(director));
	(*Director)->d_data = (*newnode);
	(*Director)->next = NULL;
}
void link_D_node(director * D_L, d_node * newnode) // 처음이 아닌 director 노드 리스트에 연결
{
	while(D_L->next!=NULL)
		D_L=D_L->next;
	D_L->next = (director*)malloc(sizeof(director));
	D_L->next->d_data = (*newnode);
	D_L->next->next = NULL;
}
void check_d_node(director * D_L, d_node * newnode) // director 연결리스트에 중복인지 아닌지 확인
{
		to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
	director * tmp_D_L = (director*)malloc(sizeof(director));
	tmp->next=NULL;
	tmp_D_L = D_L;
	while(D_L->next!=NULL)
		D_L=D_L->next;
	tmp = D_L->d_data.best_movies;
	D_L = tmp_D_L;
	while(D_L->next!=NULL)
	{
		if(strcmp(D_L->d_data.name, newnode->name) == 0)//기존의 존재하는 노드의 데이터와 새로 받은 노드의 데이터가 같은지 확인
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
			printf("@@ Do you want to add any way?(Yes/No) ");
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
				while(D_L->next->next!=NULL)
				{
					D_L=D_L->next;
				}
				free(D_L->next);
				D_L->next=NULL;
				D_L->d_data.best_movies=tmp;
				return;
			}//n일 경우 함수 리턴
			else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
			{
				D_L=D_L->next;
				continue;
			}//y일 경우 반복문 진행
		}
		D_L=D_L->next;
	}
	D_L->d_data.best_movies=tmp;
	director_log(D_L);
}

void actor_log(actor * A_L) //actor에 add 로그 기록
{
	to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
	tmp->title = NULL;
	tmp->next=NULL;
	tmp = A_L->a_data.best_movies;

	while(A_L->next!=NULL)
		A_L=A_L->next;
	FILE *fp1=fopen("actor_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",A_L->a_data.serial_number);
	fputs(A_L->a_data.name,fp1);
	fprintf(fp1,":");
	fputs(&A_L->a_data.sex,fp1);
	fprintf(fp1,":");
	fputs(A_L->a_data.birth,fp1);
	fprintf(fp1,":");
	fputs(A_L->a_data.best_movies->title,fp1);
	A_L->a_data.best_movies=A_L->a_data.best_movies->next;

	if(A_L->a_data.best_movies!=NULL)
	{
		while(1)
		{
			fprintf(fp1,",");
			fputs(A_L->a_data.best_movies->title,fp1);
			A_L->a_data.best_movies=A_L->a_data.best_movies->next;
			if(A_L->a_data.best_movies==NULL)
				break;
		}
	}
	A_L->a_data.best_movies=tmp;

	fprintf(fp1,"\n");
	fclose(fp1);
}
a_node * input_A_node() // actor 노드 추가
{
	a_node * newnode=(a_node*)malloc(sizeof(a_node));
	newnode->serial_number=1;
	newnode->name=(char*)malloc(sizeof(char)*100);
	newnode->birth=(char*)malloc(sizeof(char)*100);
	char * tmp_best_movies = (char*)malloc(sizeof(char)*100);
	newnode->best_movies = (to_movie *)malloc(sizeof(to_movie));
	newnode->best_movies->title  = (char*)malloc(sizeof(char)*100);
	newnode->best_movies -> next = NULL;
	newnode->best_movies->same_title=NULL;
	to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
	tmp->title = NULL;
	tmp->next=NULL;
	tmp = newnode->best_movies;

	printf("name > ");
	gets(newnode->name);
	printf("sex > ");
	gets(&newnode->sex);
	printf("birth > ");
	gets(newnode->birth);
	printf("best_movies > ");
	gets(tmp_best_movies);
	printf("@@ Done\n");
	newnode->best_movies->title = strtok(tmp_best_movies,",");

	while(1)
	{
		link_title(newnode->best_movies);
		while(newnode->best_movies->next->next!=NULL)
			newnode->best_movies=newnode->best_movies->next;
		if(newnode->best_movies->next->title == NULL)
		{
			free(newnode->best_movies->next);
			newnode->best_movies->next=NULL;
			break;
		}
	}
	newnode->best_movies=tmp;

	char * string = (char*)malloc(200);
	FILE * rfp = fopen("actor_log","r");
	int a=(fseek(rfp,0,0),ftell(rfp)), b=(fseek(rfp,0,2),ftell(rfp));
	if(a==b)
	{
		newnode->serial_number=1;
	}
	else
	{
		rewind(rfp);
		char c;
		while((c=fgetc(rfp))!=EOF)
		{
			fseek(rfp,-1,SEEK_CUR);
			fgets(string,175,rfp);
			if(strcmp(strtok(string,":"),"add") == 0)
			{
				newnode->serial_number+=1;
			}
		}
	}
	fclose(rfp);
	return newnode;
}
void init_A_node(actor ** Actor, a_node * newnode) //처음 actor 노드 리스트에 연결
{
	*Actor = (actor *)malloc(sizeof(actor));
	(*Actor)->a_data = (*newnode);
	(*Actor)->next = NULL;
}
void link_A_node(actor * A_L, a_node * newnode) // 처음이 아닌 actor 노드 리스트에 연결
{
	while(A_L->next!=NULL)
		A_L=A_L->next;
	A_L->next = (actor*)malloc(sizeof(actor));
	A_L->next->a_data = (*newnode);
	A_L->next->next = NULL;
}
void check_a_node(actor *A_L, a_node * newnode) // actor 연결리스트에 중복인지 아닌지 확인
{
	to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
	actor * tmp_A_L = (actor*)malloc(sizeof(actor));
	tmp->next=NULL;
	tmp_A_L = A_L;
	while(A_L->next!=NULL)
		A_L=A_L->next;
	tmp = A_L->a_data.best_movies;
	A_L = tmp_A_L;

	while(A_L->next!=NULL)
	{
		if(strcmp(A_L->a_data.name, newnode->name) == 0)//기존의 존재하는 노드의 데이터와 새로 받은 노드의 데이터가 같은지 확인
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
			printf("@@ Do you want to add any way?(Yes/No) ");
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
				while(A_L->next->next!=NULL)
				{
					A_L=A_L->next;
				}
				free(A_L->next);
				A_L->next=NULL;
				A_L->a_data.best_movies=tmp;
				return;
			}//n일 경우 함수 리턴
			else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
			{
				A_L=A_L->next;
				continue;
			}
		}//y일 경우 반복문 진행
		A_L=A_L->next;
	}
	A_L->a_data.best_movies = tmp;
	actor_log(A_L);
}
