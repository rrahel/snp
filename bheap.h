#pragma once

#define HEAP_EMPTY -1
#define ARRAY_SIZE 100

int heap_array[ARRAY_SIZE];
int size;

typedef struct _node_ {
    int priority;
    struct _node_ *left;
    struct _node_ *right;
    void(*node_operation)();
} node;

typedef struct _bheap_ {
    node *root_node;
} bheap;

void bheap_init(bheap *h);

int bheap_remove_min(bheap *h);

void bheap_insert(bheap *h, int priority, void(*node_operation)());

void bheap_run_node_operation(bheap *h, int priority);

void bheap_destroy(bheap *h);

void recursive_insert(node *current_node, int priority);

void print_array();

int getLeftChildIndex(int parentIndex);

int getRightChildIndex(int parentIndex);

int getParentIndex(int childIndex);

int hasLeftChild(int index);

int hasRightChild(int index);

int hasParent(int index);

int leftChild(int index);

int rightChild(int index);

int parent(int index);

void swap(int indexOne, int indexTwo);

void checkArraySize();

void heapifyUp();

void heapifyDown();