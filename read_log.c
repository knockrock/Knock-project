#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"
movie *read_m_log(movie * M_L)
{
  char c;
  char * option = (char*)malloc(10);
  FILE *fp = fopen("movie_log","r");
  if((c=fgetc(fp))!=EOF)
  {
    while(1)
    {
      fseek(fp,-1,SEEK_CUR);
      char * str = (char*)malloc(251);
      m_node * newnode=(m_node*)malloc(sizeof(m_node));
      newnode->serial_number=0;
      newnode->title=(char*)malloc(sizeof(char)*50);
      newnode->genre=(char*)malloc(sizeof(char)*30);
      newnode->year=(char*)malloc(sizeof(char)*8);
      newnode->runtime=(char*)malloc(sizeof(char)*3);
      char * tmp_actors = (char*)malloc(sizeof(char)*100);
      newnode->actors = (to_actor *)malloc(sizeof(to_actor));
      newnode->actors -> actor  = (char*)malloc(sizeof(char)*100);
      newnode->actors -> next = NULL;
      newnode->actors->same_actor = NULL;
      newnode->director = (to_director *)malloc(sizeof(to_director));
      newnode->director->director = (char*)malloc(sizeof(char)*100);
      char * tag = (char*)malloc(10);
      to_actor * tmp=(to_actor*)malloc(sizeof(to_actor));
      tmp->actor = NULL;
      tmp->next=NULL;
      tmp = newnode->actors;

      fgets(str,250,fp);
      str = strtok(str,"\n");
      tag = strtok(str,":");
      newnode->serial_number = atoi(strtok(NULL,":"));
      newnode->title = strtok(NULL,":");
      newnode->genre = strtok(NULL,":");
      newnode->director->director = strtok(NULL,":");
      newnode->year = strtok(NULL,":");
      newnode->runtime = strtok(NULL,":");
      tmp_actors = strtok(NULL,":");
      newnode->actors->actor = strtok(tmp_actors,",");

      while(1)
    	{
    		link_actor(newnode->actors);
        while(newnode->actors->next->next!=NULL)
    			newnode->actors=newnode->actors->next;
    		if(newnode->actors->next->actor == NULL)
    		{
    			free(newnode->actors->next->next);
    			newnode->actors->next->next=NULL;
          free(newnode->actors->next);
          newnode->actors->next=NULL;
    			break;
    		}
    	}
    	newnode->actors=tmp;
      if(strcmp(tag,"add")==0)
      {
        if(M_L==NULL)
          init_M_node(&M_L,newnode);
        else
          link_M_node(M_L,newnode);
      }
      else if(strcmp(tag,"delete")==0)
      {
        delete_log_m(M_L, newnode);
      }
      else if(strcmp(tag,"update")==0)
      {
        if(strcmp(newnode->title,"=")!=0)
          strcpy(option,"t");
        if(strcmp(newnode->genre,"=")!=0)
          strcpy(option,"g");
        if(strcmp(newnode->director->director,"=")!=0)
          strcpy(option,"d");
        if(strcmp(newnode->year,"=")!=0)
          strcpy(option,"y");
        if(strcmp(newnode->runtime,"=")!=0)
          strcpy(option,"r");
        if(strcmp(newnode->actors->actor,"=")!=0)
          strcpy(option,"a");
        m_update_log(M_L,newnode,option,newnode->serial_number);
      }
      if((c=fgetc(fp))==EOF)
        break;
    }
  }
  fclose(fp);
  return M_L;
}

