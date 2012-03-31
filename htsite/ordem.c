#include "hts.h"
#define min(a, b) a > b ? b : a

short compara(char *um, char *dois){
  unsigned int lenght;

  if(um == NULL || dois == NULL)
    Erro("Null string ordenando");

  lenght = min(strlen(um), strlen(dois));

  do{
    if(*um == *dois){
      um++;
      dois++;
    }
    if(tolower(*um) < tolower(*dois))
      return 1;
    if(tolower(*dois) < tolower(*um))
      return 2;
  }while(--lenght);

  return strlen(um) < strlen(dois) ? 1 : 2;
}

linha_t *last_linha(linha_t *lin, linha_t *last, unsigned int num){

  if(lin == NULL)
    return last;

  if(last == NULL)
    last = lin; 

  if(compara(field_get(lin->fie, num), field_get(last->fie, num)) == 1)
    last = lin;

  return last_linha(lin->next, last, num);
}

linha_t *ordena_linha(linha_t ** lin, linha_t *nova, unsigned int num){
  linha_t *tmp;

  tmp = last_linha(*lin, NULL, num);
  if(tmp == NULL)
    return nova;

  linha_insert(&nova, tmp->fie, tmp->num);
  linha_unlink(lin, tmp->fie);
  free(tmp);

  ordena_linha(lin, nova, num);
}

void ordena(linha_t **lin, unsigned int num){

  if(!num)
    Erro("Nao existe campo 0");

  *lin = ordena_linha(lin, NULL, num);
}
