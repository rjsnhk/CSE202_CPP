#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    Car() {
        make = "";
        model = "";
        year = 0;
    }

    void setMake(const std::string& _make) {
        make = _make;
    }

    void setModel(const std::string& _model) {
        model = _model;
    }

    void setYear(int _year) {
        year = _year;
    }

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    virtual int findSpeed() {
        return 0; // Default base speed
    }
};

class SportsCar : public Car {
private:
    int maxSpeed;

public:
    SportsCar(int _maxSpeed) : maxSpeed(_maxSpeed) {}

    int findSpeed() override {
        return maxSpeed;
    }
};

int main() {
    std::string make, model;
    int year, maxSpeed;

    std::getline(std::cin, make); // Read the make
    std::getline(std::cin, model); // Read the model
    std::cin >> year; // Read the year
    std::cin >> maxSpeed; // Read the max speed

    // Create objects of Car and SportsCar classes
    Car car;
    SportsCar sportsCar(maxSpeed);

    car.setMake(make);
    car.setModel(model);
    car.setYear(year);

    // Display car details
    std::cout << "Make of the car is: " << car.getMake() << std::endl;
    std::cout << "Model of the car is: " << car.getModel() << std::endl;
    std::cout << "Year of the car is: " << car.getYear() << std::endl;

    // Display sports car speed
    std::cout << "Speed of the sports car is: " << sportsCar.findSpeed() << " km/h" << std::endl;

    return 0;
}

