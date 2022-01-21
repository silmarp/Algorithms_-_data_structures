#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct Node{
  Node *left_node;
  //Bank_account *item;
  //int number;
  Game *item;
  int height;
  Node *right_node;
};

struct Tree{
  Node *root;
  unsigned int total_items;
  unsigned int max_height;
};

Tree *create_tree(){
  Tree *tree = calloc(1, sizeof(Tree));
  tree->total_items = 0;
  tree->max_height = 0;
  tree->root = NULL;
  return tree;
}

Node *create_node(unsigned int height, char CSV[1024]){
  Node *node = calloc(1, sizeof(Node));
  node->left_node = NULL;
  node->right_node = NULL;
  node->height = height;
  node->item = create_game(CSV); 
  return node;
}

void add_element_to_tree(Tree *tree, char CSV[1024]){
  if(tree->root == NULL){ //inits the tree adding a root
    tree->root = create_node(0, CSV); // height == 0, element is root;
    tree->total_items++;
    return;
  }
  
  else{
    Node *node_to_be_add = create_node(0, CSV);
    Node *previous = tree->root;
    tree->root = add_element_recur(tree->root, previous, node_to_be_add);
  }

// ---- ancient adding method
//  
//  Node *current_node = tree->root;
//  Node *previous_node;
//  Node *node_to_be_add = create_node(0, input); 
//  
//  //------ locating null node to add ---------
//
//  while(current_node != NULL){
//    if(node_to_be_add->number > current_node->number){
//      previous_node = current_node;
//      current_node = current_node->right_node;
//    }
//    else if(node_to_be_add->number < current_node->number){
//      previous_node = current_node;
//      current_node = current_node->left_node;
//    }
//    else if(node_to_be_add->number == current_node->number){
//      // equal elements will not be added,
//      // our goal is to search for specific elements
//      // duplicates will make our method less efficient
//
//      return;
//    }
//    node_to_be_add->height++;
//  }
//  
//  // ------- adding node to null pointer ------
//  //
//  // when the loop finds a NULL position it will add the node_to_be_add
//  // to the previous_node->left|or|right _node depending on who was NULL
//  // and selected
//
//  if(node_to_be_add->number > previous_node->number){
//      previous_node->right_node = node_to_be_add;
//  }
//  else if(node_to_be_add->number < previous_node->number){
//      previous_node->left_node = node_to_be_add;
//  }
//  else if(node_to_be_add->number == previous_node->number){
//      previous_node->left_node = node_to_be_add;
//  }
//
//  tree->total_items++;
//  if(node_to_be_add->height > tree->max_height){
//    tree->max_height = node_to_be_add->height;
//  }
//
}

Node *add_element_recur(Node *root,Node *previous, Node *node_to_be_add){
  
  node_to_be_add->height++;
  
  if(ret_year(node_to_be_add->item) >= ret_year(root->item) && root->right_node != NULL){
    previous->right_node = add_element_recur(root->right_node,previous->right_node , node_to_be_add);
  }
  
  else if(ret_year(node_to_be_add->item) < ret_year(root->item) && root->left_node != NULL){
    previous->left_node = add_element_recur(root->left_node,previous->left_node, node_to_be_add);
  }
  
  if(ret_year(node_to_be_add->item) >= ret_year(root->item) && root->right_node == NULL){
      root->right_node = node_to_be_add;
  }
  else if(ret_year(node_to_be_add->item) < ret_year(root->item) && root->left_node == NULL){
      root->left_node = node_to_be_add;
  }


  //---- balancing the tree with rotations ----
  if(node_to_be_add->height - root->height == 2){ //node_to_be_add->height - root->height == 2){
    //root->left_node->height - root->right_node->height)==2
    // case 1:
    //      a  
    //     /
    //    b
    //   /
    //  c
    if(root->right_node == NULL && root->left_node->left_node == node_to_be_add){ // unbalance by the left => rotate right
      root = rotate_node_right(root);
    }
    /*
     case 2:
          a  
         /
        b
         \
          c
    */
    else if(root->right_node == NULL && root->left_node->right_node == node_to_be_add){
      root = rotate_left_right(root);
    }

    /*
     case 3:
          a  
           \
            b
             \
              c
    */
    else if(root->left_node == NULL && root->right_node->right_node == node_to_be_add){ // unbalance by the right => rotate left
      root = rotate_node_left(root);
    }
    /*
     case 4:
          a  
           \
            b
           /
          c
    */      
    else if(root->left_node == NULL && root->right_node->left_node == node_to_be_add){
      root = rotate_right_left(root);
    }
  }
  return root;  
}

