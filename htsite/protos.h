#ifndef __protos_h
#define __protos_h

char *Malloc(unsigned int);
char *pega(char *);
FILE *Fopen(char *, char *);
char *cpytil(char *, unsigned char, unsigned char);
void Erro(char *);
void processa(char *, FILE *);
void linha_set(char *, linha_t **);
void linha_insert(linha_t **, field_t *, unsigned int);
void field_print(FILE *, field_t *, unsigned int);
void format_print(field_t *, linha_t *, FILE *);
void format(char *, linha_t **, FILE *);
void format_field(field_t *, linha_t *, FILE *);
void refresh(char *, char *);
char *cpyttil(char *, unsigned char);
char *strcchr(char *, unsigned char);
char *tags(char *);
void lista_refresh(char *);
void lista_loop(linha_t *);
void linha_free(linha_t **);
void field_free(field_t **);
void field_insert(field_t **, char *, unsigned int);
char *field_get(field_t *, unsigned int);
void linha_unlink(linha_t **, field_t *);
void ordena(linha_t **, unsigned int);

#endif
