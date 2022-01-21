#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

// ### structs ###
struct Node{
  int row;
  int collum;
  int value;
  Node *next_node_right;
  Node *next_node_below;
};

struct Sparse_Matrix{
  Node **rows;
  Node **collums;
  int total_rows;
  int total_collums;
};


// ### FUNCTIONS ###
// --- creation --
Matrix *create_matrix(int rows, int collums){
  Matrix *matrix           = calloc(1, sizeof(Matrix));
  matrix->total_rows       = rows;
  matrix->total_collums    = collums;
  
  matrix->rows             = calloc(rows, sizeof(Node *));
  matrix->collums          = calloc(collums, sizeof(Node *));

  // assigns NULL to all rows/colluns
  for(int i=0;i<rows;i++)     {matrix->rows[i] = NULL;}
  for(int i=0;i<collums;i++)  {matrix->collums[i] = NULL;}

  return matrix;
}

Node *create_node(int row, int collum, int value){
  Node *node              = calloc(1, sizeof(Node));

  node->row               = row;
  node->collum            = collum;
  node->value             = value;

  node->next_node_right   = NULL;
  node->next_node_below   = NULL;
  
  return node;
}

// --- deletion functions ---
void delete_matrix(Matrix **matrix){
  //deleting nodes
  int rows = (*matrix)->total_rows;
  for(int i=0;i<rows;i++){
    if((*matrix)->rows[i]!=NULL){
      delete_nodes_recursion((*matrix)->rows[i]);
    }
  }
  free((*matrix)->rows);
  free((*matrix)->collums);
  free(*matrix);
  *matrix = NULL;
}

void delete_nodes_recursion(Node *node){ // Deletes entire row pass first item on row
  if(node->next_node_right != NULL){delete_nodes_recursion(node->next_node_right);}
  free(node);
}

// --- element addtion functions ---
void add_element(Matrix *matrix, int row, int collum, int value){
  row--;
  collum--;
  Node *node_to_be_add = create_node(row, collum, value);
  Node *next = matrix->rows[row];
  Node *previous=NULL;

  while(next != NULL){
    if(next->collum < collum){
      previous = next;
      next = next->next_node_right;
    }
    else{
      if(previous == NULL){
        matrix->rows[row] = node_to_be_add;
        node_to_be_add->next_node_right = next;
        break;
      }
      else{
        previous->next_node_right = node_to_be_add;
        node_to_be_add->next_node_right = next;
        break;
      }
    }
  }
  if(next == NULL){
    if(previous == NULL){
      matrix->rows[row] = node_to_be_add;
    }
    else{
      previous->next_node_right = node_to_be_add;
    }
  }

  next = matrix->collums[collum];
  previous=NULL;

  while(next != NULL){
    if(next->row < row){
      previous = next;
      next = next->next_node_below;
    }
    else{
      if(previous == NULL){
        matrix->collums[collum] = node_to_be_add;
        node_to_be_add->next_node_below = next;
        break;
      }
      else{
        previous->next_node_below = node_to_be_add;
        node_to_be_add->next_node_below = next;
        break;
      }
    }
  }
  if(next == NULL){
    if(previous == NULL){
      matrix->collums[collum] = node_to_be_add;
    }
    else{
      previous->next_node_below = node_to_be_add;
    }
  }



/*
  // case empty row
  if(matrix->rows[row] == NULL){matrix->rows[row] = node_to_be_add;}
  // case row already with elements
  else{
    Node *next_node = matrix->rows[row];
    Node *previous_node = NULL;
    while(next_node != NULL){
      if(next_node->collum < collum){
        previous_node = next_node;
        next_node = next_node->next_node_right;
      }
      else{break;}
    }
    if(previous_node == NULL){
      matrix->rows[row] = node_to_be_add;
      node_to_be_add->next_node_right = next_node;
    }
    else{
      previous_node->next_node_right = node_to_be_add;
      node_to_be_add->next_node_right = next_node;
    }
  }

  // case empty collum
  if(matrix->collums[collum] == NULL){matrix->collums[collum] = node_to_be_add;}
  // case collum already with elements
  else{
    Node *next_node = matrix->collums[collum];
    Node *previous_node = NULL;
    while(next_node != NULL){
      if(next_node->row < row){
        previous_node = next_node;
        next_node = next_node->next_node_below;
      }
      else{break;}
    }
    if(previous_node == NULL){
      matrix->collums[collum] = node_to_be_add;
      node_to_be_add->next_node_below = next_node;
    }
    else{
      previous_node->next_node_below = node_to_be_add;
      node_to_be_add->next_node_below = next_node;
    }
  }
*/
}



// --- utils ---
int get_value(Matrix *matrix, int row, int collum){
  if(row <= matrix->total_rows && collum <= matrix->total_collums){
    Node *node_value_return = matrix->rows[row];
    if(node_value_return != NULL){
      while(node_value_return->next_node_right != NULL && node_value_return->collum < collum){
        node_value_return = node_value_return->next_node_right;
      }
      if(node_value_return->collum == collum){
        return node_value_return->value;
      }
    }
  }
  return 0;
}

void print_matrix(Matrix *matrix){
  for(int i=0;i<matrix->total_rows;i++){
    for(int j=0;j<matrix->total_collums;j++){
      printf("%i ", get_value(matrix, i, j));
    }
    printf("\n");
  }
}

int find_path_recur(Matrix *matrix, Node *node, int to, int ret){
  if(node->collum < to && node->next_node_right != NULL){
    ret = find_path_recur(matrix, node->next_node_right, to, ret);
  }
  if(node->collum == to){ret = 1;}
  if(ret == 0 && matrix->rows[node->collum] != NULL){
    ret = find_path_recur(matrix, matrix->rows[node->collum], to, ret);
  }
  return ret;
}

void find_path(Matrix *matrix, int from, int to){
  from--;
  to--;
  int result = find_path_recur(matrix, matrix->rows[from], to, 0);
  if(result == 0){
  printf("No way \n");
  }
  else{
  printf("there's way\n");
  }
}
