#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp;
struct node *temp1;
void add(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        temp=head=newnode;
        temp1=temp;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
        
    }
    temp->next=temp1;
}
void delete()
{
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(temp1==temp)
    {
        free(head);
        head=temp=NULL;
    }
    else
    {
        temp1=temp1->next;
    }
    
}
void display()
{
    struct node *current = temp1; // Use a local pointer

    while (current->next!=temp1)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d",current->data);

    printf("\n");
}

int main()
{
    int ch,d;
    printf(" 1)add \n 2) delete \n 3) display \n 4) exit \n");
    while(1)
    {
        printf("enter the option");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("enter the data");
            scanf("%d",&d);
            add(d);
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: return 0;
        }
    }
}