void access_test(Tree *tree){
  Node *node = tree->root;
  while(node != NULL){
    printf("%i\n", node->height);
    node = node->right_node;
  }
}

void destroy_tree(Tree *tree){
  destroy_node(tree->root);
  free(tree);
  return;
}

void destroy_node(Node *node){
  if(node->left_node != NULL){
    destroy_node(node->left_node);
  }
  if(node->right_node != NULL){
    destroy_node(node->right_node);
  }
  //destroy_bank_account(node->item);
  //destroy_game(node->item);
  free(node);
}


// traverse the tree nodes using a given rule
void traverse_by_rule(Tree *tree, int rule){
  switch(rule){
    case 1: traverse_preorder(tree->root);
            return;

    case 2: traverse_inorder(tree->root);
            return;

    case 3: traverse_postorder(tree->root);
            return;
  }
}

void traverse_inorder(Node *node){
  if(node->left_node != NULL){
    traverse_inorder(node->left_node);
  }
  printf("%s\n", ret_title(node->item));
  if(node->right_node != NULL){
    traverse_inorder(node->right_node);
  }
}

void traverse_preorder(Node *node){
  printf("%s\n", ret_title(node->item));
  if(node->left_node != NULL){
    traverse_preorder(node->left_node);
  }
  if(node->right_node != NULL){
    traverse_preorder(node->right_node);
  }

}

void traverse_postorder(Node *node){
  if(node->left_node != NULL){
    traverse_postorder(node->left_node);
  }
  if(node->right_node != NULL){
    traverse_postorder(node->right_node);
  }
  printf("%s\n", ret_title(node->item));
}


void tree_query(Tree *tree, int query){
  // node_query starts with 0 assuming it doesn't find the target query
  switch(  node_query_v2(tree->root, query, 0)  ){
    case 0: printf("0\n");
            return;
      
    case 1: printf("1\n");
            return;
  }
}

// return a bool value
// 0 => false
// 1 => true

int node_query(Node *node, int query, int boolean){
  if (boolean == 1){
    return boolean;
  }
  if(ret_year(node->item) == query){
    boolean = 1;
    return boolean;
  }
  if(node->left_node != NULL){
    boolean = node_query(node->left_node, query, boolean);
  }
  if(node->right_node != NULL){
    boolean = node_query(node->right_node, query, boolean);
  }
  return boolean;
}

int node_query_v2(Node *node, int query, int boolean){
  if(query > ret_year(node->item) && node->right_node != NULL){
    boolean = node_query_v2(node->right_node, query, boolean);
  }
  else if(query < ret_year(node->item) && node->left_node != NULL){
    boolean = node_query_v2(node->left_node, query, boolean);
  }
  else if(query == ret_year(node->item)){
    boolean = 1;
  }
//  else if(query > node->number && node->right_node==NULL){
  //  boolean=0;
  //}
  //else if(query < node->number && node->left_node==NULL){
   // boolean=0;
  //}
  return boolean;
}

/*
 how rotation works::          
          a         rotate left:
          /\                <--
         n  b                  |
            /\              ---
           c  n       
 result:
            b         
           /\
          a  n       
         /\
        n  c          
 From:           To:
   n <-a-> b         n <-a-> c
   c <-b-> n         a <-b-> n

   a->height++           b->height--

 (a,b,c)-> important ; (n)-> doesn't change root & dependencies
 (n) -> changes height, needs correction
*/

