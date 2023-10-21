#include<iostream>
#include<math.h>
using namespace std;

void search(int Q[], int D[], int lenD, int lenQ, int count)
{
    if (count >= lenQ)
        return;
    for(int i = 0; i < lenD; i++)
    {
        if (Q[count] == D[i])
        {
            cout << i + 1 << ", ";
            return search(Q, D, lenD, lenQ, count + 1);
            break;
        }
        else if (i == lenD - 1)
        {
            cout << -1 << ", ";
            return search(Q, D, lenD, lenQ, count + 1);
            break;
        }
    }
}

int main()
{
    int m,n;
    cout << "Input length of the querry array Q: ";
    cin >> m;
    n = -1;
    while (n <= m)
    {
        cout << "Input length of the data array D(with a length more than Q): ";
        cin >> n;
    }
    int D[n], Q[m];
    for(int i = 0; i < n; i++)
    {
        cout << "Input D[" << i << "]: ";
        cin >> D[i];
    }
    for(int i = 0; i < m; i++)
    {
        cout << "Input Q[" << i << "]: ";
        cin >> Q[i];
    }
    search(Q, D, n, m, 0);
    return 0;
}