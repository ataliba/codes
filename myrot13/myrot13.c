/*
 file - myrot13.c
 Author : Ataliba Teixeira < ataliba dot ataiba.eti.br >
 based on Rot13 with lookup table in C
 Teknovore <tek@wiw.org> 199[78]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.1a"
#define AUTHOR "Ataliba Teixeira"
#define AUTHOR_SITE "http://www.ataliba.eti.br"

char
table[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,78,79,80,81,82,83,84,85,86,87,88,89,90,65,66,67,68,69,70,71,72,73,74,75,76,77,91,92,93,94,95,96,110,111,112,113,114,115,116,117,118,119,120,121,122,97,98,99,100,101,102,103,104,105,106,107,108,109,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};

// as funcoes a serem usadas no programa 

int print_version()
{
  printf("Myrot13 implementantion \n");
  printf("The simple Caesar-cypher encryption that replaces each English letter with the one 13 places forward or back along the alphabet\n");
  printf("Version %s by %s \n",VERSION,AUTHOR);
  printf("More information on the site %s\n\n",AUTHOR_SITE);
  return 0;
}

int print_help()
 {
 	printf("myrot13 version %s\n",VERSION);
 	printf("Usage : myrot13 string\nFor more information visit %s\n",AUTHOR_SITE);
 	return 0;
 }
int main(int argc , char *argv[]) {
   char c, string2[200];
   int i, number;
   
   if(!(strcmp(argv[0],"./")))
    {
    	if(argc < 3)
    	{
    	  print_help();
    	  exit(0);
    	}
    	else
    	 if(argc > 3)
    	 {
    	 	print_help();
    	 	exit(0);
    	 }
    	strcpy(string2,argv[2]);
    	  
    }   
   else
    {
       if(argc < 2)
       {
       	 print_help();
       	 exit(0);
       }
       else if(argc > 2)
              {
              	print_help();
              	exit(0);
              }
              
       strcpy(string2,argv[1]);
    }
    
   number = strlen(string2);
   
   for(i = 0; i <= number; i++)
    {  
       c = string2[i];	 
       write(1,&table[c],1);
    }
    
    printf("\n\n");
    
    return 0;
 
}