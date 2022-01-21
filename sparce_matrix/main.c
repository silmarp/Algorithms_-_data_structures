#include <stdio.h>
#include "matrix.h"

int main(){
  int dimension, elements;
  scanf("%i %i",&dimension, &elements);
  getchar();
  Matrix *matrix = create_matrix(dimension, dimension);

  for(int i=0; i<elements;i++){
    int origin, destination, distance;
    scanf("%i %i %i", &origin, &destination, &distance);
    getchar();
    add_element(matrix, origin, destination, distance);
  }
  
  find_path(matrix, 1, 4);
  // TO DO encontrar caminho;
  print_matrix(matrix);
  delete_matrix(&matrix);
}



