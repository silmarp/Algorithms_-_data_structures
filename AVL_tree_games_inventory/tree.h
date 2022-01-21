
typedef struct Node Node;

typedef struct Tree Tree;



// tree functions
Tree *create_tree();
void add_element_to_tree(Tree *tree, char CSV[1024]);
void access_test(Tree *tree);
void destroy_tree(Tree *tree);
void destroy_node(Node *node);

void traverse_by_rule(Tree *tree, int rule);
void traverse_inorder(Node *node);
void traverse_preorder(Node *node);
void traverse_postorder(Node *node);
void tree_query(Tree *tree, int query);
void test_rotation(Tree *tree);

// node functions
Node *create_node(unsigned int height, char CSV[1024]);
int node_query(Node *node, int querry, int boolean);
Node *rotate_node_left(Node *root);
Node *rotate_node_right(Node *root);
Node *add_element_recur(Node *root,Node *previous, Node *node_to_be_add);
Node *rotate_left_right(Node *root);
Node *rotate_right_left(Node *root);
int node_query_v2(Node *node, int query, int boolean);
void height_plus_correction(Node *root);
void height_minus_correction(Node *root);
void node_deletion(Tree *tree,int value_to_be_deleted);
Node *node_deletion_recur(Node *root, int value_to_be_deleted);
Node *smallest_node(Node *node);
void delete_smallest_node(Node *node);
