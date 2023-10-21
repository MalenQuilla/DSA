#include<iostream>
#include<math.h>
using namespace std;

int digitsum(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n % 10 + digitsum(int(n/10));
    }
}
int main()
{
    int n;
    cout << "Input natural number N: ";
    cin >> n;
    cout << "Digit sum of N: " << digitsum(n);
    return 0;
}

/*
BigO: O(2^n)
*/