#include<iostream>
using namespace std;

struct node
{
    int nop;
    char name;
    node *pnext;
};

struct car
{
    int size;
    node *pHead;
};
void init(car *l)
{
    l -> size = 0;
    l -> pHead = NULL;
}
node* initNode(int a, char b)
{
    node *Node = (node*) malloc(sizeof *Node);
    Node -> nop = a;
    Node -> name = b;
    Node -> pnext = NULL;
    return Node;
}
int isEmpty(car *l)
{
    return (l -> size == 0);
}
void insertFirst(car *l, node *pnew)
{
    if (isEmpty(l))
    {
        l -> size ++;
        l -> pHead = pnew;
    }
}
void insert(node *pnew, node *pold, car *l)
{
    pnew -> pnext = pold -> pnext;
    pold -> pnext = pnew;
    l -> size++;
}
void remove0nop(car *l)
{
    node *p = l -> pHead;
    if (p -> nop == 0)
    {
        l -> pHead = p -> pnext;
        l -> size --;
        free(p);
        return;
    }
    node *q = p -> pnext;
    int cnt = 1;
    while ((p -> nop != 0) && (cnt < l -> size))
    {
        q = p;
        p = p -> pnext;
        cnt++;
    }
    if (p != NULL)
    {
        q -> pnext = p -> pnext;
        free(p);
        l -> size --;
    }
}
void display(car *l)
{
    node *p = l -> pHead;
    node *q = p -> pnext;
    int cnt = 0;
    cout << "Display:" << endl;
    cout << "Length of the train: " << l -> size << endl;
    while (cnt < (l -> size))
    {
        cout << "Car" << cnt + 1 << endl;
        cout << "Number of passengers: " << p -> nop << endl;
        cout << "Name: " << p -> name << endl;
        q = p;
        p = p -> pnext;
        cnt++;
    }
}
int main()
{
    node *m, *n;
    car *l, list;
    l = &list;
    init(l);
    int size, nop;
    char name;
    cout << "Size of the Train: ";
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cout << "Car " << i + 1 << ":" << endl;
        cout << "Number of passengers: ";
        cin >> nop;
        cout << "Name of the car: ";
        cin >> name;
        m = initNode(nop, name);
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
    cout << "Add new car: " << endl;
    cout << "Enter number of car you want to add: ";
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cout << "Car " << i + 1 << ":" << endl;
        cout << "Number of passengers: ";
        cin >> nop;
        cout << "Name of the car: ";
        cin >> name;
        m = initNode(nop, name);
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
    remove0nop(l);
    display(l);
    return 0;
}