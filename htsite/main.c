#include "hts.h"

void uso(char *arg){

  if(arg == NULL)
    return;

  fprintf(stderr,
    "Uso:\n"
    "htsite ([arquivo fonte] [arquivo alvo])\n"
    "Nao passe argumentos para usar lista htsite.txt\n"
  );
  exit(0);
}



int main(int argc, char **argv){

  fprintf(stderr, "htsite - simples programa para geracao de paginas html.\n"
    "feito por hts - plex15@linuxbr.com.br - www.paginadoht.st\n"
    "favor enviar comentarios, criticas e sugestoes para plex15@linuxbr.com.br\n"
    "Agradecimentos a unsekscene e w2x\n\n");

  if(argc == 1){
    printf("Atualizando arquivos em htsite.txt:\n");
    lista_refresh("./htsite.txt");
  }
  else
  if(argc == 2)
    uso(argv[0]);
  if(argc == 3){
    printf("Atualizando %s - %s\n", argv[1], argv[2]);
    refresh(argv[1], argv[2]);
  }
  exit(0);
  return 0;
}
