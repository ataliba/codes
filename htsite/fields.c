#include "hts.h"

void field_insert(field_t ** f, char *string, unsigned int num){
  field_t * tmp;

  if(*f == NULL){
    tmp = (field_t *) Malloc(sizeof(field_t));
    tmp->string = string;
    tmp->num = num;

    tmp->next = *f;
    *f = tmp;
  return;
  }else
     field_insert(&(*f)->next, string, num);
}

char *field_get(field_t * f, unsigned int num){

  if(f == NULL)
    return NULL;

  if(f->num == num)
    return f->string;

  return field_get(f->next, num);
}

void field_print(FILE *target, field_t *f, unsigned int num){

  if(f == NULL){
    fprintf(stderr, "%d: ", num);
    Erro("campo nao encontrado");
  }
  if(f->num == num){
    if(f->string != NULL)
      fprintf(target, "%s", f->string);
    return;
  }
  field_print(target, f->next, num);
}

void field_free(field_t ** f){
  void * tmp;

  if(*f == NULL)
    return;

  tmp = (*f)->next;
  free((*f)->string);
  free(*f);
  *f = tmp;

  field_free(f);
}
