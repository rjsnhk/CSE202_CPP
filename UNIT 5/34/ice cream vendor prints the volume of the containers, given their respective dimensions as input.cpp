#include <bits/stdc++.h>

class Icecream {
public:
    void Quantity(int r) {
        double volume = pow(r, 3);
        std::cout << std::fixed << std::setprecision(2) << volume << std::endl;
    }

    void Quantity(int r, int h) {
        double volume = 0.33 * M_PI * pow(r, 2) * h;
        std::cout << std::fixed << std::setprecision(2) << volume << std::endl;
    }
};

int main() {
    int choice, r, h;
    std::cin >> choice;

    Icecream icecream;

    if (choice == 1) {
        std::cin >> r;
        icecream.Quantity(r);
    } else if (choice == 2) {
        std::cin >> r >> h;
        icecream.Quantity(r, h);
    }

    return 0;
}