director *read_d_log(director * D_L)
{
  char c;
  char * option = (char*)malloc(10);
  FILE *fp = fopen("director_log","r");
  if((c=fgetc(fp))!=EOF)
  {
    while(1)
    {
      fseek(fp,-1,SEEK_CUR);
      char * str = (char*)malloc(251);
      d_node * newnode=(d_node*)malloc(sizeof(d_node));
      newnode->serial_number=0;
      newnode->name=(char*)malloc(sizeof(char)*50);
      newnode->birth=(char*)malloc(sizeof(char)*30);
      char * tmp_best_movies = (char*)malloc(sizeof(char)*100);
      newnode->best_movies = (to_movie *)malloc(sizeof(to_movie));
      newnode->best_movies->title  = (char*)malloc(sizeof(char)*100);
      newnode->best_movies -> next = NULL;
      newnode->best_movies->same_title = NULL;
      char * tag = (char*)malloc(10);
      to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
      tmp->title = NULL;
      tmp->next=NULL;
      tmp = newnode->best_movies;

      fgets(str,250,fp);
      str = strtok(str,"\n");
      tag = strtok(str,":");
      newnode->serial_number = atoi(strtok(NULL,":"));
      newnode->name = strtok(NULL,":");
      newnode->sex = *strtok(NULL,":");
      newnode->birth = strtok(NULL,":");
      tmp_best_movies = strtok(NULL,":");
      newnode->best_movies->title = strtok(tmp_best_movies,",");

      while(1)
    	{
    		link_title(newnode->best_movies);
    		while(newnode->best_movies->next->next!=NULL)
    			newnode->best_movies=newnode->best_movies->next;
    		if(newnode->best_movies->next->title == NULL)
    		{
    			free(newnode->best_movies->next->next);
    			newnode->best_movies->next->next=NULL;
    			free(newnode->best_movies->next);
          newnode->best_movies->next=NULL;
          break;
    		}
    	}
    	newnode->best_movies=tmp;
      if(strcmp(tag,"add")==0)
      {
        if(D_L==NULL)
          init_D_node(&D_L,newnode);
        else
          link_D_node(D_L,newnode);
      }
      else if(strcmp(tag,"delete")==0)
      {
        delete_log_d(D_L, newnode);
      }
      else if(strcmp(tag,"update")==0)
      {
        if(strcmp(newnode->name,"=")!=0)
          strcpy(option,"n");
        if(strcmp(&newnode->sex,"=")!=0)
          strcpy(option,"s");
        if(strcmp(newnode->birth,"=")!=0)
          strcpy(option,"b");
        if(strcmp(newnode->best_movies->title,"=")!=0)
          strcpy(option,"m");
        d_update_log(D_L,newnode,option,newnode->serial_number);
      }
      if((c=fgetc(fp))==EOF)
        break;
    }
  }
  fclose(fp);
  return D_L;
}

actor *read_a_log(actor * A_L)
{
  char c;
  char * option = (char*)malloc(10);
  FILE *fp = fopen("actor_log","r");
  if((c=fgetc(fp))!=EOF)
  {
    while(1)
    {
      fseek(fp,-1,SEEK_CUR);
      char * str = (char*)malloc(251);
      a_node * newnode=(a_node*)malloc(sizeof(a_node));
      newnode->serial_number=0;
      newnode->name=(char*)malloc(sizeof(char)*50);
      newnode->birth=(char*)malloc(sizeof(char)*30);
      char * tmp_best_movies = (char*)malloc(sizeof(char)*100);
      newnode->best_movies = (to_movie *)malloc(sizeof(to_movie));
      newnode->best_movies->title  = (char*)malloc(sizeof(char)*100);
      newnode->best_movies -> next = NULL;
      newnode->best_movies->same_title = NULL;
      char * tag = (char*)malloc(10);
      to_movie * tmp=(to_movie*)malloc(sizeof(to_movie));
      tmp->title = NULL;
      tmp->next=NULL;
      tmp = newnode->best_movies;

      fgets(str,250,fp);
      str = strtok(str,"\n");
      tag = strtok(str,":");
      newnode->serial_number = atoi(strtok(NULL,":"));
      newnode->name = strtok(NULL,":");
      newnode->sex = *strtok(NULL,":");
      newnode->birth = strtok(NULL,":");
      tmp_best_movies = strtok(NULL,":");
      newnode->best_movies->title = strtok(tmp_best_movies,",");

      while(1)
    	{
    		link_title(newnode->best_movies);
    		while(newnode->best_movies->next->next!=NULL)
    			newnode->best_movies=newnode->best_movies->next;
    		if(newnode->best_movies->next->title == NULL)
    		{
    			free(newnode->best_movies->next->next);
    			newnode->best_movies->next->next=NULL;
          free(newnode->best_movies->next);
          newnode->best_movies->next=NULL;
          break;
    		}
    	}
    	newnode->best_movies=tmp;
      if(strcmp(tag,"add")==0)
      {
        if(A_L==NULL)
          init_A_node(&A_L,newnode);
        else
          link_A_node(A_L,newnode);
      }
      else if(strcmp(tag,"delete")==0)
      {
        delete_log_a(A_L, newnode);
      }
      else if(strcmp(tag,"update")==0)
      {
        if(strcmp(newnode->name,"=")!=0)
          strcpy(option,"n");
        if(strcmp(&newnode->sex,"=")!=0)
          strcpy(option,"s");
        if(strcmp(newnode->birth,"=")!=0)
          strcpy(option,"b");
        if(strcmp(newnode->best_movies->title,"=")!=0)
          strcpy(option,"m");
        a_update_log(A_L,newnode,option,newnode->serial_number);
      }
      if((c=fgetc(fp))==EOF)
        break;
    }
  }
  fclose(fp);
  return A_L;
}
