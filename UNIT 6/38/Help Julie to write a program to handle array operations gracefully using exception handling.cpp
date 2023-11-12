#include <iostream>
#include <exception>

int main() {
    int n;
    std::cin >> n;

    try {
        if (n <= 0) {
            if (n == 0) {
                throw std::runtime_error("Array is empty.");
            } else {
                throw std::runtime_error("Array size should be a positive number.");
            }
        } else {
            int* arr = new int[n];
            for (int i = 0; i < n; i++) {
                std::cin >> arr[i];
            }
            for (int i = 0; i < n; i++) {
                std::cout << arr[i] << " ";
            }
            delete[] arr;  // Memory deallocation to avoid memory leaks
        }
    } catch (const std::exception& ex) {
        std::cout << "Exception caught. " << ex.what() << std::endl;
    }

    return 0;
}

