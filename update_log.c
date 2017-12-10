#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void m_update_log(movie * M_L, m_node * newnode, char * opt2, int opt3)
{
	int num = opt3;
	movie * tmp_M_L;
	tmp_M_L = M_L;
	while(M_L->m_data.serial_number!=num)
		M_L=M_L->next;
	if(strchr(opt2,'t')!=NULL)
	{
		M_L->m_data.title = newnode->title;
	}
	if(strchr(opt2,'g')!=NULL)
	{
		M_L->m_data.genre = newnode->genre;
	}
	if(strchr(opt2,'d')!=NULL)
	{
		M_L->m_data.director->director = newnode -> director->director;
	}
	if(strchr(opt2,'y')!=NULL)
	{
		M_L->m_data.year = newnode->year;
	}
	if(strchr(opt2,'r')!=NULL)
	{
		M_L->m_data.runtime = newnode->runtime;
	}
	if(strchr(opt2,'a')!=NULL)
	{
		char * tmp_actors = (char*)malloc(sizeof(char)*100);
		to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
		tmp->actor = NULL;
		tmp->next=NULL;
		tmp = M_L->m_data.actors;
		movie * tmp_M_L = M_L;
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
		M_L->m_data.actors = newnode->actors;
	}
}
void d_update_log(director * D_L, d_node * newnode, char * opt2, int opt3)
{
	int num = opt3;
	director * tmp_D_L;
	tmp_D_L = D_L;
	while(D_L->d_data.serial_number!=num)
		D_L=D_L->next;
	if(strchr(opt2,'n')!=NULL)
	{
		D_L->d_data.name = newnode->name;
	}
	if(strchr(opt2,'s')!=NULL)
	{
		D_L->d_data.sex = newnode->sex;
	}
	if(strchr(opt2,'b')!=NULL)
	{
		D_L->d_data.birth = newnode -> birth;
	}
	if(strchr(opt2,'m')!=NULL)
	{
		char * tmp_best_movies = (char*)malloc(sizeof(char)*100);
		to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
		tmp->title = NULL;
		tmp->next=NULL;
		tmp = D_L->d_data.best_movies;
		director * tmp_D_L = D_L;
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
		D_L->d_data.best_movies = newnode->best_movies;
	}
}
void a_update_log(actor * A_L, a_node * newnode, char * opt2, int opt3)
{
	int num = opt3;
	actor * tmp_A_L;
	tmp_A_L = A_L;
	while(A_L->a_data.serial_number!=num)
		A_L=A_L->next;
	if(strchr(opt2,'n')!=NULL)
	{
		A_L->a_data.name = newnode->name;
	}
	if(strchr(opt2,'s')!=NULL)
	{
		A_L->a_data.sex = newnode->sex;
	}
	if(strchr(opt2,'b')!=NULL)
	{
		A_L->a_data.birth = newnode -> birth;
	}
	if(strchr(opt2,'m')!=NULL)
	{
		char * tmp_best_movies = (char*)malloc(sizeof(char)*100);
		to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
		tmp->title = NULL;
		tmp->next=NULL;
		tmp = A_L->a_data.best_movies;
		actor * tmp_A_L = A_L;
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
		A_L->a_data.best_movies = newnode->best_movies;
	}
}
