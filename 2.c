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
	m_node *head;
	m_node *tail;
}m_linkedlist;

typedef struct director_list{
	d_node *head;
	d_node *tail;
}d_linkedlist;

typedef struct actor_list{
	a_node *head;
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
	scanf("%s",&newnode->title);
	printf("genre > ");
	scanf("%s",&newnode->genre);
	printf("director > ");
	scanf("%s",&newnode->director);
	printf("year > ");
	scanf("%s",&newnode->year);
	printf("runtime > ");
	scanf("%s",&newnode->runtime);
	printf("actors > ");
	scanf("%s",&newnode->actors);
	printf("@@ Done\n");

	newnode->next = NULL;
	if(L->head==NULL&&L->tail==NULL)
	{
		L->head = L-> tail = newnode;
		*newnode->serial_number=1;
	}
	else
	{
		*newnode->serial_number=*L->tail->serial_number+1;
		L->tail->next=newnode;
		L->tail=newnode;
	}
	movie_list(newnode);
}//node 연결

void movie_list(m_node *newnode)
{
	FILE *fp=fopen("movie_list","a");
	fprintf(fp,"%d:",*newnode->serial_number);
	fprintf(fp,"%s:",&newnode->title);
	fprintf(fp,"%s:",&newnode->genre);
	fprintf(fp,"%s:",&newnode->director);
	fprintf(fp,"%s:",&newnode->year);
	fprintf(fp,"%s:",&newnode->runtime);
	fprintf(fp,"%s",&newnode->actors);
	fprintf(fp,"\n");
	fclose(fp);

	movie_log(newnode);
}
void movie_log(m_node * newnode)
{
	FILE *fp1=fopen("movie_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",*newnode->serial_number);
	fprintf(fp1,"%s:",&newnode->title);
	fprintf(fp1,"%s:",&newnode->genre);
	fprintf(fp1,"%s:",&newnode->director);
	fprintf(fp1,"%s:",&newnode->year);
	fprintf(fp1,"%s:",&newnode->runtime);
	fprintf(fp1,"%s",&newnode->actors);
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
	if(L->head==NULL&&L->tail==NULL)
	{
		L->head = L-> tail = newnode;
		*newnode->serial_number=1;
	}
	else
	{
		*newnode->serial_number=*L->tail->serial_number+1;
		L->tail->next=newnode;
		L->tail=newnode;
	}
	director_list(newnode);
}//node 연결

void director_list(d_node *newnode)
{
	FILE *fp=fopen("director_list","a");
	fprintf(fp,"%d:",*newnode->serial_number);
	fprintf(fp,"%s:",&newnode->name);
	fprintf(fp,"%s:",&newnode->sex);
	fprintf(fp,"%s:",&newnode->birth);
	fprintf(fp,"%s",&newnode->best_movies);
	fprintf(fp,"\n");
	fclose(fp);

	director_log(newnode);
}
void director_log(d_node * newnode)
{
	FILE *fp1=fopen("director_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",*newnode->serial_number);
	fprintf(fp1,"%s:",&newnode->name);
	fprintf(fp1,"%s:",&newnode->sex);
	fprintf(fp1,"%s:",&newnode->birth);
	fprintf(fp1,"%s",&newnode->best_movies);
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
	scanf("%s",&newnode->name);
	printf("sex > ");
	scanf("%s",&newnode->sex);
	printf("birth > ");
	scanf("%s",&newnode->birth);
	printf("best_movies > ");
	scanf("%s",&newnode->best_movies);
	printf("@@ Done\n");

	newnode->next = NULL;
	if(L->head==NULL&&L->tail==NULL)
	{
		L->head = newnode;
		L->tail = newnode;
		tmp_A_L->head = newnode;
		tmp_A_L->tail = newnode;
		*newnode->serial_number=1;
	}
	else
	{
		*newnode->serial_number = *L->tail->serial_number+1;
		L->head->next = L->tail->next=newnode;
		L->tail = newnode;
	}
	actor_list(newnode);
}//node 연결

void actor_list(a_node *newnode)
{
	FILE *fp=fopen("actor_list","a");
	fprintf(fp,"%d:",*newnode->serial_number);
	fprintf(fp,"%s:",&newnode->name);
	fprintf(fp,"%s:",&newnode->sex);
	fprintf(fp,"%s:",&newnode->birth);
	fprintf(fp,"%s",&newnode->best_movies);
	fprintf(fp,"\n");
	fclose(fp);

	actor_log(newnode);
}
void actor_log(a_node * newnode)
{
	FILE *fp1=fopen("actor_log","a");
	fprintf(fp1,"add:");
	fprintf(fp1,"%d:",*newnode->serial_number);
	fprintf(fp1,"%s:",&newnode->name);
	fprintf(fp1,"%s:",&newnode->sex);
	fprintf(fp1,"%s:",&newnode->birth);
	fprintf(fp1,"%s",&newnode->best_movies);
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
	M_L->head=NULL;
	M_L->tail=NULL;
	D_L->head=NULL;
	D_L->tail=NULL;
	A_L->head=NULL;
	A_L->tail=NULL;
	tmp_M_L->head=NULL;
	tmp_M_L->tail=NULL;
	tmp_D_L->head=NULL;
	tmp_D_L->tail=NULL;
	tmp_A_L->head=NULL;
	tmp_M_L->tail=NULL;
	add_A_node(A_L,tmp_A_L);
	add_A_node(A_L,tmp_A_L);
	return 0;
}
