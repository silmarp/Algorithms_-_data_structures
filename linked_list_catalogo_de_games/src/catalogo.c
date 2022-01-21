#include "catalogo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Catalog* create_catalog(){
  Catalog *head=NULL;
  return head;
}


void catalog_append(Catalog **head, Game *game){
  if(*head==NULL){
    *head = calloc(1,sizeof(Catalog));
    Catalog *list_index = *head;
    strcpy(list_index->game.name, game->name);
    strcpy(list_index->game.producer, game->producer);
    list_index->game.launch_year=game->launch_year;
    list_index->next=NULL;
    return;
  }
  while(*head != NULL){
    Catalog *aux = *head;
    head = &aux->next;
  }
  catalog_append(&*head, game);
  return;
}

// tornar em um print all para ajudar a debuggar
//
//
int catalog_query(Catalog *head){
  Catalog *list_index=head;
  int counter=0;
  printf("%s", list_index->game.name);
  while(list_index!=NULL){
    list_index = list_index->next;
    printf("%s", list_index->game.name);
    counter++;
  }
  counter++;
  return counter;
}


void destroy_list(Catalog *head){
  while(head != NULL){
    Catalog *destroy;
    destroy=head;
    head = head->next;
    free(destroy);
  }
  return;
}


Catalog *year_query(Catalog *head, int year){
  Catalog *results=create_catalog();
  while(head != NULL){
    if(head->game.launch_year == year){
      catalog_append(&results, &head->game);
    }
    head = head->next;
  }
  return results;
}


Catalog *producer_query(Catalog *head, char producer[50]){
  Catalog *results=create_catalog();
  while(head != NULL){
    if(strncmp(head->game.producer,producer,strlen(producer))==0){
      catalog_append(&results, &head->game);
    }
    head = head->next;
  }
  return results;
}
