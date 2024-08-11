#include<stdio.h>
#include<stdlib.h>

// Define the structure for the Node of an AVL tree
struct Node
{
    struct Node *left;  // Pointer to the left child
    int data;           // Data value of the node
    int height;         // Height of the node for balancing purposes
    struct Node *right; // Pointer to the right child
};

// Function to get the height of a node
int getheight(struct Node *node)
{
    if (node == NULL)
    {
        return 0; // If the node is NULL, return height as 0
    }
    else
    {
        return node->height; // Otherwise, return the node's height
    }
}

// Function to get the maximum of two integers
int max(int a, int b)
{
    return a > b ? a : b; // Return the greater of the two values
}

// Function to calculate the balance factor of a node
int getbalancefactor(struct Node *node)
{
    if (node == NULL)
    {
        return 0; // If the node is NULL, return balance factor as 0
    }
    else
    {
        // Return the difference between the heights of the right and left subtrees
        return getheight(node->right) - getheight(node->left);
    }
}

// Function to create a new node with the given data
struct Node *createnode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node
    ptr->data = data;       // Set the data of the node
    ptr->left = NULL;       // Initialize the left child to NULL
    ptr->right = NULL;      // Initialize the right child to NULL
    ptr->height = 1;        // Set the height of the new node to 1 (leaf node)
    return ptr;             // Return the created node
}

// Function to perform right rotation
struct Node *rightrotation(struct Node *y)
{
    struct Node *x = y->left;     // Store the left child of the current node
    struct Node *t2 = x->right;   // Store the right child of the left child

    x->right = y;     // Perform rotation: make current node the right child of its left child
    y->left = t2;     // Set the right child of the left child as the left child of the current node

    // Update the heights of the nodes after rotation
    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return x; // Return the new root after rotation
}

// Function to perform left rotation
struct Node *leftrotation(struct Node *x)
{
    struct Node *y = x->right;    // Store the right child of the current node
    struct Node *t2 = y->left;    // Store the left child of the right child

    y->left = x;      // Perform rotation: make current node the left child of its right child
    x->right = t2;    // Set the left child of the right child as the right child of the current node

    // Update the heights of the nodes after rotation
    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return y; // Return the new root after rotation
}

// Function to insert a new node with a given key into the AVL tree
struct Node *insertion(struct Node *node, int key)
{
    // Perform standard BST insertion
    if (node == NULL)
    {
        return createnode(key); // If the node is NULL, create a new node
    }
    else if (key < node->data)
    {
        node->left = insertion(node->left, key); // Recur for the left subtree
    }
    else if (key > node->data)
    {
        node->right = insertion(node->right, key); // Recur for the right subtree
    }
    else
    {
        printf("the element %d is already present\n", key); // If the key is already present, return the node
        return node;
    }

    // Update the height of the current node
    node->height = 1 + max(getheight(node->left), getheight(node->right));

    // Get the balance factor of the current node
    int bf = getbalancefactor(node);

    // Perform rotations based on the balance factor
    if (bf < -1 && key < node->left->data) // Left Left Case
    {
        return rightrotation(node);
    }
    else if (bf > 1 && key > node->right->data) // Right Right Case
    {
        return leftrotation(node);
    }
    else if (bf < -1 && key > node->left->data) // Left Right Case
    {
        node->left = leftrotation(node->left);
        return rightrotation(node);
    }
    else if (bf > 1 && key < node->right->data) // Right Left Case
    {
        node->right = rightrotation(node->right);
        return leftrotation(node);
    }
    else
    {
        return node; // Return the node if no rotation is required
    }
}

// Function to perform a pre-order traversal of the tree
void preorder(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data); // Print the data of the node
        preorder(node->left);      // Recur for the left subtree
        preorder(node->right);     // Recur for the right subtree
    }
}

// Function to free the memory allocated for the tree
void freetree(struct Node *node)
{
    if (node != NULL)
    {
        freetree(node->left);   // Recur for the left subtree
        freetree(node->right);  // Recur for the right subtree
        free(node);             // Free the current node
    }
}

int main()
{
    struct Node *p = NULL; // Initialize the root of the AVL tree as NULL

    // Insert elements into the AVL tree
    p = insertion(p, 5);
    p = insertion(p, 6);
    p = insertion(p, 9);
    p = insertion(p, 2);
    p = insertion(p, 3);
    p = insertion(p, 3); // Attempt to insert a duplicate element

    // Perform a pre-order traversal of the AVL tree
    preorder(p);

    // Free the memory allocated for the tree
    freetree(p);

    return 0;
}
