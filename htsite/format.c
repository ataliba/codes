#include "hts.h"

void format(char *what, linha_t ** lin, FILE *target){
  char *ptr, *be;
  unsigned int num;
  field_t *tmp;

  if(what == NULL)
    return;

  ptr = what;
  while(1){

    be = cpytil(ptr, '%', 0);
    if(be != NULL){
      field_insert(&tmp, be, 0);
    }

    ptr = strchr(ptr, '%');

    if(ptr == NULL)
      break;

    else
    if(*(ptr+1) == '%'){
      be = Malloc(2);
      strcpy(be, "%");
      field_insert(&tmp, be, 0);
      ptr+=2;
    }

    else{
      ptr++;
      num = atoi(ptr);
      ptr = strchr(ptr, '%') + 1;
      if(num == 0)
        Erro("Campo 0 nao existe");
      field_insert(&tmp, NULL, num);
    }
  }
  format_print(tmp, *lin, target);

  free(what);
}

void format_field(field_t * fie, linha_t * lin, FILE *target){
  if(fie == NULL)
    return;

  if(fie->num == 0)
    fprintf(target, "%s", fie->string);
  else
   field_print(target, lin->fie, fie->num);

  format_field(fie->next, lin, target);
  return;
}

void format_print(field_t * fie, linha_t * lin, FILE *target){

  if(lin == NULL)
    return;

  format_field(fie, lin, target);

  format_print(fie, lin->next, target);
  return;
}
