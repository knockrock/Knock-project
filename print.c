#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

void print_d(director * D_L){
while(D_L->next != NULL){
  printf("%s\n",D_L->d_data->name);
  printf("%d\n",D_L->d_data->serial_number);
  D_L = D_L->next;
}
printf("%s\n",D_L->d_data->name);
printf("%d\n",D_L->d_data->serial_number);
}
