#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void movie_list();
void movie_log();
void add_M_node();
void director_list();
void director_log();
void add_D_node();
void actor_list();
void actor_log();
void add_A_node();

typedef struct movie_node{
	int * serial_number;
	char * title;
	char * genre;
	char * director;
	char * year;
	char * runtime;
	char * actors;
	struct movie_node *next;
}m_node;

typedef struct director_node{
	int *serial_number;
	char *name;
	char *sex;
	char *birth;
	char *best_movies;
	struct director_node *next;
}d_node;

typedef struct actor_node{
	int *serial_number;
	char *name;
	char *sex;
	char *birth;
	char *best_movies;
	struct actor_node *next;
}a_node;

typedef struct movie_list{
	m_node *tail;
}m_linkedlist;

typedef struct director_list{
	d_node *tail;
}d_linkedlist;

typedef struct actor_list{
	a_node *tail;
}a_linkedlist;

void add_M_node(m_linkedlist *L)
{
	m_node *newnode = (m_node*)malloc(sizeof(m_node));

	newnode->serial_number=(int*)malloc(sizeof(char)*3);
	newnode->title=(char*)malloc(sizeof(char)*50);
	newnode->genre=(char*)malloc(sizeof(char)*30);
	newnode->director=(char*)malloc(sizeof(char)*30);
	newnode->year=(char*)malloc(sizeof(char)*8);
	newnode->runtime=(char*)malloc(sizeof(char)*3);
	newnode->actors=(char*)malloc(sizeof(char)*50);
	//총183bite

	printf("title > ");
	gets(newnode->title);
	printf("genre > ");
	gets(newnode->genre);
	printf("director > ");
	gets(newnode->director);
	printf("year > ");
	gets(newnode->year);
	printf("runtime > ");
	gets(newnode->runtime);
	printf("actors > ");
	gets(newnode->actors);
	printf("@@ Done\n");

	newnode->next = NULL;
	if(L->tail==NULL)
	{
	  L-> tail = newnode;
		*newnode->serial_number=1;
	}
	else
	{
		*newnode->serial_number=*L->tail->serial_number+1;
		L->tail->next=newnode;
		L->tail=newnode;
	}
	if(*newnode->serial_number!=1)
	{
		L->tail = tmp_A_L->tail;
		while(L->tail != newnode)
		{
			if(strcmp(L->tail->name, newnode->name) == 0)
			{
				printf("You have the same record in movie list.\n");
				printf("%d:%s:%s:%s:%s:%s:%s\n",*L->tail->serial_number,L->tail->title,L->tail->genre,L->tail->director, L->tail->year, L->tail->runtime, L->tail->actors);
				printf("Do you want to add any way?(Yes/No) ");
				char *c = (char*)malloc(sizeof(char*)*10);
				gets(c);
				while(1)
				{
					if(strcmp(c,"No") == 0 ||  strcmp(c,"N") == 0 || strcmp(c,"no") ==0 || strcmp(c,"n") == 0)
					{
						break;
					}
					else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
					{
						break;
					}
					else
					{
						printf("Wrong answer. Put again. ");
						gets(c);
					}
				}
				if(strcmp(c,"No") == 0 ||  strcmp(c,"N") == 0 || strcmp(c,"no") == 0 || strcmp(c,"n") == 0)
				{
					return;
				}
				else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
				{
					break;
				}
			}
			L->tail=L->tail->next;
		}
		L->tail=newnode;
	}
	movie_list(newnode);
}//node 연결

