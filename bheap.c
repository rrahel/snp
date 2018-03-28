#include <stdlib.h>
#include <assert.h>
#include "bheap.h"
#include <stdio.h>
#include <string.h>
#include <memory.h>

int size = 0;

int getLeftChildIndex( int parentIndex ){ return 2 * parentIndex + 1; }

int getRightChildIndex( int parentIndex ){ return 2 * parentIndex + 2; }

int getParentIndex( int childIndex ){ return (childIndex - 1) / 2; }

int hasLeftChild( int index ){ return getLeftChildIndex(index) < size; }

int hasRightChild( int index ){ return getRightChildIndex(index) < size; }

int hasParent( int index ){ return getParentIndex(index) >= 0; }

int leftChild( int index ){ return heap_array[getLeftChildIndex(index)]; }

int rightChild( int index ){ return heap_array[getRightChildIndex(index)]; }

int parent( int index ){ return heap_array[getParentIndex(index)]; }

void swap( int indexOne, int indexTwo ){
  int temp = heap_array[indexOne];
  heap_array[indexOne] = heap_array[indexTwo];
  heap_array[indexTwo] = temp;
}

void heapifyDown(){
  int index = 0;
  while(hasLeftChild(index) == 1){    
    int smallerChildIndex = getLeftChildIndex(index);

    if(hasRightChild(index) == 1 && rightChild(index) < leftChild(index)) {
      smallerChildIndex = getRightChildIndex(index);
    }

    if(heap_array[index] < heap_array[smallerChildIndex]){
      break;
    }else{
      swap(index, smallerChildIndex);
    }

    index = smallerChildIndex;
  }
}

void heapifyUp(){  
  int index = size - 1;
  while( hasParent(index) == 1 && parent(index) > heap_array[index] ) {
    swap(getParentIndex(index), index);
    index = getParentIndex(index);
  }
}

void bheap_init(bheap *h) {
  h->root_node = NULL;
}

int bheap_remove_min(bheap *h) {
  if(size == 0){
    return HEAP_EMPTY;
  }else{
    int min_item = heap_array[0];
    heap_array[0] = heap_array[size - 1];
    size --;
    heapifyDown();
    return min_item;
  }
}

void bheap_insert(bheap *h, int priority, void(*node_operation)()) {
    heap_array[size] = priority;
    size++;
    heapifyUp();
}

void bheap_run_node_operation(bheap *h, int priority) {
  // TODO: Call the node_operation function pointer on a node with the given priority.
  // Do nothing if there does not exist a node with the given priority.
  // Do nothing if there exists such a node, but the node_operation field is set to NULL.
}


void bheap_destroy(bheap *h) {
  // TODO: Free all nodes and set root_node to NULL.
  // Make sure that no memory leak occurs.
  free(h);
  h->root_node = NULL;
}

void print_array(){
  printf("\n");
 for(int i = 0; i < size; i++) {     
    printf("%d | ", heap_array[i]);  
  } 
  printf("\n");
}
