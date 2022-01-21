#ifndef SPARSE_MATRIX
#define SPARSE_MATRIX

typedef struct Node Node;

typedef struct Sparse_Matrix Matrix;


Matrix *create_matrix(int rows, int collums);
Node *create_node(int row, int collum, int value);
void delete_matrix(Matrix **matrix);
void delete_nodes_recursion(Node *node);
void add_element(Matrix *matrix, int row, int collum, int value);
void print_matrix(Matrix *matrix);
int get_value(Matrix *matrix, int row, int collum);
void find_path(Matrix *matrix, int from, int to);



#endif //SPARSE_MATRIX
