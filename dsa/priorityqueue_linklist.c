#include <stdio.h>
#include <stdlib.h> // For malloc

struct node
{
    int data;
    int pri;
    struct node *next;
};

struct node *head = NULL;
struct node *temp;
struct node *temp1;

void insert(int data, int pi)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = data;
    newnode->pri = pi;
    newnode->next = NULL;
    
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else if (pi < head->pri)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *curr = head;
        while (curr->next != NULL && curr->next->pri < pi)
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void delete()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *delete = head;
        printf("%d\n", delete->data);
        head = head->next;
        free(delete);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp1 = head;
        while (temp1 != NULL)
        {
            printf("%d ", temp1->data);
            temp1 = temp1->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, data, pri;
    while (1)
    {
        printf("\nPriority Queue Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &pri);
            insert(data, pri);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