void movie_list(m_node *newnode)
{
	FILE *fp=fopen("movie_list","a");
	fprintf(fp,"%d:",*newnode->serial_number);
	fputs(newnode->title,fp);
	fprintf(fp,":");
	fputs(newnode->genre,fp);
	fprintf(fp,":");
	fputs(newnode->director,fp);
	fprintf(fp,":");
	fputs(newnode->year,fp);
	fprintf(fp,":");
	fputs(newnode->runtime,fp);
	fprintf(fp,":");
	fputs(newnode->actors,fp);
	fprintf(fp,"\n");
	fclose(fp);

	movie_log(newnode);
}
void movie_log(m_node * newnode)
{
	FILE *fp1=fopen("movie_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",*newnode->serial_number);
	fputs(newnode->title,fp1);
	fprintf(fp1,":");
	fputs(newnode->genre,fp1);
	fprintf(fp1,":");
	fputs(newnode->director,fp1);
	fprintf(fp1,":");
	fputs(newnode->year,fp1);
	fprintf(fp1,":");
	fputs(newnode->runtime,fp1);
	fprintf(fp1,":");
	fputs(newnode->actors,fp1);
	fprintf(fp1,"\n");
	fclose(fp1);
}
void add_D_node(d_linkedlist *L)
{
	d_node *newnode = (d_node*)malloc(sizeof(d_node));

	newnode->serial_number=(int*)malloc(sizeof(int)*3);
	newnode->name=(char*)malloc(sizeof(char)*30);
	newnode->sex=(char*)malloc(sizeof(char)*5);
	newnode->birth=(char*)malloc(sizeof(char)*8);
	newnode->best_movies=(char*)malloc(sizeof(char)*100);
	//총 155바이트

	printf("name > ");
	scanf("%s",&newnode->name);
	printf("sex > ");
	scanf("%s",&newnode->sex);
	printf("birth > ");
	scanf("%s",&newnode->birth);
	printf("best_movies > ");
	scanf("%s",&newnode->best_movies);
	printf("@@ Done\n");

	newnode->next = NULL;
	if(L->tail==NULL)
	{
		L-> tail = newnode;
		*newnode->serial_number=1;
	}
	else
	{
		*newnode->serial_number=*L->tail->serial_number+1;
		L->tail->next=newnode;
		L->tail=newnode;
	}
	if(*newnode->serial_number!=1)
	{
		L->tail = tmp_A_L->tail;
		while(L->tail != newnode)
		{
			if(strcmp(L->tail->name, newnode->name) == 0)
			{
				printf("You have the same record in actor list.\n");
				printf("%d:%s:%s:%s:%s\n",*L->tail->serial_number,L->tail->name,L->tail->sex,L->tail->birth, L->tail->best_movies);
				printf("Do you want to add any way?(Yes/No) ");
				char *c = (char*)malloc(sizeof(char*)*10);
				gets(c);
				while(1)
				{
					if(strcmp(c,"No") == 0 ||  strcmp(c,"N") == 0 || strcmp(c,"no") ==0 || strcmp(c,"n") == 0)
					{
						break;
					}
					else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
					{
						break;
					}
					else
					{
						printf("Wrong answer. Put again. ");
						gets(c);
					}
				}
				if(strcmp(c,"No") == 0 ||  strcmp(c,"N") == 0 || strcmp(c,"no") == 0 || strcmp(c,"n") == 0)
				{
					return;
				}
				else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
				{
					break;
				}
			}
			L->tail=L->tail->next;
		}
		L->tail=newnode;
	}
	director_list(newnode);
}//node 연결

void director_list(d_node *newnode)
{
	FILE *fp=fopen("director_list","a");
	fprintf(fp,"%d:",*newnode->serial_number);
	fputs(newnode->name,fp);
	fprintf(fp,":");
	fputs(newnode->sex,fp);
	fprintf(fp,":");
	fputs(newnode->birth,fp);
	fprintf(fp,":");
	fputs(newnode->best_movies,fp);
	fprintf(fp,"\n");
	fclose(fp);

	director_log(newnode);
}
void director_log(d_node * newnode)
{
	FILE *fp1=fopen("director_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",*newnode->serial_number);
	fputs(newnode->name,fp1);
	fprintf(fp1,":");
	fputs(newnode->sex,fp1);
	fprintf(fp1,":");
	fputs(newnode->birth,fp1);
	fprintf(fp1,":");
	fputs(newnode->best_movies,fp1);
	fprintf(fp1,"\n");
	fclose(fp1);
}

