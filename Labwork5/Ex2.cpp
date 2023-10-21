#include<iostream>
#include<math.h>
using namespace std;

struct list
{
    int size;
    int element[10000];
};
void init(list *l)
{
    l -> size = 0;
}
int isEmpty(list *l)
{
    return(l -> size == 0);
}
void create(list *l, int n)
{
    l -> size = n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Input element " << i + 1 << " of the list: ";
        cin >> l -> element[i];
    }
}
void sort(list *l)
{
    for (int i = 0; i <= l -> size; ++i)
    {
        int key = l -> element[i];
        int k = i + 1;
        while ((key > l -> element[k]) && (k < l -> size))
        {
            l -> element[k - 1] = l -> element[k];
            k += 1;
        }
        l -> element[k - 1] = key;
        for (int i = l -> size - 1; i >= 1 ; --i)
        {
            if (l -> element[i] < l -> element[i - 1])
            {
                int temp = l -> element[i];
                l -> element[i] = l -> element[i - 1];
                l -> element[i - 1] = temp;
            }
        }
    }
}
int display(list *l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    for (int i = 0; i < l -> size; ++i)
    {
        cout << l -> element[i] << " ";
    }
    return 1;
}

int main()
{
    int size;
    list *l, list;
    l = &list;
    init(l);
    cout << "Input the size of the list: ";
    cin >> size;
    if (isEmpty(l))
    {
        create(l, size);
        sort(l);
        display(l);
    }
    return 0;
}

/*
I use List structure because we can perform a sort from 1 to n and then perform a reversed sort from n to 1
*/