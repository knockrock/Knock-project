#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int search(char *origin, char *search)
{
  int search_length;
  search_lenght = strlen(*search);
  int origin_length;
  origin_length = strlen(*origin);

  int k = 0;
  
  if(*search == '*')
  {
    if(*(search + search_length) == '*')
    {
      // int search_length_tmp = search_length -1;

      int flag = 0;

      for(int i = 0; i < search_length -2; i++)
      {
        for(int j = 0; j < search_length; j++)
        {
          if(*(origin + j) == *(search + i + 1))
          {
            
          }
        }
      }
    }

    else
    {
      
    }
  }
  
  else if(*(search + search_length) == '*')
  {
    
  }
  else
  {
    
  }
}