Node *rotate_node_left(Node *root){
  Node *a = root;
  Node *b = root->right_node;
  Node *c = b->left_node;

  a->right_node = c;
  b->left_node = a;
  a->height++;
  b->height--;

  // height correction
  if(b->right_node != NULL){
    height_minus_correction(b->right_node);
  }
  
  if(a->left_node != NULL){
    height_plus_correction(a->left_node);
  }

  return b; // b == new root
}

/* 
  how rotation works::          
           a         rotate right:
          /\                -->
         b  n              |
         /\                 ---
        n  c     
 result:
            b         
           /\
          n  a       
             /\
            c  n         
 From:           To:
   b <-a-> n         c <-a-> n
   n <-b-> c         n <-b-> a

 (a,b,c)-> important ; (n)-> doesn't change root & dependencies
 (n) -> changes height, needs correction
*/

Node *rotate_node_right(Node *root){
  Node *a = root;
  Node *b = root->left_node;
  Node *c = b->right_node;

  a->left_node = c;
  b->right_node = a;
  a->height++;
  b->height--;
  
  // height correction
  if(b->left_node != NULL){
    height_minus_correction(b->left_node);
  }
  
  if(a->right_node != NULL){
    height_plus_correction(a->right_node);
  }

  return b; // b == new root
}

Node *rotate_left_right(Node *root){
  root->left_node = rotate_node_left(root->left_node);
  return rotate_node_right(root);
}

Node *rotate_right_left(Node *root){
  root->right_node = rotate_node_right(root->right_node);
  return rotate_node_left(root);
}

void test_rotation(Tree *tree){
 Node *root = tree->root;
 tree->root = rotate_node_right(root);
}

void height_plus_correction(Node *root){
  root->height++;
  Node *current = root->right_node;

  while(current != NULL){
    current->height++;
    current = current->right_node;
  }

  current = root->left_node;

  while(current!= NULL){
    current->height++;
    current = current->left_node;
  }
}

void height_minus_correction(Node *root){
  root->height--;
  Node *current = root->right_node;

  while(current != NULL){
    current->height--;
    current = current->right_node;
  }

  current = root->left_node;

  while(current!= NULL){
    current->height--;
    current = current->left_node;
  }
}

void node_deletion(Tree *tree,int value_to_be_deleted){
  for(int i = 0;i<5;i++){
    tree->root = node_deletion_recur(tree->root, value_to_be_deleted);
  }
}

Node *node_deletion_recur(Node *root, int value_to_be_deleted){
  if(root == NULL){return root;}

  //Find node to be excluded
  if(ret_year(root->item) > value_to_be_deleted){
    root->left_node = node_deletion_recur(root->left_node, value_to_be_deleted);
  }

  else if(ret_year(root->item) < value_to_be_deleted){
    root->right_node = node_deletion_recur(root->right_node, value_to_be_deleted);
  }

  // ret_year(root->item) == value_to_be_deleted ===> Deletion
  else{
    // 1 case, node with one child
    if(root->right_node == NULL){
      Node *new_root = root->left_node;
      free(root);
      return new_root;
    }
    else if(root->left_node == NULL){
      Node *new_root = root->right_node;
      free(root);
      return new_root;   
    }
    
    // 2 case, node with two children
    // deletion rule = new_root = smalest value from the highest son
    Node *new_root = smallest_node(root->right_node);
    
    //Game *tmp = root->item;
    root->item = new_root->item;
    
    root->right_node = node_deletion_recur(root->right_node, ret_year(new_root->item)); 
    
    //destroy_game(tmp);
  }
  // Balancing tree
  








    return root;
}


Node *smallest_node(Node *node){
  while(node->left_node != NULL){
    node = node->left_node;
  }
  return node;


}

void delete_smallest_node(Node *node){

  Node *next_node = node->right_node;
  while(next_node->left_node != NULL){
    node = next_node;
    next_node = next_node->left_node;
  }
  
  if(next_node->right_node != NULL){
    Node *tmp = next_node->right_node;
    node->left_node = tmp;
  }
  else{
    node->left_node = NULL;
  }
  free(next_node);
}


