#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct Game{
  char title[500];
  unsigned int launch_year;
  char producer[500];
};

Game *create_game(char CSV[1024]){
  Game *game = calloc(1, sizeof(Game));
  
  // getting game name
  char *token = strtok(CSV, ";");
  strcpy(game->title, token);
  
  // getting year
  token = strtok(NULL, ";");
  game->launch_year = atoi(token);

  //getting producer
  token = strtok(NULL, ";");
  strcpy(game->producer, token);
    
  return game;
}

int ret_year(Game *game){
  return game->launch_year;
}

void destroy_game(Game *game){
  free(game);
}

char *ret_title(Game *game){
  return game->title;
}
