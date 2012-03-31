#include "hts.h"

void Erro(char *err){
  fprintf(stderr, "Erro %s.\n", err);
  exit(-1);
}

FILE *Fopen(char *filename, char *modes){
  FILE *ret;

  ret = fopen(filename, modes);
  if(!ret)
    Erro(filename);

  return ret;
}

char *Malloc(unsigned int size){
  char *ret;

  ret = malloc(size);
  if(!ret)
    Erro("01");

  bzero(ret, size);

  return ret;
}


char *pega(char *filename){
  FILE *fd;
  char *ret, *ptr;
  unsigned int count;

  if(filename == NULL)
    return NULL;

  fd = Fopen(filename, "r");
  for(count = 0 ; !feof(fd) ; count++, fgetc(fd));
  rewind(fd);

  ptr = ret = Malloc(count);
  while(--count)
    *ptr++=fgetc(fd);
  fclose(fd);
   
  return ret;
}

char *cpytil(char *buf, unsigned char ch, unsigned char ch2){
  char *ret, *ptr;
  unsigned int count = 0;

  ptr = strchr(buf, ch);
  if(strchr(buf, ch2) < ptr || ptr == NULL)
    ptr = strchr(buf, ch2);

  if(ptr == NULL)
    return NULL;

  count = ptr - buf;
  if(count > 1000)
    Erro("aumente o maximo de cpytil"); 

  ptr = ret = Malloc(++count);

  while(--count)
    *ptr++=*buf++;

  return ret;
}

char *strcchr(char *buf, unsigned char ch){
  char *ptr;

  ptr = strchr(buf, '\0');
  while(*ptr != ch)
    ptr--;

  return ptr;
}

char *cpyttil(char *buf, unsigned char ch){
  char *ret, *ptr;

  unsigned int count = 0;

  ptr = strcchr(buf, ch);
  if(ptr == NULL)
    return NULL;

  count = ptr - buf;

  ret = ptr = Malloc(++count);

  while(--count)
    *ptr++ = *buf++;

  return ret;
}

int iswhite(char c){

  if(c==' ' || c=='\t') return 1;
  else return 0;

}

int isdelim(char c){

  if(c == ' ' || c == '\t')
    return 1;
  return 0;

}
