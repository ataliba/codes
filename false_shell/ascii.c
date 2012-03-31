#include <stdio.h>
#include <stdlib.h>


int main(void)
 {
   char *comando;
   int comando1;

   printf("Entre com o comando : " );
   gets(comando);

   printf("O codigo ascii eh  %d \n",*comando);

   }
