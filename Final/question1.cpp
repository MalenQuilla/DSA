/*
Pseudo-code:
int primecheck(int n)
    if n < 2
        return 0;
    endif
    for i: 2 -> n - 1
        if n % i == 0
            return 0
        endif
    endfor
    return 1
int twinprimes(int a[], int n, int i)
    for j: i + 1 -> n
        if((primecheck(a[i]) == 1) && (primecheck(a[j]) == 1) && ((a[j] - a[i] == 2) || (a[i] - a[j] == 2)))
            a[i] and a[j] are twinprimes
        endif
    endfor
    if i == n - 1
        return 0
    endif
    return twinprimes(a, n, i + 1)
int main()
    input size of array: n
    input elements of the array a[]
    call function: twinprimes(a, n, 0)
*/

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
int twinprimes(int a[], int n, int i)
{
    for(int j = i + 1; j <= n; ++j)
    {
        if((primecheck(a[i]) == 1) && (primecheck(a[j]) == 1) && ((a[j] - a[i] == 2) || (a[i] - a[j] == 2)))
        {
            cout << a[i] << " " << a[j] << endl;
        }
    }
    if(i == n - 1)
        return 0;
    return twinprimes(a, n, i + 1);
}

int main()
{
    int n;
    cout << "Input size of the array: ";
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cout << "Input a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "All twin primes in the array: " << endl;
    twinprimes(a, n, 0);
    return 0;
}

/*
Complexity: O(n^3)
Because in my algorithm there are 2 nested for loop and 1 recursion method
*/