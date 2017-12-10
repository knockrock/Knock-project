#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "movie_manage_program.h"
void rechange_colon(char* sentence);
void rechange_colon_file(FILE* file, char *sentence);
char* change_colon(char* sentence);

void rechange_colon(char* sentence)
{
  int sentence_length;
  sentence_length = strlen(sentence);

  for(int i = 0; i < sentence_length + 1; i++)
  {
    if(*(sentence + i) == '?')
    {
      if(*(sentence + i + 1) == '?')
      {
        if(*(sentence + i + 2) == ';')
        {
          printf(":");
          i = i + 3;
        }
      }
    }
    printf("%c", *(sentence + i));
  }
}

void rechange_colon_file(FILE* file, char *sentence)
{
  int sentence_length;
  sentence_length = strlen(sentence);

  for(int i = 0; i < sentence_length + 1; i++)
  {
    if(*(sentence + i) == '?')
    {
      if(*(sentence + i + 1) == '?')
      {
        if(*(sentence + i + 2) == ';')
        {
          fprintf(file, ":");
          i = i + 3;
        }
      }
    }
    fprintf(file, "%c", *(sentence + i));
  }
}

char* change_colon(char* sentence)
{
  char* colon_check;
  char* insert;

  colon_check = strchr(sentence, ':');

  if(colon_check != NULL)
  {
    int sentence_length;
    sentence_length = strlen(sentence);

    while(colon_check != NULL)
    {
      colon_check = strchr(colon_check + 1, ':');
      sentence_length += 2;
    }

    insert = (char*)malloc((sentence_length + 10) * sizeof(char));

    strcpy(insert, sentence);

    for(int i = sentence_length - 1; i >= 0; i--)
    {
      if(*(insert + i) == ':')
      {
        for(int j = sentence_length; j > i; j--)
        {
          *(insert + j + 2) = *(insert + j);
        }

        *(insert + i) = '?';
        *(insert + i + 1) = '?';
        *(insert + i + 2) = ';';
      }
    }

    return insert;
  }

  else
  {
    return sentence;
  }
}
