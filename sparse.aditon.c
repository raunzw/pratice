#include <stdio.h>
void add(int tup1[100][3],int tup2[100][3],int r,int c)
{
    int i=0,j=0;
    int tup3[100][3];
    int k=0;
        while(i<r&&j<c)
        {
            if(tup1[i][1]==tup2[j][1]&&tup1[i][0]==tup2[j][0])
            {
                tup3[k][2]=tup2[j][2]+tup1[i][2];
                tup3[k][1]=tup2[j][1];
                tup3[k][0]=tup2[j][0];
                i++;
                j++;
                k++;
            }
            else if(tup1[i][0]<tup2[j][0]||(tup1[i][0]==tup2[j][0]&&tup1[i][1]<tup2[j][1]))
            {
                tup3[k][2]=tup1[i][2];
                tup3[k][1]=tup1[i][1];
                tup3[k][0]=tup1[i][0];
                i++;
                k++;
            }
            else
            {
                tup3[k][2]=tup2[j][2];
                tup3[k][1]=tup2[j][1];
                tup3[k][0]=tup2[j][0];
                j++;
                k++;
            }
        }
        while(i<r)
        {
                tup3[k][2]=tup1[i][2];
                tup3[k][1]=tup1[i][1];
                tup3[k][0]=tup1[i][0];
                i++;
                k++;
        }
        while(j<c)
        {
                tup3[k][2]=tup2[j][2];
                tup3[k][1]=tup2[j][1];
                tup3[k][0]=tup2[j][0];
                k++;
                j++;
        }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",tup3[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    int n,n1;
    printf("enter the no of elements of the 1st tuple");
    scanf("%d",&n);
    printf("enter the no of elements of the 2nd tuple");
    scanf("%d",&n1);
    int tup1[n][3],tup2[n1][3];
    printf("enter the elements of 1st matrix");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&tup1[i][j]);
        }
    }
    printf("enter the elements of the second matrix");
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&tup2[i][j]);
        }
    }
    printf("final matrix\n");
    add(tup1,tup2,n,n1);
    
}
