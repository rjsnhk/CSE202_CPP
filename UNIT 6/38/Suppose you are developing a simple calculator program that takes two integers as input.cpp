#include <iostream>

int main() {
    int num, den;

    try {
        // Input
        std::cin >> num >> den;

        if (den == 0) {
            // Throw an exception if the denominator is zero
            throw "Divide by Zero Exception";
        }

        // Calculate and print the result
        std::cout << num / den << std::endl;
    } catch (const char* exception) {
        // Handle the exception
        std::cout << exception << std::endl;
    }

    return 0;
}

