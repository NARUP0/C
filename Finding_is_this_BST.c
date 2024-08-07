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

int isBST(struct node * root)      
{
    // Static variable to keep track of the previous node in the inorder traversal
    static struct node * prev = NULL ;

    // If the current node is not NULL
    if(root!=NULL)
    {
        // Recursively check the left subtree
        if(!isBST(root->left))
        {
            return 0 ; // If the left subtree is not a BST, return 0 (false)
        }

        // Check if the current node's data is greater than the previous node's data
        else if (prev!=NULL && prev->data>=root->data)
        {
            return 0 ;// If not, return 0 (false) since the BST property is violated
        }

        // Update the previous node to the current node
        prev=root;

        // Recursively check the right subtree
        return isBST(root->right) ;
    }
    else
    {
        // If the current node is NULL, return 1 (true) since an empty tree is a BST
        return 1 ;
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

    //inorder(p);

    if(isBST)
    {
        printf("tree is BST.\n");
    }
    else
    {
        printf("tree is not BST.\n");
    }

    // Free the memory of the entire tree
    freeTree(p) ;


    return 0;
}    