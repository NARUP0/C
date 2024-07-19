#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; // creating structure for circular linked list.
    struct node *next;
};

struct node *creation(int n)
{
    struct node *head, *p, *temp;

    head = (struct node *)malloc(sizeof(struct node));
    p = head;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth Element : ", i + 1);
        scanf("%d", &p->data); // function for taking input in circular linked list
        if (i == n - 1)
        {
            p->next = head;
        }
        else
        {
            temp = (struct node *)malloc(sizeof(struct node));
            p->next = temp;
            p = temp;
        }
    }
    return (head);
}

void print(struct node *head)
{
    struct node *p = head;
    while (p->next != head)
    {
        printf("The Element is : %d\n", p->data); // printing circular linked list
        p = p->next;
    }
    printf("The Element is : %d\n", p->data);
}

void fre(struct node *head)
{
    struct node *a = head, *temp;
    while (a->next != head) // freeing the allocate memory
    {
        temp = a;
        a = a->next;
        free(temp);
    }
    free(a);
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
