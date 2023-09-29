#include <iostream>
using namespace std;
int main()
{
    int hours, minutes;
    cin >> hours >> minutes;
    int total_minutes = hours * 60 + minutes;
    cout << total_minutes << " mins";
    return 0;
}

