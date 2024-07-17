#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                                             //creating structure for linked list.
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
        scanf("%d", &head->data);                             //function for taking input in linked list
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

print(struct node *frr)
{
    while (frr != NULL)
    {
        printf("The Element is : %d\n", frr->data);                 //printing linked list
        frr = frr->next;
    }
}

fre(struct node *frr)
{
    struct node *a = frr;
    while (frr != NULL)                           //freeing the allocate memory
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
    printf("Enter the no. of input : ");                            //taking no. of input
    scanf("%d", &n);
    frr = creation(n);
    print(frr);
    fre(frr);
}
