#include <stdio.h>
void main()
{
    int n,n1;
    int coeff1,expo1;
    int coeff2,expo2;
    printf("enter the no of terms of the 1st polynomial");
    scanf("%d",&n);
    printf("enter the no of terms of the 2nd polynomial");
    scanf("%d",&n1);
    struct poly
    {
        int coeff;
        int expo;
    };
    struct poly p1[20],p2[20],p3[20];
    printf("enter the coeff and degree of the 1st polynomial");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&coeff1,&expo1);
        p1[i].coeff=coeff1;
        p1[i].expo=expo1;
    }
    printf("enter the coeff and degree of the 2nd polynomial");
    for(int i=0;i<n1;i++)
    {
        scanf("%d%d",&coeff2,&expo2);
        p2[i].coeff=coeff2;
        p2[i].expo=expo2;
    }
    int i=0;
    int k=0;
    int j=0;
    while(i<n&&j<n1)
    {
        if(p1[i].expo==p2[j].expo)
        {
            p3[k].coeff=p2[j].coeff+p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;
            j++;
            k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;
            k++;
        }
        else
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            k++;
            j++;
        }
    }
    while(i<n)
    {
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;
            k++;
    }
    while(j<n1)
    {
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            k++;
            j++;
    }
    printf("sum polynomial is");
    for(int i=0;i<k;i++)
    {
        if(i<k-1)
        {
            printf("%d*x^%d+",p3[i].coeff,p3[i].expo);
        }
        else
        {
            printf("%d*x^%d",p3[i].coeff,p3[i].coeff);
        }
    }
}
