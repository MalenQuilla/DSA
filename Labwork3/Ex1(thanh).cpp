#include <bits/stdc++.h>
using namespace std;

// customer class with variable custno as the customer serial no and k as the quantity that the customer will buy
class cust
{
    public:
        int custno;
        int k;
};

int main()
{
    queue<cust> q;
    int n; // initial no of customers
    cout << "Enter the no of customers: ";
    cin >> n;

    int item1, item2, item3; // to store the initial quantity of each product
    cout << "Enter the quantity of Item no 1: ";
    cin >> item1;
    cout << "Enter the quantity of Item no 2: ";
    cin >> item2;
    cout << "Enter the quantity of Item no 3: ";
    cin >> item3;

    int id = 0; // customer no
    int K; // to store the quantity for each customer
    // input the quantity for each customer
    for(int i = 0; i < n; i++)
    {
        cust c;
        c.custno = id;
        id++;
        cout << "Enter the quantity for customer" << id << ": ";
        cin >> K;
        c.k = K;
        q.push(c);

        int item_no;
        cout << "Enter the item no(1,2,3): ";
        cin >> item_no;
        if(item_no == 1)
        {
            if(K > item1)
            {
                cout << "Warning: Item no 1 is out of stock!" << endl;
                cout << "Dear Customer, please wait for some time or re-enter the queue." << endl;
            }
            else{
                item1-=K;
                cout << "Customer " << id << " has successfully purchased quantity " << K << " of Item no 1" << endl;
            }
            q.pop();
        }
        else if(item_no == 2)
        {
            if(K > item2)
            {
                cout << "Warning: Item no 2 is out of stock!" << endl;
                cout << "Dear Customer, please wait for some time or re-enter the queue." << endl;
            }
            else{
                item2-=K;
                cout << "Customer " << id << " has successfully purchased quantity " << K << " of Item no 2" << endl;
            }
            q.pop();
        }
        else
        {
            if(K > item3)
            {
                cout << "Warning: Item no 3 is out of stock!" << endl;
                cout << "Dear Customer, please wait for some time or re-enter the queue." << endl;
            }
            else{
                item3-=K;
                cout << "Customer " << id << " has successfully purchased quantity " << K << " of Item no 3" << endl;
            }
            q.pop();
        }
    }
    return 0;
}