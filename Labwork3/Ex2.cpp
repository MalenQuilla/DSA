#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    char chr;
    struct node *pnext;
};
struct stack
{
    int size;
    string name;
    node *ptop;
};
void init(stack *st, string name)
{
    st -> size = 0;
    st -> name = name;
    st -> ptop = NULL;
}
int isEmpty(stack st)
{
    return (st.size == 0);
}
int push(char x, stack *st)
{
    node *p = (node *) malloc(sizeof(node));
    p -> pnext = NULL;
    if (p == NULL)
    {
        return 0;
    }
    p -> chr = x;
    p -> pnext = st -> ptop;
    st -> ptop = p;
    st -> size ++; 
    return 1;
}
int display(stack *st)
{
    cout << st -> name << " stack: ";
    if (st -> ptop == NULL)
    {
        cout << endl;
        return 0;
    }
    node *p = st -> ptop;
    node *q = p -> pnext;
    int cnt = 0;
    while (cnt < (st -> size))
    {
        cout << p -> chr << " -> ";
        q = p;
        p = p -> pnext;
        cnt++;
    }
    cout << endl;
    return 1;
}
int pop(stack *st1, stack *st2)
{
    node *p;
    if(isEmpty(*st1))
    {
        return 0;
    }
    p = st1 -> ptop;
    st1 -> ptop = st1 -> ptop -> pnext;
    st1 -> size --;
    p -> pnext = st2 -> ptop;
    st2 -> ptop = p;
    st2 -> size ++; 
    return 1;
}

int main()
{
    stack *st1, redo, *st2, undo;
    st1 = &redo;
    st2 = &undo;
    init(st1, "Redo");
    init(st2, "Undo");
    node *n;
    char chr;
    int size, u, r;
    cout << "Input length of the string: "; 
    cin >> size;
    cout << "Input string: " << endl;
    for (int i = 1; i <= size; ++i)
    { 
        cout << "Input character " << i << ": ";
        cin >> chr;
        push(chr, st1);
    }
    display(st1);
    display(st2);
    cout << "Input the number of characters which need to be undo: ";
    cin >> u;
    for (int i = 0; i < u; ++i)
    {
        pop(st1, st2);
    }
    display(st1);
    display(st2);
    cout << "Input the number of characters which need to be redo: ";
    cin >> r;
    for (int i = 0; i < r; ++i)
    {
        pop(st2, st1);
    }
    display(st1);
    display(st2);
    return 0;
}