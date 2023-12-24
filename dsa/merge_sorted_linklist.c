#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *head1 = NULL;
struct node *head3 = NULL;
void add(struct node **p, int data1)
{
    struct node *temp = *p;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data1;
    
    if (*p == NULL)
    {
        *p = newnode;
        newnode->next = NULL;
    }
    else
    {
        // Update the temp pointer correctly
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}

void sort(struct node *p1, struct node *p2)
{
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            add(&head3, p1->data);
            p1 = p1->next;
        }
        else
        {
            add(&head3, p2->data);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        add(&head3, p1->data);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        add(&head3, p2->data);
        p2 = p2->next;
    }
}

int main()
{
    int n, n1, d;
    printf("enter the size of 1st linklist");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("enter the data");
        scanf("%d", &d);
        add(&head, d);
    }
    printf("enter the size of 2nd linklist");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("enter the data");
        scanf("%d", &d);
        add(&head1, d);
    }
    sort(head, head1);
    printf("sorted linklist is ");
        struct node *temp = head3;  // Introduce a temporary pointer
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
}
