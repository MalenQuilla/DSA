#include<iostream>
#include<math.h>
using namespace std;

struct items
{
    int quantity[3];
    string name[3];
    int size = 3;
};
void createlist(items *l)
{
    cout << "Please refill products in stock:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Enter name of items " << i + 1 << ": ";
        cin >> l -> name[i];
        cout << "Enter quantity of items " << i + 1 << ": ";
        cin >> l -> quantity[i];
    }
}
void displaylist(items *l)
{
    cout << "Products in stock:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        if (l -> quantity[i] == 0)
        {
            cout << l -> name[i] <<" out of stocks" << endl;
        } else
        {
            cout << i+1 << ". " << l -> name[i] << ": " << l -> quantity[i] << endl;
        }
    }
}

struct customers
{
    int quantity[1000];
    int item[1000];
    int front, back;
    int loc[1000];
};
void initqueue(customers *q)
{
    q -> front = 0;
    q -> back = 0;
}
int isEmpty(customers *q)
{
    return (q -> back == 0);
}
void enter(customers *q , int x, int y)
{
    if ( isEmpty(q)) 
    {
        q -> quantity[0] = x;
        q -> item[0] = y;
    } else 
    {
        int idx = q -> back;
        q -> quantity[idx] = x;
        q -> item[idx] = y;
    }
    q -> back++;
    for (int i = 0; i < (q -> back); ++i)
    {
        q -> loc[i] = i + 1;
    }
}
int leave(customers *q, items *l)
{
    if (isEmpty(q))
    {
        return 0;
    } else
    {
        if ((q -> back) - (q -> front) >= 1)
        {
            if((q -> quantity[0]) <= (l -> quantity[q -> item[0]]))
            {
                cout << "Customer " << q -> loc[0] << " has successfully purchased " << q -> quantity[0] << " " << l -> name[q -> item[0]] << endl;
                l -> quantity[q -> item[0]] -= q -> quantity[0];
            } else if((l -> quantity[q -> item[0]]) == 0)
            {
                cout << "Customer " << q -> loc[0] << " has unsuccessfully purchased " << q -> quantity[0] << " " << l -> name[q -> item[0]] << endl;
            } else
            {
                cout << "Customer " << q -> loc[0] << " has successfully purchased " << l -> quantity[q -> item[0]] << " " << l -> name[q -> item[0]] << endl; 
                l -> quantity[q -> item[0]] = 0;
            }
            for (int i = 1; i < (q -> back) - (q -> front); ++i)
            {
                q -> quantity[i - 1] = q -> quantity[i];
                q -> item[i - 1] = q -> item[i];
                q -> loc[i - 1] = q -> loc[i];
            }
            q -> back -= 1;
        }
    }
    return 1;
}

int main()
{
    items *l, list;
    l = &list;
    customers *q, queue;
    q = &queue;
    initqueue(q);
    int n, serial, quantity;
    createlist(l);
    displaylist(l);
    cout << "Enter the number of customers enter store today: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter the serial of the item that customer " << i + 1 << " wants to buy: ";
        cin >> serial;
        cout << "Enter the quantity of " << list.name[serial - 1] << " that customer wants to buy: ";
        cin >> quantity;
        enter(q, quantity, serial - 1);
    }
    for (int i = 0; i < n; ++i)
    {
        leave(q, l);
        displaylist(l);
    }
    return 0;
}