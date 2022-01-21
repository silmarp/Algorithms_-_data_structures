#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "item.h"
#include <string.h>

int main(){
  FILE *fp;
  fp = fopen("CSV.csv", "r");
  if (fp == NULL) {
    printf("Erro\n");
    return 1;
  }
  // jump 3 initial bytes (indicates UTF-8)
  fseek(fp, 3, SEEK_CUR);

  Tree *tree = create_tree();
  
  char line[1024]; 
  char previous[1024];

  do{
    fgets(line,1024 , fp);
    
    
    if(strncmp(line, previous, strlen(line))==0){
      break;
    }
    else {
      strcpy(previous, line);
    }
    

    add_element_to_tree(tree, line);
  }while(feof(fp)==0);

  int rule;
  scanf("%i", &rule);
  getchar();

  char command[6];
  
  // Program loop
  while(1){
    scanf("%s", command);
    if(atoi(command)!=0){
      node_deletion(tree, atoi(command));
    }
    else{
      break;
    }
    getchar();
  }

  traverse_by_rule(tree, rule);

  destroy_tree(tree);

  
}


