#include <stdio.h>
#include <stdlib.h>
#define max 50
 int stack[max];
 int top=-1;
 int stack1[max];
 int top1=-1;
void add(int data)
{
    if(top==max-1)
    {
        printf("stack out of bounce");
    }
    else if(top==-1)
    {
        stack[++top]=data;
        //stack1[++top1]=data;
    }
    else
    {
        while(top!=-1&&data>stack[top])
        {
            stack1[++top1]=stack[top];
            top--;
        }
        stack[++top]=data;
        while(top1!=-1)
        {
            stack[++top]=stack1[top1--];
        }
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack is empty\n");
    }
    else
    stack[top--];
}
void small()
{
    printf("smallest element is %d\n",stack[top]);
}
void sort()
{
    printf("sorted order is\n ");
    while(top!=-1)
    {
        printf("%d ",stack[top]);
        top--;
    }
}
int main()
{ 
    int n=1,ch,d;
   while(n!=0)
   {
       printf("1) add\n2) pop \n3) display smallest element\n4) sorted order\n5)exit\n ");
       scanf("%d",&ch);
       switch(ch)
       {
       case 1: printf("enter data");
               scanf("%d",&d);
               add(d);
               break;
        case 2: pop();
                break;
        case 3: small();
                break;
        case 4: sort();
                break;
        case 5: return 0;
       }
        
   }
}
