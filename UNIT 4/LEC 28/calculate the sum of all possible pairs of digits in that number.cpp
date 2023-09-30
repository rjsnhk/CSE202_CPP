#include <iostream>

using namespace std;

class Parent {
public:
    int num;

    // Constructor to initialize num
    Parent(int _num) : num(_num) {}
};

class Child : public Parent {
public:
    // Constructor to inherit num from the nt class
    Child(int _num) : Parent(_num) {}

    // Method to calculate the sum of all possible pairs of digits
    int fun() {
        int sum = 0;
        int numCopy = num; // Make a copy of num to extract digits

        while (numCopy > 0) {
            int digit1 = numCopy % 10; // Extract the last digit
            numCopy /= 10; // Remove the last digit

            int tempNum = numCopy; // Create a copy of numCopy for the inner loop

            while (tempNum > 0) {
                int digit2 = tempNum % 10; // Extract the last digit
                tempNum /= 10; // Remove the last digit

                // Add the sum of the pair of digits if they are different
                if (digit1 != digit2) {
                    sum += digit1 + digit2;
                }
            }
        }

        return sum;
    }
};

int main() {
    int number;
    cin >> number;

    // Create an object of class
    Child obj(number);

    // Calculate and print the sum of all possible pairs of digits
    cout << obj.fun() << endl;

    return 0;
}

