#include <stdlib.h>
#include <assert.h>
#include "bheap.h"
#include <stdio.h>

int main() {
  // TODO: Test your implementation here
  bheap h;
  bheap_init(&h);
  // bheap_insert(&h, 1, NULL);
  // bheap_insert(&h, 5, NULL);
  
  // assert(bheap_remove_min(&h) == 1);
  // assert(bheap_remove_min(&h) == 5);
  // bheap_destroy(&h);


  bheap_insert(&h, 10, NULL);
  bheap_insert(&h, 15, NULL);
  bheap_insert(&h, 20, NULL);
  bheap_insert(&h, 17, NULL);
  bheap_insert(&h, 8, NULL);
  print_array();
  // output -> 10|15|20|17|

  bheap_remove_min(&h);
  print_array();
  //output -> 10|15|20|17

  bheap_remove_min(&h);
  print_array();
  //output -> 15|20|17

  bheap_insert(&h, 16, NULL);
  print_array();

  return 0;
}
