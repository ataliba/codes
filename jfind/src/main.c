/* jfind - Jarod Cybernetus ls 
   Small implementation of a find archive
   Ataliba Teixeira Softtware 
   Author : Ataliba Teixeira aka Jarod Cybernetus
   Mailto : ataliba@ataliba.eti.br
   http://www.ataliba.eti.br/projects/l_commands
   */
   
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/types.h>

#define PROG_ERROR "JFIND ERROR"
#define PROG_NAME "JFIND"
#define EXEC_NAME "jfind"
#define VERSION "0.1"

int print_version(void);
int print_help(void);

int main(int argc, char *argv[])
{
     DIR *dir;
     struct dirent *dir_pointer;
	char  dirname[50], extension[6];
	char tmp_str[50];
	 
	 // open the directory and, if the command returns 
	 // the NULL result, we have an error message
	
    if(argc == 2)
	{
		if(strstr(argv[1],"--h") || strstr(argv[1],"-h") || strstr(argv[1],"-help") || strstr(argv[1],"--help"))
			print_help();
		if(strstr(argv[1],"-v") || strstr(argv[1],"-version"))
			print_version();
		printf("\n");
		
		return 0;
	}
	
	if(argc < 3)
	{
          sprintf(tmp_str,"! %s ! Error in this command use \n",PROG_ERROR);
		  printf("%s",tmp_str);
          printf("Use : %s [ path for the dir ] [ extension of the archive ]\nOr -h to see the the help of the program\n", EXEC_NAME);
		  exit(0);
    }
	
	sprintf(dirname,"%s",argv[1]);
	sprintf(extension,"%s",argv[2]);
	
	if((dir = opendir(dirname)) == NULL)
	{
		sprintf(tmp_str,"\n! %s ! : Error open directory. \n",PROG_ERROR);
		printf("%s",tmp_str);
		exit(0);
	}

    printf("\n=> Archives contains the string %s in the dir %s \n",extension,dirname);
	
	while((dir_pointer = readdir(dir)))
	{
		if(!strcmp(dir_pointer->d_name,".") || !strcmp(dir_pointer->d_name,"..") || !strcmp(dir_pointer->d_name,extension)) continue;
		
		if(strstr(dir_pointer->d_name,extension))
		 {
			printf("=> %s/%s \n",dirname,dir_pointer->d_name); 
		 }			 
	}	
	
	printf("\n");
	// close the directory open in the program
	
	(void)closedir(dir);
    return 0; 	 
}

// function to print the version of the program

int print_version(void)
{
	printf("\n=> Welcome to the version %s of the jfind program \n",VERSION);
	printf("=> Version %s\n=>Author : Ataliba Teixeira < ataliba@ataliba.eti.br >\n",VERSION);
	printf("=> Site : http://www.ataliba.eti.br/codes/codes/jfind\n");
	return 0;
}

int print_help(void)
{
	printf("\n! Help of %s program !\n",PROG_NAME);
    printf("Use : %s [path.to/dir ] [ name of the file ]\n",EXEC_NAME);
    printf("Example : jfind /usr/src  test\n");
    printf("Options : \n-h -> print this help \n-v -> print the version of the program\n");
    return 0;
}
