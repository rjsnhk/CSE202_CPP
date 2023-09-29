#include <iostream>
#include <cmath>

class AdvCalculator {
public:
    bool isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    int factorial(int number) {
        if (number == 0) {
            return 1;
        }
        return number * factorial(number - 1);
    }

    int crossSum(int number) {
        int sum = 0;
        while (number != 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};

class Calculator : public AdvCalculator {
public:
    void calculate(int number) {
        if (isPrime(number)) {
            std::cout << "Prime number" << std::endl;
        } else {
            std::cout << "Not prime number" << std::endl;
        }

        int fact = factorial(number);
        std::cout << fact << std::endl;

        int crossSumResult = crossSum(fact);
        std::cout << crossSumResult << std::endl;
    }
};

int main() {
    int number;
    std::cin >> number;

    Calculator calculator;
    calculator.calculate(number);

    return 0;
}
