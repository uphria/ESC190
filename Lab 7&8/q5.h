#if !defined(q5)
#define q5

#include <stdlib.h>
#include <stdint.h>


typedef struct Heap{
    int *data;
    int size;
    int filled;
}Heap;

void create_heap(struct Heap **self, int size);
void insert_val(struct Heap *self, int val);
void extract_min(struct Heap *self);

#endif
