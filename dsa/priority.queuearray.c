#include <stdio.h>

struct node
{
    int data;
    int pri;
};

struct node p[20];
int front = -1;
int rear = -1;

void add(int data, int pri)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        p[rear].data = data;
        p[rear].pri = pri;
        rear++;
    }
    else if (rear == 20)
    {
        printf("Queue is full\n");
    }
    else
    {
        p[rear].data = data;
        p[rear].pri = pri;
        rear++;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("List is empty\n");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    struct node temp;
    for (int i = front; i < rear; i++)
    {
        for (int j = front; j < rear - i - 1; j++)
        {
            if (p[j].pri > p[j + 1].pri)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (int i = front; i < rear; i++)
    {
        printf("%d ", p[i].data);
    }
    printf("\n");
}

int main()
{
    int choice, data, pri;
        printf("\nPriority Queue Operations\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
    while (1)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &pri);
            add(data, pri);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

  
