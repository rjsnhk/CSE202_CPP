#include <iostream>
using namespace std;

// Template function to calculate total revenue from spa bookings
template <typename T>
T calculateTotalRevenue(T bookingAmounts[], int n) {
    T totalRevenue = 0;
    for (int i = 0; i < n; i++) {
        totalRevenue += bookingAmounts[i];
    }
    return totalRevenue;
}

int main() {
    int n;
    cin >> n;

    // Create an array of booking amounts
    double bookingAmounts[n];

    for (int i = 0; i < n; i++) {
        cin >> bookingAmounts[i];
    }

    // Calculate the total revenue using the template function
    double totalRevenue = calculateTotalRevenue(bookingAmounts, n);

    // Output the total revenue
    cout << totalRevenue << endl;

    return 0;
}

