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

// Function to find the in-order predecessor of a node
struct node * inorderpredecessor(struct node *root)
{
    root=root->left;// Move to the left child of the current node
    // Find the rightmost node in the left subtree
    while(root->right!=NULL)                                                             //Inorder Predecessor of any node is his left subtrees rigt most node.
    {                                                                                    //Inorder Successor of any node is his rigt subtrees left most node.
        root=root->right ;
    }
    return root ;// Return the in-order predecessor
}

// Function to delete a node from the BST
struct node * deletionBST(struct node * root, int key )
{
    if (root == NULL)    
    {
        return NULL ; // Base case: If the root is NULL, return NULL
    }

    // Recur down the tree to find the node to be deleted
    else if (key<root->data)
    {
        root->left = deletionBST(root->left, key); // Recur on the left subtree
    }
    else if (key>root->data)
    {
        root->right = deletionBST(root->right, key); // Recur on the right subtree
    }
    else // Node to be deleted is found
    {

        // Case 1: Node has no left child
        if (root->left==NULL)
        {
            struct node * temp = root->right; // Store the right child
            free(root); // Free the current node
            return temp ; // Return the right child
        }                                                             //case 1 and 2 also handele if the the both childs are null.

        // Case 2: Node has no right child
        else if (root->right==NULL)
        {
            struct node * temp = root->left; // Store the left child
            free(root); // Free the current node
            return temp ; // Return the left child
        }

        // Case 3: Node has two children
        else
        {
            // Find the in-order predecessor (maximum value in the left subtree)
            struct node * inorderprev = inorderpredecessor(root);
            root->data = inorderprev->data;// Replace the node's data with the predecessor's data
            // Delete the in-order predecessor
            root->left = deletionBST(root->left, inorderprev->data);
            return root ; // Return the root node
        }
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

    inorder(p);
    deletionBST(p, 5);
    printf("\n");
    inorder(p);

    // Free the memory of the entire tree
    freeTree(p) ;


    return 0;
}    