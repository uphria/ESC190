#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
} node;


typedef struct LL{
    node *head;
    int size;
} LL;


void create_node(node **p_n, int data)
{
    *p_n = (node*)malloc(sizeof(node));
    (*p_n)->next = NULL;
    (*p_n)->data = data;
}

// created a linked list that looks like data[0]->data[1]->data[2]->...->data[size-1]
void create_LL_from_data(LL **p_LL, int *data_arr, int size)
{
    (*p_LL) = (LL*)malloc(sizeof(LL));
    (*p_LL)->size = 0;
    node *cur = NULL;
    for(int i = 0; i < size; i++){
        node *n;
        create_node(&n, data_arr[i]); // n is a pointer to a node with data = data[i], next = NULL
        if(cur == NULL){
            (*p_LL)->head = n;
        }
        else{
            cur->next = n;
        }
        cur = n;
        (*p_LL)->size++;
    }
}


void LL_append(LL *my_list, int new_elem)
{
    node *cur = my_list->head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    node *n;
    create_node(&n, new_elem);
    cur->next = n;
    my_list->size++;
}

void LL_insert(LL *my_list, int new_elem, int index)
{
    // TODO
    // Insert new_elem at index index in linked list my_list
    node *cur = my_list->head;
    for(int i = 0; i < index - 1; i++)
        cur = cur->next;
    node *n;
    create_node(&n, new_elem);
    n->next = cur->next;
    cur->next = n;
    my_list->size++;
}

void LL_delete(LL *my_list, int index)
{
    // TODO
    // Delete element at index index in linked list my_list
    if (index == 0){
        node *temp = my_list->head;
        my_list->head = my_list->head->next;
        free(temp);
        my_list->size--;
        return;
    }
    node *cur = my_list->head;
    for(int i = 0; i < index - 1; i++)
        cur = cur->next;
    node *temp = cur->next;
    cur->next = (cur->next)->next;
    free(temp);
    my_list->size--;
}

void LL_free_all(LL *my_list)
{
    // TODO
    // Free all memory allocated for linked list my_list,
    // including all the nodes
    node *cur = my_list->head;
    while(cur != NULL){
        node *temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(my_list);
}

int LL_get_rec_helper(node *node, int index){
    if (index == 0)
        return node->data;
    return LL_get_rec_helper(node->next, index-1);
}

int LL_get_rec(LL *my_list, int index)
{
    // TODO
    // Return the element at index index in linked list my_list
    // Use recursion. you must not use for, while, or do-while loops
    // You should use a helper function
    node *cur = my_list->head;
    return LL_get_rec_helper(cur, index);
}

int LL_get(LL *my_list, int index){
    node *cur = my_list->head;
    for(int i = 0; i<index; i++){
        cur = cur->next;
        if(cur == NULL){
            fprintf(stderr, "Index out of bounds\n");
            exit(1);
        }
    }
}

typedef struct ArrayList{
    int *data;
    int size;
    int capacity;
} ArrayList;

void create_AL_from_data(ArrayList **p_AL, int *data_arr, int size)
{
    // TODO
    *p_AL = (ArrayList*)malloc(sizeof(ArrayList));
    (*p_AL)->size = size;
    (*p_AL)->capacity = size;
    (*p_AL)->data = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        (*p_AL)->data[i] = data_arr[i];
    }
}

void AL_append(ArrayList *my_list, int new_elem)
{
    // TODO
    if (my_list->size == my_list->capacity){
        my_list->capacity *= 3;
        my_list->data = (int*)realloc(my_list->data, sizeof(int)*my_list->capacity);
    }

    my_list->data[my_list->size] = new_elem;
    my_list->size++;
}

void AL_insert(ArrayList *my_list, int new_elem, int index)
{
    // TODO
    if (my_list->size == my_list->capacity){
        my_list->capacity *= 2;
        my_list->data = (int*)realloc(my_list->data, sizeof(int)*my_list->capacity);
    }
    memmove(my_list->data+index+1, my_list->data+index, sizeof(int)*(my_list->size-index));
    my_list->data[index] = new_elem;
    my_list->size++;
}

void AL_delete(ArrayList *my_list, int index)
{
    // TODO
    memmove(my_list->data+index, my_list->data+index+1, sizeof(int)*(my_list->size-index-1));
    //my_list->data[my_list->size] = '\0';
    my_list->size--;
}

void AL_free(ArrayList *my_list)
{
    // TODO
    free(my_list->data);
    free(my_list);
}


int main()
{
    int data_arr[] = {1, 2, 3, 4, 5};
    LL *my_list;
    create_LL_from_data(&my_list, data_arr, 5);
    LL_append(my_list, 6);
    node *cur = my_list->head;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    return 0;
}