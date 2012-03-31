/* 02022002 - Inicio da Implementacao
 * 00002003 - Primeiro codigo liberado para o publico
 * Autor : J@r0d Cyb3rn3tuS < jarodcybernetus@subdimension.com >
 * http://www.ataliba.eti.br/projetos/false_shell/
 *
 * este eh um programa que tem a intencao de simular uma interface shell
 * mas, como todo programinha tem suas falhas. com o tempo espero sana-las e 
 * se voce achar que tem algum code que pode ajudar aqui, mande-o. se tem alguma 
 * ideia que ache legal ser implementada nas proximas versoes, mande um e-mail. e 
 * se gostou use e mande um mail tambem :) eh bom saber quem ta usando e o que ta 
 * achando do programa. o codigo ta ai, so peco que qualquer mudanca feita, seja 
 * mandada pro autor, pois pode ajudar nas proximas versoes do programa.
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <ctype.h>
 // #include "comandos.h"

 #define VERSION "Linux Simulator 0.01a 2003"

 struct diretorio 
  {
     char *diretorio;
     char *arquivo;
     char *state;
  };
  
 /* declaracao das funcoes que serao usadas no programa */

 int printlogin(void);

 void printboot(void);

 int shell_principal(char *usuario);

 int print_saida(void);

 char user[10];
 
 /* declaracao de strutcs e variaveis globais */

 
 /* funcao principal do programa  */

  main()
   {
     int state;
	 char *usuario;
	 
	 printf("\033c");

     printboot(); /* funcao que imprime o boot do sistema */
     
	 do 
	  {
        state = printlogin();
	  }while(state == 1);

    shell_principal(user);
      
   }


 void printboot(void)
  {
        printf("Iniciando o Linux Simulator 2003 \n");
	system("sleep 3");

	printf("\n");
	printf("Memoria total real : 8388608\n");
	printf("Memoria a ser utilizada : 7122944\n");

	system("sleep 2");

	printf("\n");

	printf("%s \n", VERSION);
	printf("\n");
	
	printf("Copyright (c) 2003\n");
	printf("Todos os direitos reservados\n");
	printf("Linux é uma marca registrada por Linus Torvalds\n");

	printf("\n");
	printf("Carregando servicos \n");
	system("sleep 5");

	printf("Wangtek PC-36/EV-811 cartridge tape controller was found
	address 00000300H.\n");

	printf("\n");
    
        printf("PC586 v2.7 Copyright(c) 1987,1988,1989 Intel Corp., AllRights Reserved\n");
	printf("PC586 board 0 was found, Ethernet Address: 00:00:1c:00:02:f0\n");
	printf("Node: matrix\n");
	printf("The system is coming up. Please wait.\n");
   
	system("sleep 2");

}	

     int printlogin(void)
	  {
	   
	    char login[20], senha[20];

	    printf("\n");
	    printf("Welcome to Linux Simulator 0.01a\n");
	    printf("Jarod Cybernetus Software 2003\n");
	    printf("Login : ");
	    fflush(stdin);
	    gets(login);
	    
	    if(!(strcmp(login,"root")))
	       {
		  fflush(stdin);
		  printf("Senha : ");
		  gets(senha);
		  
		  if(!(strcmp(senha,"root")))
		       {
			  strcpy(user,login);
			  return 0;
		       }
		  else
		       {
			  printf("Senha Incorreta !! Favor conferir seus registros !!! ");
			  return 1;
		       }
	       }
	     
	     else
	       { 
		  printf("Usuario Incorreto !!! Não existe em nosso sistema \n");
		  return 1;
               }
	     
	     	

	   }	

   int shell_principal(char *usuario)
      {
       
	 char comando[40];
	 char *diretorio = ' ~ ';
         int comando1;
	 
	 for(;;)
	   {
	      
	     if(!(strcmp(usuario,"root")))
		{		
		   printf("%s@machine # ",usuario);
		}
	     else 
       	        {
		   printf("%s@machine $ ",usuario);
		}
	      
	     fflush(stdin);
	     gets(comando);
             
	     if(!(strcmp(comando,"exit")))
		{
		   
		   print_saida();
		   return 0;
		}
	     else if(!(strcmp(comando,"logout")))
		    {
		       print_saida();
		       return 0;
		    }
	      
	     
	     switch(comando1)
		{
		 case -1073744536 :
		   printf("\033c");
		   break;
		 case   
	   }
	 
      }

   

  int print_saida(void)
     {
	system("sleep 1");
	printf("\033c");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n");
	printf("$       Saindo do Linux Simulator 0.01a 2003             $ \n");
	printf("$ < http://www.ataliba.eti.br/codes/codes/false_shell/ > $ \n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n");
	
	system("sleep 2");
	
	return 0;
     }

		 
 
