#include <iostream>
using namespace std;
int main()
{
    int bal, amt;
    // cout << "Enter the initial balance: ";
    cin >> bal;
    // cout << "Enter the amount to withdraw: ";
    cin >> amt;
    if (bal > amt)
    {
        bal = bal - amt;
        cout<< bal;
    }
    else
    {
        cout << "Insufficient balance";
    }
    return 0;
}

