#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; // creating structure for linked list.
    struct node *next;
};

struct node *creation(int n)
{
    struct node *head, *frr, *temp;

    head = (struct node *)malloc(sizeof(struct node));
    frr = head;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth Element : ", i + 1);
        scanf("%d", &head->data); // function for taking input in linked list
        if (i == n - 1)
        {
            head->next = NULL;
        }
        else
        {
            temp = (struct node *)malloc(sizeof(struct node));
            head->next = temp;
            head = temp;
        }
    }
    return (frr);
}

// struct node * insertionAtFirst(struct node * head , int data , int *n)
// {
//     struct node * ptr = (struct node *)malloc(sizeof(struct node));
//     ptr->data=data;
//     ptr->next=head;                                                             //insert at 0 index          O(1)
//     head=ptr;
//     ++(*n);
//     return head;
// }

// int insertionAtIndex(struct node * head , int data , int index , int n)
// {
//     for (int i = 0; i < index-1; i++)
//     {
//         head=head->next;
//     }
//     struct node * ptr = (struct node *)malloc(sizeof(struct node));                     //insert at any index except 0 and last      O(n)
//     ptr->data=data;
//     ptr->next=head->next;
//     head->next=ptr;
//     return ++n;
// }

// int insertionAtLast(struct node * head , int data , int n)
// {
//     while(head->next!=NULL)
//     {
//         head=head->next;
//     }
//     struct node * ptr = (struct node *)malloc(sizeof(struct node));                      //insert at last index                    O(n)
//     ptr->data=data;
//     ptr->next=NULL;
//     head->next=ptr;
//     return ++n;
// }

// int insertionAfterNode(struct node * prenode, int data , int n)
// {
//     struct node * ptr = (struct node *)malloc(sizeof(struct node));
//     ptr->data=data;                                                                      //insert  after any node if you have addres of prenode    O(1)
//     ptr->next=prenode->next;
//     prenode->next=ptr;
//     return ++n;
// }

print(struct node *frr)
{
    while (frr != NULL)
    {
        printf("The Element is : %d\n", frr->data); // printing linked list
        frr = frr->next;
    }
}

fre(struct node *frr)
{
    struct node *a = frr;
    while (frr != NULL) // freeing the allocate memory
    {
        a = frr->next;
        free(frr);
        frr = a;
    }
}

main()
{
    int n;
    struct node *frr;
    printf("Enter the no. of input : "); // taking no. of input
    scanf("%d", &n);
    frr = creation(n);
    // frr = insertionAtFirst(frr , 69 , &n);
    // n=insertionAtIndex(frr , 69 , 2 , n);         //use one function at time 
    // n=insertionAtLast(frr , 69 , n);
    // n=insertionAfterNode(frr ,69 , n);
    print(frr);
    fre(frr);
}