void add_A_node(a_linkedlist *L, a_linkedlist *tmp_A_L)
{
	a_node *newnode = (a_node*)malloc(sizeof(a_node));

	newnode->serial_number=(int*)malloc(sizeof(int)*3);
	newnode->name=(char*)malloc(sizeof(char)*30);
	newnode->sex=(char*)malloc(sizeof(char)*5);
	newnode->birth=(char*)malloc(sizeof(char)*8);
	newnode->best_movies=(char*)malloc(sizeof(char)*100);
	//총 155바이트

	printf("name > ");
	gets(newnode->name);
	printf("sex > ");
	gets(newnode->sex);
	printf("birth > ");
	gets(newnode->birth);
	printf("best_movies > ");
	gets(newnode->best_movies);
	printf("@@ Done\n");

	newnode->next = NULL;
	if(L->tail==NULL)
	{
		L->tail = newnode;
		tmp_A_L->tail = newnode;
		*newnode->serial_number=1;
	}
	else
	{
		*newnode->serial_number = *L->tail->serial_number+1;
		L->tail->next = newnode;
	}
	if(*newnode->serial_number!=1)
	{
		L->tail = tmp_A_L->tail;
		while(L->tail != newnode)
		{
			if(strcmp(L->tail->name, newnode->name) == 0)
			{
				printf("You have the same record in actor list.\n");
				printf("%d:%s:%s:%s:%s\n",*L->tail->serial_number,L->tail->name,L->tail->sex,L->tail->birth, L->tail->best_movies);
				printf("Do you want to add any way?(Yes/No) ");
				char *c = (char*)malloc(sizeof(char*)*10);
				gets(c);
				while(1)
				{
					if(strcmp(c,"No") == 0 ||  strcmp(c,"N") == 0 || strcmp(c,"no") ==0 || strcmp(c,"n") == 0)
					{
						break;
					}
					else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
					{
						break;
					}
					else
					{
						printf("Wrong answer. Put again. ");
						gets(c);
					}
				}
				if(strcmp(c,"No") == 0 ||  strcmp(c,"N") == 0 || strcmp(c,"no") == 0 || strcmp(c,"n") == 0)
				{
					return;
				}
				else if(strcmp(c,"Yes") == 0 || strcmp(c,"Y") == 0 || strcmp(c,"yes") == 0 || strcmp(c,"y") == 0)
				{
					break;
				}
			}
			L->tail=L->tail->next;
		}
		L->tail=newnode;
	}
	actor_list(newnode);
}//node 연결

void actor_list(a_node *newnode)
{
	FILE *fp=fopen("actor_list","a");
	fprintf(fp,"%d:",*newnode->serial_number);
	fputs(newnode->name,fp);
	fprintf(fp,":");
	fputs(newnode->sex,fp);
	fprintf(fp,":");
	fputs(newnode->birth,fp);
	fprintf(fp,":");
	fputs(newnode->best_movies,fp);
	fprintf(fp,"\n");
	fclose(fp);

	actor_log(newnode);
}
void actor_log(a_node * newnode)
{
	FILE *fp1=fopen("actor_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",*newnode->serial_number);
	fputs(newnode->name,fp1);
	fprintf(fp1,":");
	fputs(newnode->sex,fp1);
	fprintf(fp1,":");
	fputs(newnode->birth,fp1);
	fprintf(fp1,":");
	fputs(newnode->best_movies,fp1);
	fprintf(fp1,"\n");
	fclose(fp1);
}

int main()
{
	m_linkedlist *M_L=(m_linkedlist*)malloc(sizeof(m_linkedlist));
	d_linkedlist *D_L=(d_linkedlist*)malloc(sizeof(d_linkedlist));
	a_linkedlist *A_L=(a_linkedlist*)malloc(sizeof(a_linkedlist));
	m_linkedlist *tmp_M_L=(m_linkedlist*)malloc(sizeof(m_linkedlist));
	d_linkedlist *tmp_D_L=(d_linkedlist*)malloc(sizeof(d_linkedlist));
	a_linkedlist *tmp_A_L=(a_linkedlist*)malloc(sizeof(a_linkedlist));

	M_L->tail=NULL;
	D_L->tail=NULL;
	A_L->tail=NULL;
	tmp_M_L->tail=NULL;
	tmp_D_L->tail=NULL;
	tmp_M_L->tail=NULL;
	add_A_node(A_L,tmp_A_L);
	add_A_node(A_L,tmp_A_L);
	return 0;
}
