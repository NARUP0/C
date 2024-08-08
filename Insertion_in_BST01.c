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

// function to print tree in inorder traversal
void inorder(struct node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

// Function to insert a node with a given key in a Binary Search Tree (BST)
void insertionBST(struct node * root, int key)
{
    struct node * prev , *ptr ;

    // Traverse the tree to find the correct insertion point
    while (root!=NULL)
    {
        prev=root ; // Keep track of the previous node

        // If the key already exists in the BST, print an error message and return
        if(root->data==key)
        {
            printf("cannot enter %d in the BST, it already exist\n",key);
            return ;
        }

        // If the key is smaller, move to the left subtree
        else if(root->data>key)
        {
            root=root->left;
        }

        // If the key is larger, move to the right subtree
        else
        {
            root=root->right;
        }
    }

    // Create a new node for the key
    ptr = createnode(key);

     // Attach the new node to the appropriate position in the tree
    if (prev->data>key)
    {
        prev->left=ptr;// Insert as the left child
    }
    else
    {
        prev->right=ptr;// Insert as the right child
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
    // Create three nodes
    struct node * p = createnode(10) ;
    struct node * p1 = createnode(5) ;
    struct node * p2 = createnode(17) ;
    struct node * p3 = createnode(1) ;
    struct node * p4 = createnode(7) ;

    // Link the nodes to form the tree
    p->left=p1 ;
    p->right=p2 ;
    p1->left=p3 ;
    p1->right=p4 ;

    // Finally The tree looks like this:
    //      10
    //     / \
    //    5   17
    //   / \
    //  1   7  

    insertionBST(p, 6);
    inorder(p);

    // Free the memory of the entire tree
    freeTree(p) ;


    return 0;
}    