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

struct node * insertionBST(struct node * root, int key)
{
    // Check if the tree is non-empty
    if(root!=NULL)
    {
        // Declare pointers to keep track of the current node, previous node, and the root
        struct node * prev , *ptr , *mainroot ;

        // Store the root in mainroot to return it later
        mainroot = root ;

        // Traverse the tree to find the correct position for the new key
        while (root!=NULL)
        {
            // Keep track of the previous node
            prev=root ;

            // If the key already exists, print a message and return the root
            if(root->data==key)
            {
                printf("cannot enter %d in the BST, it already exist\n",key);
                return mainroot ;
            }

            // Move to the left subtree if the key is smaller than the current node's data
            else if(root->data>key)
            {
                root=root->left;
            }

            // Move to the right subtree if the key is greater than the current node's data
            else
            {
                root=root->right;
            }
        }

        // Create a new node with the key
        ptr = createnode(key);

        // Attach the new node to the correct position in the tree
        if (prev->data>key)
        {
            prev->left=ptr;
        }
        else
        {
            prev->right=ptr;
        }

        // Return the original root of the tree
        return mainroot ;
    }
    else
    {
        // If the tree is empty, create a new node and return it as the root
        return createnode(key); ;
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
    struct node * p ;
    p=insertionBST(NULL, 6);
    p=insertionBST(p, 7);
    p=insertionBST(p, 2);
    p=insertionBST(p, 3);
    p=insertionBST(p, 10);
    p=insertionBST(p, 3);

        // Finally The tree looks like this:
    //        6
    //       / \
    //      2   7
    //     / \   \
    //   null 3  10

    inorder(p);

    // Free the memory of the entire tree
    freeTree(p) ;


    return 0;
}    