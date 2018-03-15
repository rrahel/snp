#include <stdlib.h>
#include <assert.h>
#include "bheap.h"
#include <stdio.h>
#include <string.h>
#include <memory.h>

void bheap_init(bheap *h) {
  h->root_node = NULL;
}


int bheap_remove_min(bheap *h) {
  // TODO: Remove a node with minimal priority (the root node).
  // Return the priority of the removed node, or return HEAP_EMPTY if there is no node to remove.
  // The min-heap condition must be retained.
  // Set h->root_node to NULL if the last node is removed.
  // Make sure that no memory leak occurs.
  if(h->root_node == NULL) {
    return HEAP_EMPTY;
  }else{
    node *tmp = h->root_node;
    int priority = tmp->priority;    
    h->root_node = tmp->left;
    return priority;
  }
 
}

struct _node_* newNode(int priority){

    node* temp = (node*)malloc(sizeof(node));
    temp->priority = priority;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//bheap_insert(&h, 5, NULL);
void bheap_insert(bheap *h, int priority, void(*node_operation)()) {
  // TODO: Allocate a new node and insert it into the tree.
  // Make sure that the min-heap condition is retained.
  // Duplicate nodes are allowed (it should be possible to insert multiple nodes with the same priority).

  if(h->root_node == NULL){
    h->root_node = newNode(priority);
  }else{
    node *position = h->root_node;
    node *position2 = NULL;
    int side = 0;
    int index = 0;
    while(position != NULL){      
      position2 = position;
      if(position->priority <= priority){
        if( position->left == NULL){   
          position = position->left;
          side = 1;        
        } else if(position->right == NULL) {
          position = position->right;
          side = 0;
        } else{
          if(index % 2 == 0){
            position = position->right;
          }else{
            position = position->left;
          }  
          index ++;
        }
      }else{

          node *tmp = newNode(position2->priority);
          position2->priority = priority;
          position2->left = tmp;
      }
    }
      if(side){
        position2->left = newNode(priority);
      }else{
        position2->right = newNode(priority);
      }

  }
      
}



void bheap_run_node_operation(bheap *h, int priority) {
  // TODO: Call the node_operation function pointer on a node with the given priority.
  // Do nothing if there does not exist a node with the given priority.
  // Do nothing if there exists such a node, but the node_operation field is set to NULL.
}


void h_destroy_help(node *root_node){
  if(root_node != NULL){
    h_destroy_help(root_node->left);
    h_destroy_help(root_node->right);
    free(root_node);
  }
}

void bheap_destroy(bheap *h) {
  // TODO: Free all nodes and set root_node to NULL.
  // Make sure that no memory leak occurs.
  node *position = h->root_node;
  h_destroy_help(position);
}


