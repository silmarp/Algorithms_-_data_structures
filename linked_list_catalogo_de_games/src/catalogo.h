#ifndef Catalogo_included
#define Catalogo_included

#include "games.h"

// structs
struct list_of_games{
  Game game;
  struct list_of_games* next;
};
typedef struct list_of_games Catalog;

// structs --------
// methods
Catalog *create_catalog();

void catalog_append(Catalog **head, Game *game);

int catalog_query(Catalog *head);

void destroy_list(Catalog *head);

Catalog *year_query(Catalog *head, int year);

Catalog *producer_query(Catalog *head, char producer[50]);

// methods --------

#endif //Catalogo_included
