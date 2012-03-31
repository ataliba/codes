/***********************************************
 file : usleep.c 
 Program : USleep
 Author : Ataliba de Oliveira Teixeira < ataliba@ataliba.eti.br >
 Home Page : http://www.ataliba.eti.br/codes/codes/shell_utils/
 ------------------------------------------------
 THIS CODE IS UNDER GPL LICENSE 2
 ------------------------------------------------
 ***********************************************
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define VERSION "Version 0.1.1"

int usage()
{
   printf("\n\033[34;1mUsleep : Suspend execution from a microsecond interval\033[m\n");
   printf("\033[31;1mUsage :\033[m \n\033[34;1musleep\033[m \033[37;1m[ Integer Argument ]\033[m \033[31;1m( default is 1 )\033[m\n");
   printf("\033[34;1musleep\033[m \033[37;1m[ OPTIONS ]\033[m\n");
   printf("\033[31;1mOPTIONS :\033[m\n");
   printf("\033[37;1m--help, -h, -help, --h to see this screen \033[m\n");
   printf("\033[37;1m-v, --v, -version, --version to see the version of the program\033[m \n");
   printf("\033[37;1mMore information :\033[m \033[34;1mhttp://www.ataliba.eti.br/codes/codes/shell_utils/ \033[m \n");
   printf("\033[37;1mTo report bugs :\033[m \033[34;1mataliba@ataliba.eti.br \033[m\n\n");
   
   return 0;
}

   

int main(int argc, char *argv[])
 {
   unsigned long int time_of_sleep = 1;
   
   switch(argc)
      {
	 
	 case 1:
	   {
	      usage();
	      exit(0); break;
	   }
	 
	 case 2:
	   {
	      if(strstr(argv[1],"--help") || strstr(argv[1],"--h") || strstr(argv[1],"-help") || strstr(argv[1],"-h"))
		{
		   usage();
		   exit(1);
	        }
	   
             if(strstr(argv[1],"-v") || strstr(argv[1],"-version") || strstr(argv[1],"--version") || strstr(argv[1],"--v"))
	        {
		   printf("\n\033[34;1m%s %s \033[m\n",argv[0],VERSION);
	           printf("\033[34;1m%s : Jarod Cybernetus SHELL Utils\033[m\n",argv[0]);
	           printf("\033[37;1mWriten by Ataliba Teixeira :\033[m \033[34;1mataliba@ataliba.eti.br\033[m\n");
	           printf("\033[37;1mCopyright (C) 1999 Free Software Foundation, Inc.\033[m\n");
	           printf("\033[37;1mThis is free software; see the source for copying conditions.  There is NO\033[m\n");
	           printf("\033[37;1mwarranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\033[m\n\n");
	           exit(1);
	        }
    
             time_of_sleep = atol(argv[1]);

             if(time_of_sleep == LONG_MAX)
	       {
		  printf("Number is too large\n");
	          printf("The argument must under  1 to %d \n",LONG_MAX);
	          exit(0);
               }
	     
             usleep(time_of_sleep);

             return 0;
	   }
	 
      }
    
  }


