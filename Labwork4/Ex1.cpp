/*
Pseudocode:
Declare N, sum;
Input N;
while (n >= 1)
    sum += n%10;
    n = int(n / 10);
end while
print sum;
*/

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n, sum;
    cout << "Input natural number N: ";
    cin >> n;
    cout << "The digit sum of N: ";
    while (n >= 1)
    {
        cout << " + " << n%10;
        sum += n % 10;
        n = int(n / 10);
    }
    cout << " = " << sum;
    return 0;
}

/*
BigO: O(n)
*/