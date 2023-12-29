#include <stdio.h>
#include <stdlib.h>

#define N 5

int queue[N];
int f = -1, r = -1;

void enqueuefront(int data) {
    if ((r + 1) % N == f) {
        printf("Queue is full\n");
    }
    else if(f==-1)
    {
        f=r=0;
        queue[f]=data;
    }
        else {
        f = (f + N - 1) % N;
        queue[f] = data;
    }
}

void enqueuerear(int data) {
    if ((r + 1) % N == f) {
        printf("Queue is full\n");
    }
     else if(f==-1)
    {
        queue[f]=data;
        f=r=0;
    }
    else {
        r = (r + 1) % N;
        queue[r] = data;
    }
}

void dequeuefront() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else if (f == r) {
        f = r = -1;
    } else {
        f = (f + 1) % N;
    }
}

void dequeuerear() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else if (f == r) {
        f = r = -1;
    } else {
        r = (r + N - 1) % N;
    }
}

void display() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else {
        int temp = f;
        while (temp != r) {
            printf("%d ", queue[temp]);
            temp = (temp + 1) % N;
        }
        printf("%d\n", queue[r]);
    }
}
int main() 
{
    int choice, data;

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to enqueue at front: ");
                scanf("%d", &data);
                enqueuefront(data);
                break;
            case 2:
                printf("Enter data to enqueue at rear: ");
                scanf("%d", &data);
                enqueuerear(data);
                break;
            case 3:
                dequeuefront();
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
