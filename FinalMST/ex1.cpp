#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n, r, eb = 0, cnt = 0;
    cout << "Input natural number n: ";
    cin >> n;
    while(n != 0)
    {
        r = n%2;
        n = round(n/2);
        eb += r * pow(10,cnt);
        cnt++;
    }
    cout << eb;
    return 0;
}