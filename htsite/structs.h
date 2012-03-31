#ifndef __structs_h
#define __structs_h

typedef struct field{
  char *string;
  unsigned int num;
  struct field *next;
} field_t;

typedef struct linha{
  struct field *fie;
  struct linha *next;
  unsigned int num;
} linha_t;

#endif
