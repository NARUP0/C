// Time complexity of serching in BST is depends upon hight of the tree(h),the best time complexity is O(log n) and worst time complexity is O(n).

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


// Function to search for a key in a Binary Search Tree (BST)
// Returns a pointer to the node containing the key if found, otherwise returns NUL
struct node * searchBST(struct node * root, int  key)
{
    // Base case: If the tree is empty or the key is not found, return NULL
    if(root==NULL)
    {
        return NULL ;
    }
    // If the current node's data matches the key, return the current node
    else if (root->data==key)
    {
        return root ;
    }
    // If the key is smaller than the current node's data,
    // search in the left subtree
    else if (root->data>key)
    {
        return searchBST(root->left, key) ;
    }
    // If the key is larger than the current node's data,
    // search in the right subtree
    else
    {
        return searchBST(root->right, key) ;
    }
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
    // Create BST three nodes
    struct node * p = createnode(5) ;
    struct node * p1 = createnode(3) ;
    struct node * p2 = createnode(7) ;
    struct node * p3 = createnode(1) ;
    struct node * p4 = createnode(4) ;

    // Link the nodes to form the BST tree
    p->left=p1 ;
    p->right=p2 ;
    p1->left=p3 ;
    p1->right=p4 ;

    // Finally The BST tree looks like this:
    //      5
    //     / \
    //    3   7
    //   / \
    //  1   4  

    struct node *  n = searchBST(p, 7);
    if (n!=NULL)
    {
        printf("found : %d\n", n->data);
    }
    else
    {
        printf("not found\n");    
    }
    
    



    // Free the memory of the entire tree
    freeTree(p) ;


    return 0;
}    