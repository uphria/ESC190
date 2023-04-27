#include <stdio.h>
#include <stdlib.h>
#include "q5.h"

void create_heap(struct Heap **self, int size){
    *self = (Heap*)malloc(sizeof(Heap));
    (*self)->size = size;
    (*self)->filled = 0;
    (*self)->data = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        (*self)->data[i] = NULL;
    }
}

void insert_val(struct Heap *self, int val){
    if (self->filled == self->size){
        self->size *= 2;
        self->data = (int*)realloc(self->data, sizeof(int) * self->size);
    }
    self->data[self->filled+1] = val;
    self->filled = self->filled + 1;
    heapify_up(&self);
}

int get_left_child_index(int parent_index){
    return 2*parent_index;
}

int get_right_child_index(int parent_index){
    return 2*parent_index+1;
}

int get_parent_index(int child_index){
    return child_index/2;
}

void swap(struct Heap *self, int index1, int index2){
    int temp = self->data[index1];
    self->data[index1] = self->data[index2];
    self->data[index2] = temp;
}

int has_left_child(struct Heap *self, int index){
    return get_left_child_index(index) <= self->filled;
}

int has_right_child(struct Heap *self, int index){
    return get_right_child_index(index) <= self->filled;
}

int has_parent(int index){
    return get_parent_index(index) >= 1;
}

int left_child(struct Heap *self, int index){
    return self->data[get_left_child_index(index)];
}

int right_child(struct Heap *self, int index){
    return self->data[get_right_child_index(index)];
}

int parent(struct Heap *self, int index){
    return self->data[get_parent_index(index)];
}

void heapify_up(struct Heap *self){
    int index = self->filled;
    while (has_parent(index) && (parent(self, index) > self->data[index])){
        swap(self, get_parent_index(index), index);
        index = get_parent_index(index);
    }
}

void heapify_down(struct Heap *self){
    int index = 1;
    while (has_left_child(self, index)){
        int smaller_child_index = get_left_child_index(index);
        if (has_right_child(self, index) && (right_child(self, index) < left_child(self, index))){
            smaller_child_index = get_right_child_index(index);
        }
        if (self->data[index] < self->data[smaller_child_index]){
            break;
        }
        else{
            swap(self, index, smaller_child_index);
        }
        index = smaller_child_index;
    }
}

void extract_min(struct Heap *self){
    if (self->filled == 0){
        return NULL;
    }
    int min_val = self->data[1];
    self->data[1] = self->data[self->filled];
    self->filled -= 1;
    heapify_down(self);
    return min_val;
}

void extract_max(struct Heap *self){
    if (self->filled == 0){
        return NULL;
    }
}