#include <stdlib.h>
#include <stdio.h>

typedef struct Con{
    double weight;
    struct Node *node;
} Con;


typedef struct Node {
    int data;
    int num_cons;
    struct Con **connections;
    double dist_from_start;

} Node;



void create_node(int data, Node **p_node) {
    *p_node = malloc(sizeof(Node));
    (*p_node)->data = data;
    (*p_node)->connections = (void *)0;
    (*p_node)->num_cons = 0;
    (*p_node)->dist_from_start = 10000000.0;
}

void add_neighbour(Node *node, Node *neighbour, double weight) {
    node->num_cons++;
    node->connections = realloc(node->connections, node->num_cons * sizeof(Con *));
    node->connections[node->num_cons - 1] = malloc(sizeof(Con));
    node->connections[node->num_cons - 1]->weight = weight;
    node->connections[node->num_cons - 1]->node = neighbour;
}


void add_to_visited(Node ***p_visited, int *p_n_visited, Node *node) { // CHANGED
    Node **visited = *p_visited; // ADDED

    for(int i = 0; i < *p_n_visited; i++) {
        if (visited[i] == node) {
            return;
        }
    }
    (*p_n_visited)++; // CHECK THIS
    visited = realloc(visited, *p_n_visited * sizeof(Node *));
    visited[*p_n_visited - 1] = node;

    *p_visited = visited; // ADDED
}

int was_visited(Node **visited, int n_visited, Node *node) {
    // Complete this function
    int i = 0;
    while (i < n_visited){
        if(visited[i] == node){
            return 1;
        }
        i++;
    }
    
    return 0;
}


void dijkstra(Node *start, Node *end) {
    Node **visited = (void *)0;
    int num_visited = 0;
    Node *current = start;
    add_to_visited(&visited, &num_visited, current); // CHANGED
    start->dist_from_start = 0;             // change this
    

    while (current != end) {
        double min_dist = 1000000000.0;
        Node *min_node = (void *)0;
        for(int i = 0; i < num_visited; i++){
            Node *s = visited[i];
            for(int j = 0; j < s->num_cons; j++) {
                // complete this code
                if(was_visited(visited, num_visited, (s->connections)[j]->node) == 0){
                    if(min_dist > s->dist_from_start+(s->connections)[j]->weight){
                        min_dist = s->dist_from_start + (s->connections)[j]->weight;
                        min_node = (s->connections)[j]->node;
                    }
                }
            }

        }
        current = min_node;
        current->dist_from_start = min_dist;
        add_to_visited(&visited, &num_visited, current); // CHANGED
    }
}

int main(void){
    Node *A;
    Node *B;
    Node *C;
    Node *D;

    create_node('A', &A);
    create_node('B', &B);
    create_node('C', &C);
    create_node('D', &D);

    add_neighbour(A, B, 5);
    add_neighbour(A, C, 1);
    add_neighbour(A, D, 3);
    add_neighbour(B, D, 8);
    add_neighbour(C, D, 1);

    dijkstra(A, D);
    printf("%f", D->dist_from_start);
    return 0;
}