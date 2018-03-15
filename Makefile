	CFLAGS += -Wall -Werror -O0 -g3 -std=c99 -fsanitize=address

.PHONY: binary_heap clean

all: binary_heap

binary_heap:
	gcc $(CFLAGS) -o binary_heap.out bheap.c main.c

clean:
	rm -f *.out
