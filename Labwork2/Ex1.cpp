#include<iostream>
#include<math.h>
using namespace std;

struct func
{
    int size;
    int constant[1000];
    int degree[1000];
};
void init(func *l)
{
    l -> size = 0;
}
int isEmpty(func *l)
{
    return (l -> size == 0);
}
void create(func *l, int n)
{
    l -> size = n;
    for (int i = 0; i <= n; ++i)
    {
        cout << "Input a" << i << ": ";
        cin >> l -> constant[i];
        l -> degree[i] = i;
    }
}
void disp(func *l)
{
    cout << "y =";
    for (int i = 0; i < (l -> size + 1); ++i)
    {
        if (l -> constant[i] != 0)
        {
            cout << " + " << l -> constant[i] << "x^" << l -> degree[i];
        }
    }
    cout << endl;
}
void add(func *l, int a, int b)
{
    for (int i = 1; i < (l -> size + 1); ++i)
    {
        if (i == b)
        {
            l -> constant[i] += a;
        }
    }
    if (b > l -> size)
    {
        l -> constant[b] = a;
        l -> degree[b] = b;
        for (int j = l -> size; j < b; ++j)
        {
            l -> constant[j] = 0;
            l -> degree[j] = j;
        }
        l -> size = b;
    }
}
void remove(func *l, int a)
{
    for (int i = 1; i < (l -> size + 1); ++i)
    {
        if (i == a)
        {
            l -> constant[i] = 0;
        }
    }
}
int calc(func *l, int x)
{
    int ans = 0;
    for (int i = 0; i <= l -> size; ++i)
    {
        int a = l -> constant[i], b = l -> degree[i];
        ans += a * pow(x, b);
    }
    return ans;
}
int main()
{
    int n, constant, degree, index, x;
    func *l, list;
    l = &list;
    init(l);
    cout << "Size: ";
    cin >> n;
    if (isEmpty(l))
    {
        create(l, n);
        disp(l);
        cout << "Input new term" << endl;
        cout << "Input degree: ";
        cin >> degree;
        cout << "Input constant: ";
        cin >> constant;
        add(l, constant, degree);
        disp(l);
        cout << "Remove a term" << endl;
        cout << "Input index: ";
        cin >> index;
        remove(l, index);
        disp(l);
        cout << "Calculate function" << endl;
        cout << "Input x: ";
        cin >> x;
        cout << "y = " << calc(l, x);
    }
    return 0;
}