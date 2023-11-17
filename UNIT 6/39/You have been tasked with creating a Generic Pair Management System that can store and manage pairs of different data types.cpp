#include <iostream>
using namespace std;

// Template class PairBase to manage pairs of float and double values
template <typename T1, typename T2>
class PairBase {
public:
    T1 first;
    T2 second;

    // Constructor to initialize the pair
    PairBase(T1 a, T2 b) : first(a), second(b) {}

    // Function to swap the values in the pair
    void swap() {
        T1 temp = first;
        first = second;
        second = temp;
    }

    // Function to display the details of the pair
    void display() {
        cout << "Values before swap:" << endl;
        cout << "First: " << first << endl;
        cout << "Second: " << second << endl;
    }
};

// Derived class template PairDerived that inherits from PairBase
template <typename T1, typename T2>
class PairDerived : public PairBase<T1, T2> {
public:
    // Constructor to inherit and initialize the base class
    PairDerived(T1 a, T2 b) : PairBase<T1, T2>(a, b) {}
};

int main() {
    double a, b;

    // Input for float and double values
    cin >> a >> b;

    // Create an instance of PairDerived for float and double
    PairDerived<double, double> pair(a, b);

    // Display values before the swap
    pair.display();

    // Swap the values
    pair.swap();

    // Display values after the swap
    cout << "Values after swap:" << endl;
    cout << "First: " << pair.first << endl;
    cout << "Second: " << pair.second << endl;

    return 0;
}

