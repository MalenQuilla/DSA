#include<iostream>
#include<math.h>
using namespace std;

double pi(int x, double y, int n, double sum)
{
    int odd_arr[n];
    odd_arr[0] = 1;
    for (int i = 1; i <=n; i++)
    {
        odd_arr[i] = odd_arr[i - 1];
    }
    sum += pow(x, 2)/
}

int main()
{
    int n;
    double sum;
    cout << "Input n: ";
    cin >> n;
    sum += pi(1, 3, n);
    cout << 4/sum;
    return 0;
}