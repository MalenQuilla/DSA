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
int factorization(int n, int i)
{
    if(primecheck(i) == 1)
    {
        while (n % i == 0)
            {
                if(n / i == 1)
                {
                    cout << i;
                    return 0;
                }
                else
                {
                    cout << i << " * ";
                }
                n = n / i;
            }
    }
    return factorization(n, i + 1);
}

int main()
{
    int n;
    cout << "Input number N: ";
    cin >> n;
    factorization(n, 2);
    return 0;
}