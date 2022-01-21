#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <string.h>

int main(){
  Tree *tree = create_tree();
//  char command;
  int amount;
  scanf("%i", &amount);
  getchar();

  for(int i=0;i<amount;i++){
    char csv[500];
    fgets(csv, 500, stdin);
    add_element_to_tree(tree, csv);
  }
 
  char command;
  scanf("%c",&command);
  getchar();

  //traverse_by_rule(tree, 2);
  //printf("\n");

  char input[500];
  switch(command){
    case 'B': fgets(input, 20, stdin);
              Node *node = query_by_cpf_str(tree, input);
              if(node != NULL){print_account(node);}
              else{printf("Pessoa nao encontrada.\n");}
              break;

    case 'I': fgets(input, 500, stdin);
              add_element_to_tree(tree, input);
              traverse_by_rule(tree, 2);
              break; 

    case 'R': fgets(input, 20, stdin);
              Node *node_R = query_by_cpf_str(tree, input);
              if(node_R != NULL){
                print_account(node_R);
                delete_node(tree, node_R);
              }
              else{printf("Pessoa nao encontrada.\n");}
              traverse_by_rule(tree, 2);
              break;
  }
  
  printf("\n");

  destroy_tree(tree);
}
