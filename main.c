#include <stdio.h>
#include <stdlib.h>
#define M[1000][1000]
#define c[10000]
struct Nod {
int val;
struct Nod *next;};

push_first(struct Nod*head)
{ int val;
    struct Nod *current,*new_Nod;
    current=head;

    while(current->next!=NULL){
        current=current->next;
    }
struct *new_nod =(Nod*) malloc(sizeof(Nod));
    current->next=new_nod;
    new_nod->data=val;
    new_nod->next=NULL;
}

pop_first(struct Nod*head)
{
    int value;
    Nod *primul_element;
    primul_element=head->next;
    value=primul_element->data;
    head->next=primul_element->next;
    free(primul_element);
    return value;
}

void citire(int nRN, int nRR){

    for(i=1;i<=nRN;i++)
        for(j<=nRr;j++)
            {M[i][j]=0;
            v[i]=0; }
    for(i=1;i<=nRN;i++)
    {
        scanf("%d %d",&x, &y);
        m[x][y]=
    }

void dfs(){
    while(head->next!=NULL)
    {
        int aux=head->next->val;
        v[aux]=1;
        printf("%d", v[aux]);
        for(i=0;i<=nRN;i++)

            if(m[aux][i]==1 || v[i]==0)
                push_first(i,head);

    }


}

int main()
{
   int nr_nod,nr_muchii;
   scanf("%d ",&nr_nod);
   scanf("%d", &nr_muchii);
   citire(nr_nod,nr_muchi);
   struct
}
