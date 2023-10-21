#include<iostream>
#include<math.h>
using namespace std;

int eb(int n, int r, int cnt, int EB)
{
    if(n == 0)
        return EB;
    else
    {
        r = n % 2;
        EB += r * pow(10,cnt);
        return eb(round(n/2), r, cnt + 1, EB);
    }
}

int main()
{
    int n;
    cout << "Input natural number n: ";
    cin >> n;
    cout << eb(n, 0, 0, 0);
    return 0;
}