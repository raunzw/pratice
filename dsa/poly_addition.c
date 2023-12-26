
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int exp1;
    int coeff;
    struct node *next;
    
};
struct node *head = NULL;
struct node *head1=NULL;
struct node *head2=NULL;
void add(struct node **p,int coeff,int exp1)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    newnode->coeff = coeff;
    newnode->exp1=exp1;
    newnode->next = NULL;
    if (*p == NULL)
    {
        temp = *p = newnode;
    }
    else
    {
        temp->next = newnode;
        //newnode->next=NULL;
        temp = newnode;
    }
}
void adds(struct node *p1, struct node *p2)
{
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp1 == p2->exp1)
        {
            add(&head2, p1->coeff + p2->coeff, p1->exp1);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp1 > p2->exp1)
        {
            add(&head2, p1->coeff, p1->exp1);
            p1 = p1->next;
        }
        else
        {
            add(&head2, p2->coeff, p2->exp1);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        add(&head2, p1->coeff, p1->exp1);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        add(&head2, p2->coeff, p2->exp1);
        p2 = p2->next;
    }
}

void display()
{
    printf("1st polynomial is\n ");
    while(head->next!=NULL)
    {
        printf("%dx%d+",head->coeff,head->exp1);
        head=head->next;
    }
    printf("%dx%d\n",head->coeff,head->exp1);
    printf("2nd polynomial is \n");
    while(head1->next!=NULL)
    {
        printf("%dx%d+",head1->coeff,head1->exp1);
        head1=head1->next;
    }
    printf("%dx%d\n",head1->coeff,head1->exp1);
    printf("final polynomial is\n ");
    while(head2->next!=NULL)
    {
        printf("%dx%d+",head2->coeff,head2->exp1);
        head2=head2->next;
    }
    printf("%dx%d\n",head2->coeff,head2->exp1);
}
int main()
{
    int ch, x, y, x1, y1;
    int n = 1;

    while (n != 0)
    {
        printf("enter your choice \n 1)1st polynomial \n 2)second polynomial \n 3)add\n 4)display ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("enter the coefficient and exponent of 1st polynomial in order");
            scanf("%d", &x);
            scanf("%d", &y);
            add(&head, x, y);
            break;
        case 2:
            printf("enter the coefficient and exponent of 2nd polynomial in order");
            scanf("%d", &x1);
            scanf("%d", &y1);
            add(&head1, x1, y1);
            break;
        case 3:
            printf("h");
            //head2 = NULL; // Initialize head2 before calling adds
            adds(head, head1);
            break;
        case 4:
            display();
            return 0;
            break;
        }
    }
    return 0;
}
