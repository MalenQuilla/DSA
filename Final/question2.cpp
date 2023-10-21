#include<iostream>
#include<math.h>
using namespace std;

int primecheck(int n)
{
    if(n < 2)
    {
        return 0;
    }
    for(int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

struct node
{
    int val;
    node *pnext;
};

struct list
{
    int size;
    node *pHead;
};
void init(list *l)
{
    l -> size = 0;
    l -> pHead = NULL;
}
node* initNode(int a)
{
    node *Node = (node*) malloc(sizeof *Node);
    Node -> val = a;
    Node -> pnext = NULL;
    return Node;
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
        l -> pHead = pnew;
    }
}
void insert(node *pnew, node *pold, list *l)
{
    pnew -> pnext = pold -> pnext;
    pold -> pnext = pnew;
    l -> size++;
}
void twinprimesADT(list *l)
{
    node *p = l -> pHead;
    while (p -> pnext != NULL)
    {
        node *q = p -> pnext;
        while (q -> pnext != NULL)
        {
            if((primecheck(p -> val) == 1) && (primecheck(q -> val) == 1) && ((p -> val - q -> val == 2) || (q -> val - p -> val == 2)))
                cout << p -> val << " " << q -> val << endl;
            q = q -> pnext;
        }
        p = p -> pnext;
    }
}

int main()
{
    node *m, *n;
    list *l, List;
    l = &List;
    init(l);
    int size, value;
    cout << "Size of the array: ";
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        m = initNode(value);
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
    m = initNode(0);/*Because my twinprimesADT function skip the last q node so that i create 1 more node with value = 0 at the end of the linked-list*/
    insert(m, n, l);
    cout << "All twin primes in the array: " << endl;
    twinprimesADT(l);
    return 0;
}

/*
My method is using 2 nested for loop. The 2nd one run inside the 1st one so that we can compare every 2 elements in the array.
So that, that function complexity is O(n^2) and the algorithm complexity is O(n^3) because there is 1 more for loop in prime checking function.
*/