#include <iostream>

class Vehicle {
public:
    float distance;
    float time;

    // Constructor to initialize distance and time
    Vehicle(float d, float t) : distance(d), time(t) {}

    // Function to calculate and display the speed
    void calculateSpeed() {
        if (time != 0) {
            float speed = distance / time;
            std::cout << "Speed of car: " << speed << " km/hr" << std::endl;
        } else {
            std::cerr << "Error: Time cannot be zero." << std::endl;
        }
    }
};

class Car : public Vehicle {
public:
    Car(float d, float t) : Vehicle(d, t) {}
};

int main() {
    float distance, time;
    std::cin >> distance >> time;

    // Create an instance of the Car class
    Car car(distance, time);

    // Calculate and display the speed
    car.calculateSpeed();

    return 0;
}

