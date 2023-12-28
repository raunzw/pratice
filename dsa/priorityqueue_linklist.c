#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *head=NULL;
struct node *temp;
struct node *temp1;
void add(int data,int priority)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->priority=priority;
    newnode->next=NULL;
    if(head==NULL)
    {
        temp=head=newnode;
        temp1=temp;
    }
    else if(priority<temp1->priority)
    {
        newnode->next=temp1;
        temp1=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    //temp->next=temp1;
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

    while (current!=NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    //printf("%d",current->data);

    printf("\n");
}

int main()
{
    int ch,d,p;
    printf(" 1)add \n 2) delete \n 3) display \n 4) exit \n");
    while(1)
    {
        printf("enter the option");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("enter the data with priority");
            scanf("%d %d",&d,&p);
            add(d,p);
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: return 0;
        }
    }
}
