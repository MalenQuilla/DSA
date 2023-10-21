#include<iostream>
#include<math.h>
using namespace std;

double pi(double x, double n, double sum)
{
    sum += ((4 / (4*x + 1)) - (4 / (4*x + 3)));
    if (x == n)
        return sum;
    else return pi(x + 1, n, sum);
}

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << pi(0, n, 0);
    return 0;
}