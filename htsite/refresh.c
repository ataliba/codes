#include "hts.h"

void refresh(char *name, char *alvo){
  char *buf, *ptr, *ptr2, *tmp;
  FILE *target;

  if(name == NULL)
    return;

  if(alvo == NULL)
    target = stdout;
  else
    target = Fopen(alvo, "w");

  ptr = buf = pega(name);

  while(1){
    if(*ptr == '<'){
      if(++ptr == '\0')
        break;
      else
      if(ptr == strstr(ptr, "hts")){

        ptr2 = ptr + strlen("hts");
        ptr = tags(ptr2);
        if(ptr++ == NULL)
          Erro(">");

        tmp = Malloc(ptr - ptr2);
        strncpy(tmp, ptr2, ptr - ptr2 - 1);
        processa(tmp, target);
      }
      else fputc('<', target);
    }
    if(*ptr == '\0') break;
    fputc(*(ptr++), target);
  }

  if(target != stdout)
    fclose(target);
  free(buf);
}
