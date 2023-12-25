
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void add(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        temp = head = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->next=NULL;
        temp = newnode;
    }
}

void sort()
{
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data>j->data)
            {
                temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }

    printf("sorted list is: ");
    struct node *temp1 = head;
    while (temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

int main()
{
    int ch;
    int n = 1;
    while (n > 0)
    {
        printf("enter your choice \n 1) add elements\n 2) sort\n 3) exit ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element: ");
            scanf("%d", &n);
            add(n);
            break;
        case 2:
            sort();
            break;
        case 3:
            return 0;
            break;
        }
    }
}
