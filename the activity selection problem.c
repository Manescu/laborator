#include <stdio.h>
#include <stdlib.h>


int main()
{
     int n,i,aux,j,k=0;
     int *a, *s,*f;
     printf("dati nr de activitati:\n");
     scanf("%d",&n);

     a=calloc(n,sizeof(int));
     s=calloc(n,sizeof(int));
     f=calloc(n,sizeof(int));

     printf("introduceti timpul de inceput si de sfarsit al activitatii::\n");
     printf("ocupatia\t inceput\t sfarsit\n");
     for(i=0;i<n;i++)
    {
        a[i]=i+1;
        printf("A[%d]\t",a[i]);
        scanf("%d",&s[i]);
        scanf("%d",&f[i]);
     }

      for(i=n-2;i>=0;i--)
      {
        for(j=0;j<=i;j++)
        {
            if(f[j]>f[j+1])
            {
                aux=f[j+1];
                f[j+1]=f[j];
                f[j]=aux;

                aux=s[j+1];
                s[j+1]=s[j];
                s[j]=aux;

                aux=a[j+1];
                a[j+1]=a[j];
                a[j]=aux;
            }
         }
       }


     for(i=0;i<n;i++)
    {
         printf("A[%d]\t",a[i]);
         printf("%d\t",s[i]);
         printf("%d\n",f[i]);
     }
     printf("orarul final:\n");
     printf("\nA[%d]\t",a[0]);
     for(i=1;i<n;i++)
     {
         if(s[i]>=f[k])

         {
             printf("A[%d]\t",a[i]);
             k=i;
         }
     }
     printf("\n");
     free(a); free(s); free(f);
     return 0;
}
