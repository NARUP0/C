#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; // creating structure for doubaly linked list.
    struct node *next, *prev;
};

struct node *creation(int n)
{
    struct node *head, *p, *temp;

    head = (struct node *)malloc(sizeof(struct node));
    p = head;
    head->prev = NULL;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth Element : ", i + 1);
        scanf("%d", &p->data); // function for taking input in doubaly linked list
        if (i == n - 1)
        {
            p->next = NULL;
        }
        else
        {
            temp = (struct node *)malloc(sizeof(struct node));
            p->next = temp;
            temp->prev = p;
            p = temp;
        }
    }
    return (head);
}

void print(struct node *head)
{
    struct node *p = head , *q;
    printf("\nprinting left to right\n\n");
    while (p != NULL)
    {
        printf("The Element is : %d\n", p->data); // printing doubaly linked list
        q=p;
        p = p->next;
    }
    printf("\nprinting right to left\n\n");
    while (q->prev != NULL)
    {
        printf("The Element is : %d\n", q->data); // printing doubaly linked list
        q = q->prev;
    }
    printf("The Element is : %d\n", q->data);
}

void fre(struct node *head)
{
    struct node *a = head, *temp;
    while (a != NULL) // freeing the allocate memory
    {
        temp = a;
        a = a->next;
        free(temp);
    }
}

int main()
{
    struct node *head;
    int n;
    printf("Enter the no. of element : ");
    scanf("%d", &n);
    if (n != 0)
    {
        head = creation(n);
        print(head);
        fre(head);
    }
    return 0;
}
