
typedef struct Node Node;

typedef struct Tree Tree;



// tree functions
Tree *create_tree();
void add_element_to_tree(Tree *tree, char csv[500]);
void access_test(Tree *tree);
void destroy_tree(Tree *tree);
void destroy_node(Node *node);
void traverse_by_rule(Tree *tree, int rule);
void traverse_inorder(Node *node);
void traverse_preorder(Node *node);
void traverse_postorder(Node *node);
Node *query_by_cpf_str(Tree *tree, char cpf[10]);

// node functions
void delete_node(Tree *tree, Node *node_to_be_excluded);
Node *recursive_node_deletion(Node *root, unsigned long int cpf);
Node *create_node(unsigned int height, char csv[500]);
void print_account(Node *node);
Node *get_min_value_node(Node *node);
