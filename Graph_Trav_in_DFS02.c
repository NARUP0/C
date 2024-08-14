// here the no. of vertices must be > the value of the vertices in graph.

#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the adjacency list

struct Node {
    int data;                                                             // Store the data of the node (i.e., vertex)
    struct Node* next;                                                    // Pointer to the next node in the adjacency list
};

// Define the structure for the graph

struct Graph {
    int numvertices;                                                     // Number of vertices in the graph
    int* visitarray;                                                     // Array to keep track of visited vertices
    struct Node** adjlist;                                               // Array of pointers to adjacency lists (each list represents neighbors of a vertex)
};

// Define the structure for the stack used in DFS

struct Stack {
    int maxsize;                                                         // Maximum size of the stack (number of vertices in the graph)
    struct Node* head;                                                    // Pointer to the top node of the stack
};

// Function to create a new node in the adjacency list

struct Node* createnode(int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;                                                      // Assign data to the node
    ptr->next = NULL;                                                      // Initialize the next pointer to NULL
    return ptr;                                                             // Return the newly created node
}

// Function to check if the stack is empty

int isEmpty(struct Stack* stack) {
    return (stack->head == NULL);                                         // Return 1 (true) if the stack is empty, otherwise 0 (false)
}

// Function to check if memory is full (not related to stack size, but to memory availability)

int isFull() {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {                                                     // If memory allocation fails, memory is full
        return 1;                                                        // Return 1 (true) indicating memory is full
    }
    free(n);                                                             // Free the allocated memory if successful
    return 0;                                                            // Return 0 (false) indicating memory is not full
}

// Function to push an element onto the stack

void push(struct Stack* stack, int data) {
    if (isFull()) {                                                       // Check if memory is full before pushing
        printf("Stack Overflow\n");
    } else {
        struct Node* n = createnode(data);                                // Create a new node with the given data
        n->next = stack->head;                                            // Point the new node to the current top node of the stack
        stack->head = n;                                                  // Update the top pointer to the new node
    }
}

// Function to pop an element from the stack

int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {                                                 // Check if the stack is not empty before popping
        struct Node* ptr = stack->head;                                    // Pointer to the top node of the stack
        stack->head = stack->head->next;                                   // Update the top pointer to the next node
        int val = ptr->data;                                               // Store the data of the top node
        free(ptr);                                                         // Free the memory of the popped node
        return val;                                                        // Return the data of the popped node
    } else {
        printf("Stack Underflow\n");
        return -1;                                                         // Return -1 if the stack is empty
    }
}

// Function to create a graph with the given number of vertices

struct Graph* creategraph(int num) {
    struct Graph* ptr = (struct Graph*)malloc(sizeof(struct Graph));
    ptr->numvertices = num;                                               // Initialize the number of vertices
    ptr->visitarray = (int*)malloc(num * sizeof(int));                    // Allocate memory for the visit array
    ptr->adjlist = (struct Node**)malloc(num * sizeof(struct Node*));     // Allocate memory for the adjacency list array

    // Initialize all vertices as not visited and all adjacency lists as empty

    for (int i = 0; i < num; i++) {
        ptr->visitarray[i] = 0;                                         // Set all vertices as not visited
        ptr->adjlist[i] = NULL;                                         // Initialize all adjacency lists as empty
    }
    
    return ptr;                                                         // Return the newly created graph
}

// Function to add an edge to the graph

void addedge(struct Graph* ptr, int source, int destination) {
    // Add an edge from source to destination

    struct Node* newnode = createnode(destination);
    newnode->next = ptr->adjlist[source];                                // Point the new node to the current list of source
    ptr->adjlist[source] = newnode;                                      // Update the source's adjacency list to include the new node

    // Add an edge from destination to source (since it's an undirected graph)

    newnode = createnode(source);
    newnode->next = ptr->adjlist[destination];                           // Point the new node to the current list of destination
    ptr->adjlist[destination] = newnode;                                 // Update the destination's adjacency list to include the new node
}

// Function to perform Depth-First Search (DFS) on the graph

void DFS(struct Graph* graph, int startvertex) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxsize = graph->numvertices;                               // Initialize the maximum size of the stack
    stack->head = NULL;                                                // Initialize the stack as empty

    push(stack, startvertex);                                           // Push the start vertex onto the stack
    graph->visitarray[startvertex] = 1;                                // Mark the start vertex as visited
    int vertex;

    // While there are vertices to process in the stack

    while (!isEmpty(stack)) {
        vertex = pop(stack);                                               // Pop a vertex from the stack
        printf("%d ", vertex);                                             // Print the popped vertex

        struct Node* n = graph->adjlist[vertex];                            // Get the adjacency list of the popped vertex

        // Traverse all adjacent vertices

        while (n != NULL) {
            if (graph->visitarray[n->data] == 0) {                          // If the adjacent vertex has not been visited
                graph->visitarray[n->data] = 1;                             // Mark it as visited
                push(stack, n->data);                                        // Push the adjacent vertex onto the stack
            }
            n = n->next;                                                      // Move to the next adjacent vertex
        }
    }
    free(stack);                                                              // Free the memory allocated for the stack
}

// Function to free the memory allocated for the graph

void freeGraph(struct Graph* graph) {

    // Loop through each vertex in the graph

    for (int i = 0; i < graph->numvertices; i++) {
        struct Node* temp = graph->adjlist[i];                                      // Get the head of the adjacency list for vertex i

        // Traverse the adjacency list for this vertex

        while (temp != NULL) {
            struct Node* next = temp->next;                                         // Store the next node in the list
            free(temp);                                                             // Free the current node
            temp = next;                                                             // Move to the next node
        }
    }

    // Free the memory allocated for the adjacency list array and the visit array

    free(graph->adjlist);
    free(graph->visitarray);

    // Free the memory allocated for the graph structure itself

    free(graph);
}

int main() {

    // Create a graph with 11 vertices (0 to 10)

    struct Graph* graph = creategraph(11);
    
    // Add edges to the graph

    addedge(graph, 0, 10);
    addedge(graph, 0, 7);
    addedge(graph, 0, 5);
    addedge(graph, 7, 5);
    addedge(graph, 7, 2);
    addedge(graph, 10, 5);
    addedge(graph, 2, 5);
    addedge(graph, 5, 1);
    addedge(graph, 1, 4);

    // Perform DFS starting from vertex 4

    DFS(graph, 4);

    // Free the memory allocated for the graph

    freeGraph(graph);

    return 0;
}
