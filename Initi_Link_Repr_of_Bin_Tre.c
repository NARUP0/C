#include<stdio.h>
#include<stdlib.h>

// Define a structure for a binary tree node
struct node 
{
    struct node * left ;
    int data ;
    struct node * right ;

};

// Function to create a new node
struct node * createnode(int data)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));

    n->data = data ; // Initialize data
    n->left = NULL ; // Initialize left child
    n->right = NULL ; // Initialize right child

    return n ; // Return the created node
}

// Function to free the memory of the entire tree
void freeTree(struct node* root) 
{
    if (root == NULL)
    {
        return ;
    }
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    // Create three nodes
    struct node * p = createnode(2) ;
    struct node * p1 = createnode(1) ;
    struct node * p2 = createnode(4) ;

    // Link the nodes to form the tree
    p->left=p1 ;
    p->right=p2 ;

    // Free the memory of the entire tree
    freeTree(p) ;


    return 0;
}
