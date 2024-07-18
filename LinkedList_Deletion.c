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

// struct node * deletionAtFirst(struct node * head , int *n)
// {
//     struct node * ptr = head;
//     head = head->next;                                                       //deletion at 0 index          O(1)
//     free(ptr);
//     --(*n);
//     return head;
// }

// int deletionAtIndex(struct node * head , int index , int n)
// {
//     struct node * q =head, *p;
//     for (int i = 0; i < index; i++)
//     {
//         p=q;                                                                 //deletion at index except 0
//         q=q->next;
//     }
//     p->next=q->next;
//     free(q);
//     return --n;
// }

// int deletionAtLast(struct node * head , int n)
// {
//     struct node * q =head, *p;
//     while(q->next!=NULL)
//     {
//         p=q;                                                          //deletion of last index element
//         q=q->next;
//     }
//     p->next=q->next;
//     free(q);
//     return --n;
// }

// int deletionAtValue(struct node *head, int n, int value)
// {
//     struct node *q = head, *p;
//     while (q->data != value && q->next != NULL)
//     {
//         p = q;
//         q = q->next;                                                   //deletion of first occur value
//     }
//     if (q->data == value)
//     {
//         p->next = q->next;
//         free(q);
//         return --n;
//     }
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
    // frr = deletionAtFirst(frr , &n);
    // n=deletionAtIndex(frr , 2 , n);         //use one function at time
    // n=deletionAtLast(frr , n);
    // n = deletionAtValue(frr, n, 2);
    print(frr);
    fre(frr);
}
