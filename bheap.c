#include <stdlib.h>
#include <assert.h>
#include "bheap.h"
#include <stdio.h>
#include <string.h>
#include <memory.h>

void display(bheap *h){
  // printf("%d\n",&h->root_node->priority);
  // node *temp = NULL;
  // temp = (node*) malloc(sizeof(node));
  // h->root_node = (node*) malloc(sizeof(node));
  // h->root_node = temp;

    // printf("%d", h->root_node->priority);
    // if(root_node != NULL){
    //     printf(" %d \n", root_node->priority);
    //     display(root_node->left);
    //     display(root_node->right);
    // }
}

void bheap_init(bheap *h) {
  h->root_node = NULL;
}


int bheap_remove_min(bheap *h) {
  // TODO: Remove a node with minimal priority (the root node).
  // Return the priority of the removed node, or return HEAP_EMPTY if there is no node to remove.
  // The min-heap condition must be retained.
  // Set h->root_node to NULL if the last node is removed.
  // Make sure that no memory leak occurs.
  return HEAP_EMPTY;
}


//bheap_insert(&h, 5, NULL);
void bheap_insert(bheap *h, int priority, void(*node_operation)()) {
  // TODO: Allocate a new node and insert it into the tree.
  // Make sure that the min-heap condition is retained.
  // Duplicate nodes are allowed (it should be possible to insert multiple nodes with the same priority).

  // node *temp = NULL;
  // temp = (node*) malloc(sizeof(node));
  // node *temp_2 = NULL;
  // temp_2 = (node*) malloc(sizeof(node));
  
  // if(!h->root_node){
  //   temp->left = NULL;
  //   temp->right = NULL;
  //   temp->priority = priority;
  //   h->root_node = (node*) malloc(sizeof(node));
  //   h->root_node = temp;
  //   // printf("+++++root empty");
  //   return;
  // }else if(priority < 3){
  //   h->root_node = (node*) malloc(sizeof(node));
  //   h->root_node->right = temp;
  //   // printf("+++++low priority");
  //   return;
  // }else if(priority > 3) {
  //   h->root_node = (node*) malloc(sizeof(node));
  //   temp_2 = h->root_node;
  //   h->root_node = temp;
  //   h->root_node->right = temp_2;
  //   // printf("+++++high priority");
  //   return;

    node *tmp = (node *)malloc(sizeof(node));
    tmp->priority = priority;
    tmp->right = NULL;
    tmp->left = NULL;

    if(h->root_node == NULL){
        h->root_node = tmp;
        printf("test: %d", h->root_node->priority);
    }else{
        if(priority > (h->root_node)->priority){
            if((h->root_node)->left == NULL){
                bheap_insert((h->root_node)->left, priority, NULL);
            }else{
                bheap_insert((h->root_node)->right, priority, NULL);
            }
        }
        // }else if(priority <= (h->root_node)->priority){
            
        //     printf("h->root_node ---> %d \n", (h->root_node)->priority);
        //     printf("priority ---> %d \n", tmp->priority);

        //     tmp->priority = (h->root_node)->priority;
        //     (h->root_node)->priority = priority;
        //     bheap_insert((h->root_node), tmp->priority, NULL);
        // }
    }

}


void bheap_run_node_operation(bheap *h, int priority) {
  // TODO: Call the node_operation function pointer on a node with the given priority.
  // Do nothing if there does not exist a node with the given priority.
  // Do nothing if there exists such a node, but the node_operation field is set to NULL.
}


void bheap_destroy(bheap *h) {
  // TODO: Free all nodes and set root_node to NULL.
  // Make sure that no memory leak occurs.
}
