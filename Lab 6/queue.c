#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue{
    int *data;
    int size;
    int start;
    int end;
    int capacity;
} CircularQueue;

void create_CircularQueue(CircularQueue **p_CQ, int size)
{
    *p_CQ = (CircularQueue*)malloc(sizeof(CircularQueue));
    (*p_CQ)->size = size;
    (*p_CQ)->capacity = size;
    (*p_CQ)->start = -1;
    (*p_CQ)->end = -1;
    (*p_CQ)->data = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        (*p_CQ)->data[i] = NULL;
    }
}

void CQ_enqueue(CircularQueue *queue, int item)
{
    if ((queue->end+1 == queue->start)|| (queue->end == queue->size && queue->start == 0)){
        printf("Queue full\n");
    }
    else if (queue->start == -1){
        queue->start = 0;
        queue->end = 0;
        queue->data[queue->end] = item;
    }
    else if (queue->end == queue->size-1){
        queue->end = 0;
        queue->data[queue->end] = item;
    }
    else{
        queue->end = queue->end+1;
        queue->data[queue->end] = item;
    }
}

void CQ_dequeue(CircularQueue *queue){
    int ret_val;
    if (queue->start == -1){
        printf("Queue empty\n");
    }
    else if (queue->start == queue->end){
        ret_val = queue->data[queue->start];
        queue->start = -1;
        queue->end = -1;
    }
    else if (queue->start == queue->size-1){
        ret_val = queue->data[queue->start];
        queue->start = 0;
    }
    else{
        ret_val = queue->data[queue->start];
        queue->start = queue->start+1;
    }
}

void CQ_print(CircularQueue *queue){
    if (queue->start == -1){
        printf("Queue empty\n");
    }
    else if(queue->end >= queue->start){
        printf("Elements in queue: ");
        for(int i = queue->start; i<queue->end+1; i++){
            printf("%d", queue->data[i]);
        }
        printf("\n");
    }
    else{
        printf("Elements in queue: ");
        for(int i = queue->start; i<queue->size; i++){
            printf("%d ", queue->data[i]);
        }
        for (int i = 0; i<queue->end+1; i++){
            printf("%d ", queue->data[i]);
        }
        printf("\n");
    }
}

int main(){
    CircularQueue *CQ;
    create_CircularQueue(&CQ, 2);
    CQ_enqueue(CQ, 5);
    CQ_enqueue(CQ, 6);
    CQ_dequeue(CQ);
    CQ_enqueue(CQ, 7);
    CQ_print(CQ);
}

// SCALING CASE!!!!!!