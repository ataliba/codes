#include "hts.h"

void printall(unsigned int ordem, char *file, char *fstring, FILE *target){
  char *fbuf;
  linha_t *lin;

  if(fstring == NULL || file == NULL)
    return;

  fbuf = pega(file);
  free(file);
  if(!fbuf)
    Erro("Arquivo de dados nao encontrado");

  linha_set(fbuf, &lin);
  free(fbuf);

  if(ordem != 0)
  ordena(&lin, ordem);

  format(fstring, &lin, target);
}

void processa(char *what, FILE *target){
  char *ptr, *buf, *buf2;
  linha_t *lin;
  short ordem = 0;

  if((ptr = strstr(what, "printall "))){
    ptr += strlen("printall");

ordem:
    ptr++;
    if(*(ptr++) != '$')
      Erro("falta $.");

    if((strchr(buf, '$') - buf) > 50)
      Erro("$$: nome de arquivo muito extenso");
    buf = cpytil(ptr, '$', 0); // !!!
    if(buf == NULL)
      return;

    ptr = strchr(ptr, '$') + 1;
    if(!strncmp(buf, "ordena", strlen("ordena"))){
      ordem = atoi(buf + strlen("ordena") + 1);
      free(buf);
      goto ordem;
    }

    ptr = strchr(ptr, '\"') + 1;

    buf2 = pega(buf);
    free(buf);
    if(buf2 == NULL)
      Erro("arquivo nao encontrado.");

    linha_set(buf2, &lin);
    free(buf2);

    if(ordem != 0)
      ordena(&lin, ordem);

    buf2 = cpyttil(ptr, '\"');

    format(buf2, &lin, target);
    linha_free(&lin);
  }

  free(what);
  return;
}
