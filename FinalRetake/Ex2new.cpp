#include<iostream>
#include<math.h>
using namespace std;

double pi(int x, double y, double n)
{
    if (x == n)
        return y + pow(x, 2)/(y + 2);
    return y + pow(x, 2)/pi(x + 1, y + 2, n);
}

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << 4/pi(1, 1, n);
    return 0;
}