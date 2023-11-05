#include <iostream>
#include <string>
#include <iomanip>

const double ECONOMY_RATE = 40.00;
const double COMPACT_RATE = 50.00;
const double STANDARD_RATE = 60.00;

class Car {
public:
    virtual double calculateRentalCost(int numDays) {
        return 0.0;
    }
};

class EconomyCar : public Car {
public:
    double calculateRentalCost(int numDays) override {
        return ECONOMY_RATE * numDays;
    }
};

class CompactCar : public Car {
public:
    double calculateRentalCost(int numDays) override {
        return COMPACT_RATE * numDays;
    }
};

class StandardCar : public Car {
public:
    double calculateRentalCost(int numDays) override {
        return STANDARD_RATE * numDays;
    }
};

int main() {
    int numDays;
    std::string carType;

    std::cin >> numDays;
    std::cin >> carType;

    Car* car;

    if (carType == "Economy") {
        car = new EconomyCar();
    } else if (carType == "Compact") {
        car = new CompactCar();
    } else if (carType == "Standard") {
        car = new StandardCar();
    } else {
        std::cout << "Invalid car type." << std::endl;
        return 0;
    }

    double totalCost = car->calculateRentalCost(numDays);
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "The total cost of the rental is $" << totalCost << std::endl;

    delete car;

    return 0;
}

