/*      ««« False Shell 0.01a »»»
        Simulador de Shell em C 
Coder : Ataliba de Oliveira Teixeira < ataliba@ataliba.eti.br >
Site : < http://www.ataliba.eti.br >
Repositorio : < http://ataliba.eti.br/codes/projetos/false_shell/ >

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "commands.h"

/* funcoes que serao usadas no programa */

int boot_function(void);
int shell_function(void);

// corpo principal do programa 

main(void)
 {
    int i;
    
    printf("\033c"); // limpa a tela 
    
    // imprime como o false_shell.sh informacoes sobre o programa 
    
    printf("#############################################################\n");
    printf("#   Bem vindo ao FALSE SHELL 0.01a - SIMULADOR DE SHELL     #\n");
    printf("#  Ataliba de Oliveira Teixeira < ataliba@ataliba.eti.br >  #\n");
    printf("#  http://www.ataliba.eti.br/codes/projetos/false_shell     #\n");
    printf("#############################################################\n");
    
    system("sleep 2");
      
    printf("\033c"); // limpa a tela 
    printf("\n\n");
    
    /* simula o loading do kernel do linux */
    
    printf(" Loading false_shell ");
    
    for(i = 0;i < 8;i++)
      {
	 printf(". ");
	 system("sleep 2");
      }
    
    
    printf("\n");
    
    system("sleep 1");

    boot_function(); // chama a funcao que imprime as telas de boot 
    
    system("sleep 2");
    
    status = login_function();
    
    if(status == 1)
      {
	 shell_function();
      }
    
    
    }

/* funcao de boot - escreve o boot na tela */

int boot_function(void)
 {
   
    printf("\n");
    
    printf("Loading Linux ");
	
	for(i = 0;i < 10;i++)
	 printf(" . ");
	
	printf("\n");

	// continuar o boot do sistema ( ou entao, parar de vez este
	// codigo )
   
    
    
 }

 
/* funcao de login - login no sistema */

int login_function(void)
{
   
   printf("\nSeja bem vindo ao False Shell 0.01a\n");
   
   do
     {
	printf("Login : ");
	gets(login);
	fflush(stdin);
	printf("Password : ");
	gets(passwd);
	fflush(stdin);
	 }while(((login != "user") && (passwd != "user")) && ((login != "root") && (senha != "root")));
	
   return 1;
}

/* imprime o shell na tela ( primeira versao somente shell ) */
   
 int shell_function(void)
  {
    printf("false_shell@localhost ~/ $ ");

  } 
   
