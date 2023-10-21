#include<iostream>
#include<math.h>
using namespace std;

struct node
{
    int numb;
    node *pnext;
};

struct list
{
    int size;
    node *phead;
};

void InitList(list *l)
{
    l -> size = 0;
    l -> phead = NULL;
}
node* InitNode(int x)
{
    node *p = (node*) malloc(sizeof *p);
    p -> numb = x;
    p -> pnext = NULL;
    return p;
}
int isEmpty(list *l)
{
    return (l -> size == 0);
}
void insertFirst(list *l, node *pnew)
{
    if (isEmpty(l))
    {
        l -> size ++;
        l -> phead = pnew;
    }
}
void insert(node *pnew, node *pold, list *l)
{
    pnew -> pnext = pold -> pnext;
    pold -> pnext = pnew;
    l -> size++;
}
void display(list *l)
{
    node *p = l -> phead;
    node *q = p -> pnext;
    int cnt = 0;
    while (cnt < (l -> size))
    {
        cout << p -> numb << " ";
        q = p;
        p = p -> pnext;
        cnt++;
    }
}
void sort(list *l)
{
    node *p = l -> phead;
    node *q = p -> pnext;
    int key = p -> numb;
    int cnt = 2;
    while ((key > q -> numb) && (cnt < l -> size))
    {
        p -> numb = q -> numb;
        q = p;
        p = p -> pnext;
    }
    p -> numb = key;
}
int main()
{
    node *m, *n;
    list *l, list;
    l = &list;
    InitList(l);
    int size, numb;
    cout << "Size of the list: ";
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cout << "Input element " << i + 1 << " of the list: ";
        cin >> numb;
        m = InitNode(numb);
        if (i == 0)
        {
            insertFirst(l, m);
        }
        else
        {
            insert(m, n, l);
        }
        n = m;
    }
    sort(l);
    display(l);
    return 0;
}