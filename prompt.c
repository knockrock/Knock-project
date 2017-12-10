#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "movie_manage_program.h"

void prompt(char * value, char * command, char * opt1, char * opt2, char * opt3, char * opt4, movie * M_L, director * D_L, actor * A_L,m_node * m_newnode, d_node * d_newnode, a_node * a_newnode) // 영화 관리 프로그램 기본 프롬프트
{
   M_L = read_m_log(M_L);
   D_L = read_d_log(D_L);
   A_L = read_a_log(A_L);

   d_link(D_L,A_L,M_L);
   a_link(A_L,D_L,M_L);
   m_a_link(A_L,D_L,M_L);
   m_d_link(D_L,A_L,M_L);

   m_write(M_L);
   d_write(D_L);
   a_write(A_L);

   while(1)
   {
      int optcnt=0;
      int i = 0;
      signal(SIGINT,cntrl_signal);
      printf("(movie) ");
      gets(value);

      if (strlen(value) == 0)
      {
        continue;
      }
      else{


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

      d_link(D_L,A_L,M_L);
      a_link(A_L,D_L,M_L);
      m_a_link(A_L,D_L,M_L);
      m_d_link(D_L,A_L,M_L);


      }

      else if(strcmp(command,"search")==0)
      {

      }

      else if(strcmp(command,"print")==0)
      {
        if(optcnt>=1)
        {
           if(opt1!=NULL)
           {
              if(!strcmp(opt1,"m"))
              {

                print_m(M_L,opt2);

                printf("%s\n", D_L->next->next->next->next->d_data.best_movies->same_title->title);

              }
              else if(!strcmp(opt1,"d"))
              {
                 print_d(D_L,opt2);
              }
              else if(!strcmp(opt1,"a"))
              {

                print_a(A_L,opt2);



              }
              else
                 printf("Please enter with factor (m|d|a).\n");
           }
        }
        else
           printf("Please enter with factor (m|d|a).\n");
      }

      else if(strcmp(command,"update")==0)
      {
         if(optcnt==3)
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

               m_update(M_L,optcnt,opt2,atoi(opt3));
            }
            else if(strcmp(opt1,"d")==0)
            {
               d_update(D_L,optcnt,opt2,atoi(opt3));
            }
            else if(strcmp(opt1,"a")==0)
            {
               a_update(A_L,optcnt,opt2,atoi(opt3));

            }
            else
               printf("Please enter the necessary factor (m|d|a).\n");
         }
         else
            printf("Please enter the all options.\n");
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
         exit(1);
      }

      else
         printf("Please enter correct command.\n");
   }
}

}


