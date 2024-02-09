#include <stdio.h>
void main()
{
    int r,c;
    printf("enter the rows and cols of the matrix");
    scanf("%d%d",&r,&c);
    int mat[r][c];
    printf("enter the elements");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    
    int ji;
    
    for(int i=0;i<r;i++)
    {
        int flag=1;
        int max=mat[i][0];
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]>max)
            {
                max=mat[i][j];
                ji=j;
            }
        }
        for(int k=0;k<r;k++)
        {
            if(mat[k][ji]<max)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            printf("%d",mat[i][ji]);
        }
    }
}
