/* mat_disc.c
   Matematica Discreta
   Professor Luis Elpidio
   Faculdade de Informatica do Oeste de Minas
   Sistemas de Informacao

   -------------------------------------------
   Alunos :
   Ataliba de Oliveira Teixeira
   Augusto Cesar
   Junio Menezes
   Eneo
   Jose Ernesto
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

// funcoes que seroa usadas no programa

int mmc_func(void);
int mdc_func(void);
int entrada_programa(void);

// corpo principal do programa

 int main(void)
  {
    char ch, str[3];

    clrscr();

    entrada_programa();


    for(;;)
     {
       clrscr();

       do
	{
	  clrscr();
	  gotoxy(12,9);
	  printf("(================================================)");
	  gotoxy(12,10);
	  printf("(    ®® Escolha uma das opcoes abaixo ¯¯         )");
	  gotoxy(12,11);
	  printf("(       ®® MM(C) de dois numeros ¯¯              )");
	  gotoxy(12,12);
	  printf("(       ®® M(D)C de dois numeros ¯¯              )");
	  gotoxy(12,13);
	  printf("(        ®® (S)air do programa ¯¯                )");
	  gotoxy(12,14);
	  printf("(================================================)");
	  gotoxy(12,15);
	  printf("Opcao : ");
	  fflush(stdin);

	  gets(str);
	  ch = toupper(*str);
	}while((ch != 'S') && ( ch != 'C') && (ch != 'D'));

	switch(ch)
	 {
	   case 'C':
	     mmc_func();
	     break;
	   case 'D':
	     mdc_func();
	     break;
	   case 'S':
	     exit(0);
	     break;
	 }
     }


 }

// funcao que calcula o mmc

int mmc_func(void)
 {
   int number1, number2, a, aa, b, bb, resto;

  clrscr();
  gotoxy(12,8);
  printf("(=======================================================)");
  gotoxy(12,9);
  printf("(       ®® Calculando o MMC de dois numeros ¯¯          )");
  gotoxy(12,10);
  printf("(=======================================================)");
  gotoxy(12,11);
  printf("# Entre com o primeiro numero : ");
  scanf("%d",&a);
  gotoxy(12,12);
  printf("# Entre com o segundo numero : ");
  scanf("%d",&b);
  gotoxy(12,13);
  printf("(            Processando o Resultado                    )");
  sleep(1);


  number1 = aa = a;
  number2 = bb = b;


  while(bb != 0)
   {
     resto = aa % bb;
     aa = bb;
     bb = resto;
   }

   gotoxy(12,14);
   printf("(======================================================)");
   gotoxy(12,15);
   printf("(   ®® O resultado do MMC dos dois numeros eh ¯¯       )");
   gotoxy(12,16);
   printf("(=======================================================)");
   gotoxy(12,17);
   printf("# MMC(%d,%d) = %d",number1,number2,(a*b / aa));
   gotoxy(12,18);
   system("PAUSE");
   return 0;
 }

// funcao que calcula o mdc

int mdc_func(void)
 {
    int number1, number2, a, b, resto;

   clrscr();
   gotoxy(12,8);
   printf("(======================================================)");
   gotoxy(12,9);
   printf("(      ®® Calculando o MDC de dois numeros ¯¯          )");
   gotoxy(12,10);
   printf("(======================================================)");
   gotoxy(12,11);
   printf("# Entre com o primeiro numero : ");
   scanf("%d",&a);
   gotoxy(12,12);
   printf("# Entre com o segundo numero : ");
   scanf("%d",&b);
   gotoxy(12,13);
   printf("(-----------------------------------------------------)");
   gotoxy(12,14);
   printf("(              ®® Resultado do MDC ¯¯                 )");
   gotoxy(12,15);
   printf("(-----------------------------------------------------)");

   number1 = a;
   number2 = b;

   while(b != 0)
    {
      resto = a % b;
      a = b;
      b = resto;
    }
   gotoxy(12,17);
   printf("# MDC(%d,%d) = %d ",number1, number2, a);
   gotoxy(12,20);
   system("PAUSE");
   return 0;
}

// funcao que imprime uma tela de entrada para o programa

int entrada_programa(void)
 {
   clrscr();
   gotoxy(12,9);
   printf("(====================================================)\n");
   gotoxy(12,10);
   printf("(        Ataliba de Oliveira Teixeira                )");
   gotoxy(12,11);
   printf("(               Augusto Cesar                        )");
   gotoxy(12,12);
   printf("(               Junio Menezes                        )");
   gotoxy(12,13);
   printf("(                    Eneo                            )");
   gotoxy(12,14);
   printf("(                 Bruno Cesar                        )");
   gotoxy(12,15);
   printf("(                 Jose Ernesto                       )");
   gotoxy(12,16);
   printf("(====================================================)");
   printf("\n");

   system("PAUSE");
   return 0;

 }