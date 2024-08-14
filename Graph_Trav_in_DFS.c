// here we are using DFS using stack but, actually we are not implementing stack because recursive function in c are always works in stack.

#include <stdio.h>
#include <stdlib.h>

// Array to keep track of visited nodes during DFS traversal

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

// Adjacency matrix representing the graph
// Each element adjmatrixofgraph[i][j] = 1 indicates an edge between node i and node j

int adjmatrixofgraph[7][7] = 
{
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0}, 
    {0, 0, 0, 0, 1, 0, 0}
};

// Function to perform DFS traversal starting from a given node 'initial'

void DFS(int initial)
{
                                                                                // Print the current node (i.e., visiting the node)
    printf("%d ", initial);

                                                                                // Mark the current node as visited
    visited[initial] = 1;

    // Loop through all nodes to check adjacency with the current node

    for (int i = 0; i < 7; i++)
    {
                                                                                 // If there is an edge between the current node and node 'i'
                                                                                 // and node 'i' has not been visited yet
        if (adjmatrixofgraph[initial][i] == 1 && visited[i] == 0)
        {
                                                                                 // Recursively perform DFS on the adjacent node
            DFS(i);
        }
    }
}

// Main function

int main()
{
    // Start DFS traversal from node 2
    
    DFS(2);
    
    return 0;
}

