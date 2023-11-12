#include <iostream>
#include <exception>

class NegativeRadiusException : public std::exception {
public:
    const char* what() const throw() {
        return "Radius cannot be negative or zero.";
    }
};

class Circle {
private:
    double radius;

public:
    Circle() : radius(0.0) {}

    void setRadius(double r) {
        if (r <= 0) {
            throw NegativeRadiusException();
        }
        radius = r;
    }

    double getRadius() {
        return radius;
    }
};

int main() {
    Circle circle;
    double r;

    try {
        std::cin >> r;
        circle.setRadius(r);
        std::cout << "Radius set successfully: " << circle.getRadius() << std::endl;
    } catch (NegativeRadiusException& ex) {
        std::cout << "Exception caught. Error: " << ex.what() << std::endl;
    }

    return 0;
}

