#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;

public:
    Vehicle(const string& b) : brand(b) {}

    virtual void displayInfo() const = 0;
};

class Car : public Vehicle {
private:
    int doors;

public:
    Car(const string& b, int d) : Vehicle(b), doors(d) {}

    void displayInfo() const override {
        cout << "Brand: " << brand << endl;
        cout << "Number of Doors: " << doors << endl;
    }
};

class Bicycle : public Vehicle {
private:
    int gears;

public:
    Bicycle(const string& b, int g) : Vehicle(b), gears(g) {}

    void displayInfo() const override {
        cout << "Brand: " << brand << endl;
        cout << "Number of Gears: " << gears << endl;
    }
};

int main() {
    string carBrand, bicycleBrand;
    int carDoors, bicycleGears;

    cin >> carBrand;
    cin >> carDoors;

    cin >> bicycleBrand;
    cin >> bicycleGears;

    Car myCar(carBrand, carDoors);
    Bicycle myBicycle(bicycleBrand, bicycleGears);

    myCar.displayInfo();
    cout << endl;
    myBicycle.displayInfo();

    return 0;
}

