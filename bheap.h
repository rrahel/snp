#pragma once

#define HEAP_EMPTY -1

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

struct _node_* newNode(int data);

void h_destroy_help(node *root_node);