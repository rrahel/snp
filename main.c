#include <stdlib.h>
#include <assert.h>
#include "bheap.h"
#include <stdio.h>

int main() {
  // TODO: Test your implementation here
  bheap h;
  bheap_init(&h);
  bheap_insert(&h, 5, NULL);
  bheap_insert(&h, 1, NULL);
  
  assert(bheap_remove_min(&h) == 1);
  assert(bheap_remove_min(&h) == 5);
  bheap_destroy(&h);
  
  return 0;
}
