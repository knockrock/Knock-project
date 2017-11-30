#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void prompt(char * value, char * command, char * opt1, char * opt2, char * opt3, char * opt4, movie * M_L, director * D_L, actor * A_L,m_node * m_newnode, d_node * d_newnode, a_node * a_newnode) // 영화 관리 프로그램 기본 프롬프트
{
	while(1)
	{
		printf("(movie) ");
		gets(value);
		command = strtok(value," ");
		opt1 = strtok(NULL," ");
		opt2 = strtok(NULL," ");
		opt3 = strtok(NULL," ");
		opt4 = strtok(NULL," ");

		if(strcmp(command,"add")==0)
		{
			if(opt1!=NULL)
			{
				if(!strcmp(opt1,"m"))
				{
					if(M_L==NULL)
					{
						m_newnode = input_M_node();
						init_M_node(&M_L,m_newnode);
						check_m_node(M_L,m_newnode);
					}
					else
					{
						m_newnode = input_M_node();
						link_M_node(M_L,m_newnode);
						check_m_node(M_L,m_newnode);
					}
				}
				else if(!strcmp(opt1,"d"))
				{
					if(D_L==NULL)
					{
						d_newnode = input_D_node();
						init_D_node(&D_L,d_newnode);
						check_d_node(D_L,d_newnode);
					}
					else
					{
						d_newnode = input_D_node();
						link_D_node(D_L,d_newnode);
						check_d_node(D_L,d_newnode);
					}
				}
				else if(!strcmp(opt1,"a"))
				{
					if(A_L==NULL)
					{
						a_newnode = input_A_node();
						init_A_node(&A_L,a_newnode);
						check_a_node(A_L,a_newnode);
					}
					else
					{
						a_newnode = input_A_node();
						link_A_node(A_L,a_newnode);
						check_a_node(A_L,a_newnode);
					}
				}
				else
					printf("Please enter with factor (m|d|a).\n");
			}
			else
				printf("Please enter with factor (m|d|a).\n");
		}
		else if(strcmp(command,"search")==0)
		{

		}
		else if(strcmp(command,"print")==0)
		{

		}
		else if(strcmp(command,"update")==0)
		{

		}
		/*else if(strcmp(command,"delete")==0)
		{
			if(opt1!=NULL)
			{
				if(!strcmp(opt1,"m"))
				{
					delete_m(M_L, opt2);
				}
				else if(!strcmp(opt1,"d"))
				{
					delete_d(D_L, opt2);
				}
				else if(!strcmp(opt1,"a"))
				{
					delete_a(A_L, opt2);
				}
				else
					printf("Please enter with factor (m|d|a).\n");
			}
			else
				printf("Please enter with factor (m|d|a).\n");
		}*/
		else if(strcmp(command,"sort")==0)
		{

		}
		else if(strcmp(command,"save")==0)
		{
			if(opt1!=NULL)
			{
				if(strcmp(opt2,"-f")==0)
				{
					if(strcmp(opt1,"m")!=NULL)
					{
						m_save(M_L, opt4, opt2, opt3);
					}
					else if(strcmp(opt1,"d")!=NULL)
					{
						d_save(D_L, opt4, opt2, opt3);
					}
					else if(strcmp(opt1,"a")!=NULL)
					{
						a_save(A_L, opt4, opt2, opt3);
					}
				}
				else
				{
					if(strchr(opt1,'m')!=NULL)
					{
						m_save(M_L, opt2, opt3, opt4);
					}
					else if(strchr(opt1,'d')!=NULL)
					{
						d_save(D_L, opt2, opt3, opt4);
					}
					else if(strchr(opt1,'a')!=NULL)
					{
						a_save(A_L, opt2, opt3, opt4);
					}
				}
			}
			else
				printf("Please enter necessary factor (m|d|a).\n");
		}
		else if(strcmp(command, "end")==0)
		{
			exit(1);
		}
		else
			printf("Please enter correct command.\n");
	}
}
