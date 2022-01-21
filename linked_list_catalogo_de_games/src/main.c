#include "games.h"
#include <stdio.h>
#include <stdlib.h>
#include "catalogo.h"
#include <string.h>



int main(){
  char F[]="F\0", A[]="A\0",E[]="E\0";  // comandos F=encerra A=pesquisa por ano E=pesquisa por empresa
  Catalog *game_list = create_catalog();

  while(1){ //armazena os jogos em uma lista
    Game *game=calloc(1,sizeof(Game));
    fflush(stdin); 
    scanf("%[^\n]", game->name);
    getchar();
    fflush(stdin);

    if(strncmp(F, game->name, strlen(F))==0){
      free(game);
      break;
    }
    scanf("%[^\n]", game->producer);
    getchar();
    fflush(stdin);

    scanf("%i", &game->launch_year);
    getchar();
    fflush(stdin);
    catalog_append(&game_list , game);
    free(game);
  }
  

  while(1){  // le o comando e executa ele
    char command[5];
    fflush(stdin);
    scanf("%[^\n]", command);
    getchar();
    fflush(stdin);

    if(strncmp(F,command,strlen(F))==0){ //encerra o programa
      destroy_list(game_list);
      break;
    }
    
    else if(strncmp(A, command, strlen(A))==0){ //query por ano
      int year;
      scanf("%i", &year);
      getchar();
      fflush(stdin);
      Catalog *results = year_query(game_list, year);
      if(results == NULL){
        printf("Nada encontrado\n");
        destroy_list(results);
        continue;
      }
      Catalog *aux=results;
      while(aux != NULL){
        printf("%s\n",aux->game.name);
        aux = aux->next;
      }
      destroy_list(results);
    }
    
    else if(strncmp(E, command, strlen(E))==0){ //query por empresa
      char producer[50];
      fflush(stdin);
      scanf("%[^\n]", producer);
      getchar();
      fflush(stdin);
      Catalog *results = producer_query(game_list, producer);
      if(results == NULL){
        printf("Nada encontrado\n");
        destroy_list(results);
        continue;
      }
      Catalog *aux = results;
      while(aux != NULL){
        printf("%s\n",aux->game.name);
        aux = aux->next;
      }
      destroy_list(results);
    }
  }
  return 0;
}
