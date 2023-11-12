#include <iostream>

int main() {
    int num;
    std::cin >> num;

    try {
        if (num > 0) {
            std::cout << "You Entered Positive number" << std::endl;
        } else if (num < 0) {
            std::cout << "You Entered Negative number" << std::endl;
        } else {
            if (num == 0) {
                throw 0;
            }
        }
    } catch (int) {
        std::cout << "You Entered Zero" << std::endl;
    }

    return 0;
}

