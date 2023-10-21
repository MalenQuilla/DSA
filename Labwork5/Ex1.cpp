#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout << "Input size of the array: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Input a[" << i << "]: ";
        cin >> a[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        int key = a[i];
        int k = i + 1;
        while ((key > a[k]) && (k < n))
        {
            a[k - 1] = a[k];
            k += 1;
        }
        a[k - 1] = key;
        for (int i = n - 1; i >= 1 ; --i)
        {
            if (a[i] < a[i - 1])
            {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}

/*
BigO: O(n^2)
SmallO: O(1)
*/