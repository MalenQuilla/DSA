#include<iostream>
#include<math.h>
using namespace std;

int prime(int n)
{
    if (n <=2)
    {
        return 0;
    }
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int primemax(int n) //Return maximum prime number from 1 to n
{
    if (n <= 2)
    {
        return 2;
    }
    if (prime(n - 1) == 1)
    {
        return n-1;
    }
    return primemax(n - 1);
}
int sphenic(int n, int n1, int x)
{
    if ((n == 1) && (x == 3))
    {
        return 1;
    }
    if (n == 4)
    {
        return 0;
    }
    if ((n1 == 2) && (n % 2 != 0))
    {
        return 0;
    }
    if(n % primemax(n1) == 0)
    {
        return sphenic(n / primemax(n1), n / primemax(n1), x + 1);
    }
    else
    {
        return sphenic(n, primemax(n1), x);
    }
}
int main()
{
    int n, count = 0;
    cout << "Input natural number n: ";
    cin >> n;
    if ((sphenic(n, n, count) == 1))
    {
        cout << n << " is sphenic number" << endl;
    }
    else
    {
        cout << n << " isn't sphenic number" << endl;
    }
    return 0;
}

/*
BigO: O(n*2^(2*n))
*/