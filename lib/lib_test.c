#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include"lib_test.h"

void mergesort(int a[], int s, int h)
{
 int i = 0;
 int lung = h - s + 1;
 int pivot  = 0;
 int m1 = 0;
 int m2 = 0;
 int aux[100];

 if(s == h)
 return;

 pivot  = (s + h) / 2;

 mergesort(a, s, pivot);
 mergesort(a, pivot + 1, h);

 for(i = 0; i < lung; i++)
 {
  aux[i] = a[s + i];
 }

 m1 = 0;
 m2 = pivot - s + 1;

 for(i = 0; i < lung; i++)
 {
  if(m2 <= h - s)
  {
   if(m1 <= pivot - s)
   {
    if(aux[m1] > aux[m2])
    {
     a[i + s] = aux[m2++];
    }

    else
    {
     a[i + s] = aux[m1++];
    }
   }

   else
   {
    a[i + s] = aux[m2++];
   }
  }

  else
  {
   a[i + s] = aux[m1++];
  }
 }
}






int a[10],b[10];
void backtracking(int k,int lung)
{
    int i;
    for(i = 1; i <= lung; i++)
        b[i]=1;
     if(k-1 == lung)
     {
         for( i = 1; i <= lung;i++)
           printf("%d ",a[i]);
         printf("\n");
     }
     else
     {
         for(i = 1; i <= lung; i++)
            if(b[i]!=0)
           {
                 a[k] = i;
                 b[i] = 1;
                 backtracking(k+1,lung);
                 b[i] = 0;
           }
     }
}


void heapsort(int a[],int n) {
	int i,t;
	heapify(a,n);
	for (i=n-1;i>0;i--) {
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		adjust(a,i);
	}
}

void heapify(int a[],int n) {
	int k,i,j,item;
	for (k=1;k<n;k++) {
		item = a[k];
		i = k;
		j = (i-1)/2;
		while((i>0)&&(item>a[j])) {
			a[i] = a[j];
			i = j;
			j = (i-1)/2;
		}
		a[i] = item;
	}
}


void adjust(int a[],int n) {
	int i,j,item;
	j = 0;
	item = a[j];
	i = 2*j+1;
	while(i<=n-1) {
		if(i+1 <= n-1)
		   if(a[i] <a[i+1])
		    i++;
		if(item<a[i]) {
			a[j] = a[i];
			j = i;
			i = 2*j+1;
		} else
		   break;
	}
	a[j] = item;
}




void quickSort(int *a, int s, int d)
{
    if (s >= d)
        return;
    int v = partition(a, s, d);
    quickSort(a, s, v - 1);
    quickSort(a, v + 1, d);
}

int partition(int *a, int s, int d)
{
    int v = a[s];
    int i = s + 1;
    int j = d;

    while (true) {
        while (a[i] < v && i < d)
            i++;
        while (a[j] >= v && j > s)
            j--;
        if (i >= j)
            break;
        swap(a, i, j);
    }
    swap(a, s, j);
    return j;
}

void swap(int *a, int i, int j)
{
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}


int n;
void dfs(int v)
{
    int a[20][20],reach[20];
 int i;
 reach[v]=1;
 for(i=1;i<=n;i++)
  if(a[v][i] && !reach[i])
  {
   printf("\n %d->%d",v,i);
   dfs(i);
  }
}

