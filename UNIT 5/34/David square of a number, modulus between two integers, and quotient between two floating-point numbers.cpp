#include <bits/stdc++.h>

int clac(int a) {
    return a * a;
}

int clac(int a, int b) {
    return a % b;
}

float calc(float a, float b) {
    return a / b;
}

int main() {
    int intInput1, intInput2;
    float floatInput1, floatInput2;

    std::cin >> intInput1 >> intInput2 >> floatInput1 >> floatInput2;

    int squareResult = clac(intInput1);
    int modulusResult = clac(intInput1, intInput2);
    float quotientResult = calc(floatInput1, floatInput2);

    std::cout << "Square of " << intInput1 << ": " << squareResult << std::endl;
    std::cout << "Modulus of " << intInput1 << ", " << intInput2 << ": " << modulusResult << std::endl;
    std::cout << "Quotient of " << floatInput1 << ", " << floatInput2 << ": " <<std::fixed<<std::setprecision(2)<< quotientResult << std::endl;

    return 0;
}

