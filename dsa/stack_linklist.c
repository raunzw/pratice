#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *temp;
void add(int data)
{
    
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        newnode->next=temp;;
        temp=newnode;
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("nothing to pop");
    }
    else if(head==temp)
    {
        free(temp);
    }
    else
    {
        temp=temp->next;
    }
}
void display()
{
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int  main()
{
    int n,d;
    while(1)
    {
    printf("enter \n 1)add \n 2)pop \n 3)display \n 4)exit ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:printf("enter the data");
                scanf("%d",&d);
                while(d>0)
                {
                add(d%2);
                d=d/2;
                }
                break;
        case 2:pop();
                break;
        case 3: display(); 
        break;
        case 4: return 0;
    }
  }
}
