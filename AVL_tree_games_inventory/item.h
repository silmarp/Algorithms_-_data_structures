
typedef struct Game Game;

Game *create_game(char CSV[1024]);
int ret_year(Game *game);
void destroy_game(Game *game);
char *ret_title(Game *game);
