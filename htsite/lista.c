#include "hts.h"

void lista_refresh(char *filename){
  char *buf;
  linha_t *lin = NULL;

  buf = pega(filename);

  linha_set(buf, &lin);
  lista_loop(lin);

  linha_free(&lin);
}

void lista_loop(linha_t *lin){

  if(lin == NULL)
    return;

  if(lin->fie->string == NULL)
    if(lin->fie->next->string == NULL)
      Erro("Erro na lista");

  printf("Atualizando %s - %s\n", lin->fie->string, lin->fie->next->string);
  refresh(lin->fie->string, lin->fie->next->string);

  lista_loop(lin->next);
  return;
}
