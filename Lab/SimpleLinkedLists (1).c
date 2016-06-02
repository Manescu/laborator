#include<stdio.h>
#include<stdlib.h>

//tipul nod
typedef struct Nod {
    int data;                                   //ce va retine fiecare nod
    struct Nod * next;                          //pointeri catre elementul urmator
};


void print_list(struct Nod *head) {
    if (head->next!= NULL){                     // daca lista nu este goala
struct        Nod *current = head;                    //nodul curent primeste head
        do {
            current = current->next;            //nodul curent primeste urmatorul element
            printf("%d,", current->data);       //printeaza valoarea nodului curent
        }while (current->next != NULL);
        printf("\n");
    }else{
        printf("Lista este goala\n");           //daca dupa nodul head nu mai avem alte elemente
    }
}

// adaugam elemente din stanga listei, ca la stiva
void push_first(struct Nod *head, int val){
struct    Nod *new_nod;                               //creez un nod nou
    new_nod = (struct Nod*)malloc(sizeof(struct Nod));        // aloc memmorie pentru noul nod
    new_nod->data = val;                        //se da valoarea noului element
    new_nod->next = head->next;                 //noul nod va pointa catre al doilea element (ex primul)
    head->next = new_nod;                       //head-ul va pointa catre noul nod creat
}

//adaugam elemente la dreapta listei, ca la vector
void push_last(struct Nod *head, int val){
struct    Nod *current,*new_nod;
    current=head;
    //cat timp elementul la care am ajuns mai are un nod dupa inseamna ca nu este ultimul
    while(current->next!=NULL){
        current=current->next;
    }
    //current va avea acum adresa ultimului element
    new_nod =(struct Nod*) malloc(sizeof(struct Nod));        // aloc memmorie pentru noul
    current->next=new_nod;                      //ultimul nod va pointa acum catre noul nod creat
    new_nod->data=val;                          //i se atribuie o valoare noului nod
    new_nod->next=NULL;                         //noul nod devine ultimul deci va pointa catre NULL
}

//adaugam un nou element la pozitia poz
void push_poz(struct Nod *head, int poz, int val){
    int iterator;                               //declaram un iterator cu care ne vom plimba prin lista
struct    Nod *current;                               //declaram un nod cu care ne vom plimba prin lista
struct    Nod *added_node;                            //declaram nodul pe care il vom adauga
    iterator=0;                                 //iteratoul va pleca de la inceputul listei
    current=head;                               //nodul curent pleaca de la head
    //atat timp cat nu am ajuns la pozitia ceruta
    while(iterator<poz){
        current=current->next;
        iterator++;
    }
    added_node=(struct Nod*) malloc(sizeof(struct Nod));      //alocam in memorie noul nod
    added_node->next=current->next;             //noul nod se va adresa la urmatorul dupa curent
    current->next=added_node;                   //nodul current va adresa noul nod adaugat
    added_node->data=val;                       //dam nodului o valoare
}

//extragem primul element din lista, ca la stiva
int pop_first(struct Nod * head){
    int value;                                  //o variabila pe care o voi returna
 struct   Nod *primul_element;                        //declar primul element
    primul_element=head->next;                  //primul element primeste adresa elementului dupa head
    value=primul_element->data;                 //in value vom retine valoarea primului element
    head->next=primul_element->next;            //head va primi adresa celui de-al doilea element
    free(primul_element);                       //dealocam din memorie primul element
    return value;                               //returnam valoarea primului element
}

//extragem ultimul element din lista
int pop_last(struct Nod * head){
struct    Nod *current,*deleted_node;                 //declar doua noduri
    int value;                                  //o variabila pe care o voi returna
    current=head->next;                         //nodul curent devine primul element din lista
    //cat timp nu am ajuns la penultimul element
    while(current->next->next!=NULL){
        current=current->next;
    }
    //current devine penultimul nod
    deleted_node=current->next;                 //deleted_node devine ultimul nod
    value=deleted_node->data;                   //preluam valuare in value a ultimului nod
    free(deleted_node);                         //dealocam ultimul nod
    current->next=NULL;                         //nodul curent devine ultimul deci va primi NULL la adresa urmatorului element
    return value;                               //returnam valoarea ultimului element
}

int pop_poz(struct Nod *head,int poz){
    int iterator;                               //declaram un iterator cu care ne vom plimba prin lista
    int value;
struct    Nod *current;                               //declaram un nod cu care ne vom plimba prin lista
struct    Nod *deleted_node;                          //declaram nodul pe care il vom adauga
    iterator=0;                                 //iteratoul va pleca de la inceputul listei
    current=head;                               //nodul curent pleaca de la head
    //atat timp cat nu am ajuns la pozitia ceruta
    while(iterator<poz-1){
        current=current->next;
        iterator++;
    }
    deleted_node=current->next;                 //nodul ce va fi sters este urmatorul
    value=deleted_node->data;                   //in value retinem informatia din nodul ce va fi sters
    current->next=deleted_node->next;           //nodul curent va adresa
    free(deleted_node);
}

int main ()
{
    int aux;

struct    Nod * head=NULL; // creez nodul de start
    head=(struct Nod*) malloc(sizeof(struct Nod)); // aloc memorie pentru nodul de start
    head->next=NULL;

    //verific ca nodul de start sa fie alocat
    if (head->data==NULL){
        printf("Lista este goala\n");
    }

    push_last(head,1);
    push_last(head,2);
    push_last(head,3);
    push_first(head,0);
    print_list(head);
    pop_last(head);
    pop_first(head);
    print_list(head);
    push_last(head,3);
    push_poz(head,1,10);
    print_list(head);
    pop_poz(head,3);
    print_list(head);
}