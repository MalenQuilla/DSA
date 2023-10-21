#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct _node{
    int passengers;
    char name;
    struct _node *pNext;
}node;

typedef struct _list{
    int size;
    struct _node *pHead;
}list;

void InitList(list *l){
    l -> size = 0;
    l -> pHead = NULL;
}

node* initNode(int c, char a){
    node *Node = (node*) malloc(sizeof *Node);
    Node -> name = a;
    Node -> passengers = c;
    Node -> pNext = NULL;
    return Node;
}

int isEmpty(list *l){
    return(l -> size == 0);
}

void insertFirst(list *l, node *pnew){
    if (isEmpty(l)){
        l -> size ++;
        l -> pHead = pnew;
    }
}

void insert(list *l, node *pnew, node *pold){
    pnew -> pNext = pold -> pNext;
    pold -> pNext = pnew;
    l -> size++;
}

void checkc(list *l){
    node *a = l -> pHead;
    for(int i = 0; i < l -> size -1; i++){
    if(a -> passengers != 0){
        a = a -> pNext;
        if (a -> pNext = NULL){
            return;
        }
     }
    }
    
    node *t = l -> pHead;
    if(t -> passengers == 0){
        l -> pHead = t -> pNext;
        free(t);
        l -> size--;
    }
    node *u = t -> pNext;
    for(int i = 0; i < l -> size; i++){
        if(u -> passengers == 0){
            t -> pNext = u -> pNext;
            l -> size--;
            free(u);
        }
        t = u;
        u = u -> pNext;
    }
}

void display(list *l){
    node *t = l ->pHead;
    printf("Length of the train is: %d \n",l -> size);
    for(int i = 0; i < l -> size; i++){
        printf ("Car %c has %d passengers \n", t -> name, t -> passengers);
        t = t -> pNext;
    }
}

int main(){
    char name;
    int size, passengers;
    node *t, *q;
    list *p, a;
    p = &a;
    InitList(p);
    printf("Size: \n");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        printf("Name of car %d: \n",i + 1);
        scanf("%s", &name);
        printf("Number of passengers of car %d: \n",i + 1);
        scanf("%d", &passengers);
        t = initNode(passengers, name);
        if (i == 0){
            insertFirst(p, t);
        }
        else{
            insert(p, t, q);
        }
        q = t;
    }

    printf("Add new car \n");
    printf("Enter number of car you want to add: \n");
    scanf("%d",&size);
    for(int i = 0; i < size; i++){
        printf("Name of car: \n");
        scanf("%s",&name);
        printf("Number of passengers of car: \n");
        scanf("%d",&passengers);
        t = initNode(passengers, name);
        insert(p, t, q);
        q = t;
    }
    
    
    checkc(p);
    
    display(p);
}