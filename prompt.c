
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "movie_manage_program.h"



void prompt(char * value, char * command, char * opt1, char * opt2, char * opt3, char * opt4, movie * M_L, director * D_L, actor * A_L,m_node * m_newnode, d_node * d_newnode, a_node * a_newnode) // 영화 관리 프로그램 기본 프롬프트

{

	M_L = read_m_log(M_L);

	D_L = read_d_log(D_L);

	A_L = read_a_log(A_L);

	while(1)

	{

		int optcnt=0;

		int i = 0;

		printf("(movie) ");

		gets(value);

		while(*(value+i)!='\0')

		{

			if(*(value+i)==' ')

				optcnt++;

			i++;

		}

		if(*(value+(strlen(value)-1))==' ')

		{

			printf("Please enter the command correctly. \n");

			continue;

		}

		command = strtok(value," ");

		opt1 = strtok(NULL," ");

		opt2 = strtok(NULL," ");

		opt3 = strtok(NULL," ");

		opt4 = strtok(NULL," ");



		if(strcmp(command,"add")==0)

		{

			if(optcnt==1)

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
      if(optcnt>=1)
			{
        if(!strcmp(opt1, 'm'))
        {
          search_movie(M_L, opt2);
        }

        else if(!strcmp(opt1, 'a'))
        {
          search_actor(A_L, opt2);
        }

        else if(!strcmp(opt1, 'd'))
        {
          search_director(D_L, opt2);
        }

        else if(!strcmp(opt1, 'ma'))
        {
          search_movie(M_L, opt2);
          search_actor(A_L, opt2);
        }

        else if(!strcmp(opt1, 'am'))
        {
          search_actor(A_L, opt2);
          search_movie(M_L, opt2);
        }

        else if(!strcmp(opt1, 'md'))
        {
          search_movie(M_L, opt2);
          search_director(D_L, opt2);
        }

        else if(!strcmp(opt1, 'dm'))
        {
          search_director(D_L, opt2);
          search_movie(M_L, opt2);
        }

        else if(!strcmp(opt1, 'ad'))
        {
          search_actor(A_L, opt2);
          search_director(D_L, opt2);
        }

        else if(!strcmp(opt1, 'da'))
        {
          search_director(M_L, opt2);
          search_actor(M_L, opt2);
        }

        else if(!strcmp(opt1, 'mda'))
        {
          search_movie(M_L, opt2);
          search_director(D_L, opt2);
          search_actor(A_L, opt2);

        }

        else if(!strcmp(opt1, 'mad'))
        {
          search_movie(M_L, opt2);
          search_actor(A_L, opt2);
          search_director(D_L, opt2);
        }

        else if(!strcmp(opt1, 'dma'))
        {
          search_director(D_L, opt2);
          search_movie(M_L, opt2);
          search_actor(A_L, opt2);
        }

        else if(!strcmp(opt1, 'dam'))
        {
          search_director(D_L, opt2);
          search_actor(A_L, opt2);
          search_movie(M_L, opt2);
        }

        else if(!strcmp(opt1, 'amd'))
        {
          search_actor(A_L, opt2);
          search_movie(M_L, opt2);
          search_director(D_L, opt2);
        }

        else if(!strcmp(opt1, 'adm'))
        {
          search_actor(A_L, opt2);
          search_director(D_L, opt2);
          search_movie(M_L, opt2);
        }

        else
        {
          printf("Please enter with factor (m|d|a).\n");
        }

      }





		}



		else if(strcmp(command,"print")==0)

		{



		}



		else if(strcmp(command,"update")==0)

		{

			if(optcnt>=1)

			{

				if(strcmp(opt1,"m")==0)

				{

					m_update(M_L,optcnt,opt2,opt3);

				}

				else if(strcmp(opt1,"d")==0)

				{

					d_update(D_L,optcnt,opt2,opt3);

				}

				else if(strcmp(opt1,"a")==0)

				{

					a_update(A_L,optcnt,opt2,opt3);

				}

				else

					printf("Please enter the necessary factor (m|d|a).\n");

			}

			else

				printf("Please enter the necessary factor (m|d|a).\n");

		}

		else if(strcmp(command,"delete")==0)

		{

			if(optcnt>=1)

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

			}

			else

				printf("Please enter with factor (m|d|a).\n");

		}



		else if(strcmp(command,"sort")==0)

		{

			if(optcnt>=1)

			{

				if(strcmp(opt1,"m")==0)

				{

					m_sort(M_L,optcnt,opt2,opt3,opt4);

				}

				else if(strcmp(opt1,"d")==0)

				{

					d_sort(D_L,optcnt,opt2,opt3,opt4);

				}

				else if(strcmp(opt1,"a")==0)

				{

					a_sort(A_L,optcnt,opt2,opt3,opt4);

				}

				else

					printf("Please enter the necessary factor (m|d|a).\n");

			}

			else

				printf("Please enter the necessary factor (m|d|a).\n");

		}



		else if(strcmp(command,"save")==0)

		{

			if(optcnt>=1)

			{

				if(strcmp(opt1,"m")==0)

				{

					m_save(M_L, optcnt, opt2, opt3, opt4);

				}

				else if(strcmp(opt1,"d")==0)

				{

					d_save(D_L, optcnt, opt2, opt3, opt4);

				}

				else if(strcmp(opt1,"a")==0)

				{

					a_save(A_L, optcnt, opt2, opt3, opt4);

				}

				else

				printf("Please enter necessary factor (m|d|a).\n");

			}

		}



		else if(strcmp(command, "end")==0)

		{
      char a;
      
      printf("@@ Do you want Save? (Y/N)\n");
      scanf("%c", &a);
      
      if(!(strcmp(a, "Y")) || !(strcmp(a, "y")))
      {
        m_save(M_L, 1, NULL, NULL, NULL);
        d_save(D_L, 1, NULL, NULL, NULL);
        a_save(A_L, 1, NULL, NULL, NULL);
        exit(1);
      }

      else if(!(strcmp(a, "Y")) || !(strcmp(a, "y")))
        {
          printf("See you next Semester\n");
          exit(1);
        }

        
      else
      {
        printf("Please enter necessary factor (Y|N).\n");
      }
      
		}

    
		else
    {
			printf("Please enter correct command.\n");
    }

	}

}
