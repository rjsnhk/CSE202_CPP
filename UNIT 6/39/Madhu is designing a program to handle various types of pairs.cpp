#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair {
public:
    T1 first;
    T2 second;

    // Constructor to initialize data members
    Pair(T1 a, T2 b) : first(a), second(b) {}

    // Function to swap the values
    void swap() {
        T1 temp = first;
        first = second;
        second = temp;
    }
};

int main() {
    float a;
    double b;

    // Input for float and double values
    cin >> a;
    cin >> b;

    // Create a Pair object with the user input values
    Pair<float, double> myPair(a, b);

    // Output values before swap
    cout << "Values before swap:" << endl;
    cout << "First: " << myPair.first << endl;
    cout << "Second: " << myPair.second << endl;

    // Swap the values
    myPair.swap();

    // Output values after swap
    cout << "Values after swap:" << endl;
    cout << "First: " << myPair.first << endl;
    cout << "Second: " << myPair.second << endl;

    return 0;
}

