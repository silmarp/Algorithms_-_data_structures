#include "tree.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct Node{
  Node *left_node;
  Bank_account *item;
  unsigned int height;
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

Node *create_node(unsigned int height, char csv[500]){
  Node *node = calloc(1, sizeof(Node));
  node->left_node = NULL;
  node->right_node = NULL;
  node->height = height;
  node->item = create_bank_account(csv); 
  return node;
}

void add_element_to_tree(Tree *tree, char csv[500]){
  if(tree->root == NULL){ //inits the tree adding a root
    tree->root = create_node(0, csv); // height == 0, element is root;
    tree->total_items++;
    return;
  }
  
  Node *current_node = tree->root;
  Node *previous_node;
  Node *node_to_be_add = create_node(0, csv); 
  
  while(current_node != NULL){
    if(return_cpf(node_to_be_add->item) > return_cpf(current_node->item)){
      previous_node = current_node;
      current_node = current_node->right_node;
    }
    else if(return_cpf(node_to_be_add->item) < return_cpf(current_node->item)){
      previous_node = current_node;
      current_node = current_node->left_node;
    }
    else if(return_cpf(node_to_be_add->item) == return_cpf(current_node->item)){
      printf("error, duplicated cpf \n");
      return;
    }
    node_to_be_add->height++;
  }
  
  // when the loop finds a NULL position it will add the node_to_be_add
  // to the previous_node->left|or|right _node depending on who was NULL
  // and selected

  if(return_cpf(node_to_be_add->item) > return_cpf(previous_node->item)){
      previous_node->right_node = node_to_be_add;
  }
  else if(return_cpf(node_to_be_add->item) < return_cpf(previous_node->item)){
      previous_node->left_node = node_to_be_add;
  }

  tree->total_items++;
  if(node_to_be_add->height > tree->max_height){
    tree->max_height = node_to_be_add->height;
  }
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
  destroy_bank_account(node->item);
  free(node);
}


// traverse the tree nodes using a given rule
// inorder:     | rule => 1
// preorder:    | rule => 2
// postorder:   | rule => 3

void traverse_by_rule(Tree *tree, int rule){
  switch(rule){
    case 1: printf("Inorder\n");
            traverse_inorder(tree->root);
            return;

    case 2: printf("Preorder\n");
            traverse_preorder(tree->root);
            return;

    case 3: printf("Postorder\n");
            traverse_postorder(tree->root);
            return;
  }
}

void traverse_inorder(Node *node){
  if(node->left_node != NULL){
    traverse_inorder(node->left_node);
  }
  print_cpf(node->item);
  if(node->right_node != NULL){
    traverse_inorder(node->right_node);
  }
}

void traverse_preorder(Node *node){
  print_cpf(node->item);
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
  print_cpf(node->item);
}

Node *query_by_cpf_str(Tree *tree, char cpf[20]){
  unsigned long int cpf_int = convert_cpf_str_to_cpf_int(cpf);
  Node *current_node = tree->root;
 
  while(current_node != NULL){
    if(cpf_int > return_cpf(current_node->item)){
      current_node = current_node->right_node;
    }
    else if(cpf_int < return_cpf(current_node->item)){
      current_node = current_node->left_node;
    }
    else if(cpf_int == return_cpf(current_node->item)){
      return current_node;
    }
  }
}

void print_account(Node *node){
  print_info(node->item);
}


void delete_node(Tree *tree, Node *node_to_be_excluded){
  unsigned long int cpf = return_cpf(node_to_be_excluded->item);
  tree->root = recursive_node_deletion(tree->root, cpf);
}


Node *recursive_node_deletion(Node *root, unsigned long int cpf){
  if(root == NULL){return root;}

  if(cpf > return_cpf(root->item)){
    root->right_node = recursive_node_deletion(root->right_node, cpf);
  }
  else if(cpf < return_cpf(root->item)){
    root->left_node = recursive_node_deletion(root->left_node, cpf);
  }

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
    Node *new_root = get_min_value_node(root->right_node);
    
    Bank_account *tmp = root->item;
    root->item = new_root->item;
    
    root->right_node = recursive_node_deletion(root->right_node, return_cpf(new_root->item)); 
    
    destroy_bank_account(tmp);
  }

  return root;
}

Node *get_min_value_node(Node *node){
  while(node->left_node != NULL){
    node = node->left_node;
  }
  return node;
}
