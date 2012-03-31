#include "hts.h"

char *tags(char *what){
  char *ptr;
  unsigned int count;

  if(what == NULL)
    return NULL;

  ptr = what;
  count = 1;
  while(*ptr != '\0'){
    if(*ptr == '<')
      count++;
    else
      if(*ptr == '>'){
      count--;
      if(count == 0)
        return ptr;
    }

    ptr++;
  }
  return NULL;
}
