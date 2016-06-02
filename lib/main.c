#include<stdio.h>
#include"lib_test.h"


int main()
{
    int a[20],n,i,reach[20],j,b[50][50],count;
    printf("n=");
    scanf("%d",&n);
    printf("\n Numarul de varfuri:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    reach[i]=0;
    for(j=1;j<=n;j++)
       b[i][j]=0;
    }
    printf("\n Introduceti matricea de adiacenta:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&b[i][j]);
    dfs(1);
    printf("\n");
    for(i=1;i<=n;i++)
    {
    if(reach[i])
       count++;
    }
    if(count==n)
      printf("\n Graful este conectat");
    else
      printf("\n Graful nu e conectat");
    getch();
}
