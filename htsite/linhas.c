#include "hts.h"

void linha_unlink(linha_t ** l, field_t *fie){

  if(fie == NULL)
    return;

  if(*l == NULL)
    return;

  if((*l)->fie == fie){
    (*l) = (*l)->next;
    return;
  }

  linha_unlink(&(*l)->next, fie);
}

void linha_insert(linha_t ** l, field_t *fie, unsigned int num){
  linha_t * l_tmp;

  if(*l == NULL){
    l_tmp = (linha_t *)Malloc(sizeof(linha_t));

    l_tmp->num = num;
    l_tmp->fie = fie;

    l_tmp->next = *l;
    *l = l_tmp;
    return;
  }
  linha_insert(&(*l)->next, fie, num);
}

void linha_print(linha_t *l, unsigned int num){

  if(l == NULL)
    return;
  field_print(stdout, l->fie, num);
  linha_print(l->next, num);
  return;
}

void linha_set(char *what, linha_t ** l){
  linha_t * tmp = NULL;
  field_t * fie = NULL;
  char *ptr, *buf;
  unsigned int fnum, lnum;

  if(what == NULL)
    return;

  *l = NULL;
  ptr = what;
  lnum = fnum = 0;

  while(1){
    buf = cpytil(ptr, '\t', ';');
    if(buf == NULL)
      break;

    fnum++;
    field_insert(&fie, buf, fnum);

   if(strchr(ptr, '\t') > strchr(ptr, ';')
      || strchr(ptr,'\t') ==  NULL){
      lnum++;
      fnum = 0;
      linha_insert(&tmp, fie, lnum);
      fie = NULL;
    }

    ptr = ptr + strlen(buf);
    while(!isprint(*++ptr) && *ptr != 0);
  }
  *l = tmp;

  return;
}

void linha_free(linha_t ** l){
  linha_t * tmp;

  if(*l == NULL)
    return;

  field_free(&(*l)->fie);
  tmp = (*l)->next;
  free(*l);
  *l = tmp;

  linha_free(l);
  return;
}
