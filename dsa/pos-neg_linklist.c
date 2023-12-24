#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *head1 = NULL;
struct node *head2 = NULL;

void add(struct node **p, int data)
{
    struct node *temp = *p;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    if (*p == NULL)
    {
        *p = temp = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        temp = newnode;
    }
}

void posneg(struct node *new)
{
    while (new != NULL)
    {
        if (new->data > 0)
        {
            add(&head1, new->data);
        }
        else if (new->data < 0)
        {
            add(&head2, new->data);
        }
        new = new->next;
    }
}

void display()
{
    struct node *temp = head1;
    printf("positive linklist is ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\nnegative linklist is ");
    temp = head2; 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

int main()
{
    int ch, num;
    int n = 1;
    while (n > 0)
    {
        printf("enter the option\n 1)add elements\n 2)convert\n 3)exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element: ");
            scanf("%d", &num);
            add(&head, num);
            break;
        case 2:
            posneg(head);
            display();
            break;
        case 3:
            return 0;
            break;
        }
    }

    return 0;
}
