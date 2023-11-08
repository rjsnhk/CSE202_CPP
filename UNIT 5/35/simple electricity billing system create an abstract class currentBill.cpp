#include <iostream>
using namespace std;

class currentBill {
protected:
    int powerRating;
    int totalHours;

public:
    currentBill(int powerRating, int totalHours) {
        this->powerRating = powerRating;
        this->totalHours = totalHours;
    }

    virtual double amount()=0;
};

class Fan : public currentBill {
public:
    Fan(int powerRating, int totalHours) : currentBill(powerRating, totalHours) {}

    double amount() {
        double energyConsumed = (powerRating * totalHours) / 1000.0; // Convert watt-hours to kilowatt-hours
        double billAmount = energyConsumed * 1.5; // Electricity tariff rate is $1.5 per kWh
        return billAmount;
    }
};

class Light : public currentBill {
public:
    Light(int powerRating, int totalHours) : currentBill(powerRating, totalHours) {}

    double amount() {
        double energyConsumed = (powerRating * totalHours) / 1000.0; // Convert watt-hours to kilowatt-hours
        double billAmount = energyConsumed * 1.5; // Electricity tariff rate is $1.5 per kWh
        return billAmount;
    }
};

class TV : public currentBill {
public:
    TV(int powerRating, int totalHours) : currentBill(powerRating, totalHours) {}

    double amount() {
        double energyConsumed = (powerRating * totalHours) / 1000.0; // Convert watt-hours to kilowatt-hours
        double billAmount = energyConsumed * 1.5; // Electricity tariff rate is $1.5 per kWh
        return billAmount;
    }
};

int main() {
    int fanPower, fanHours, lightPower, lightHours, tvPower, tvHours;

    // Read input values
    cin >> fanPower >> fanHours;
    cin >> lightPower >> lightHours;
    cin >> tvPower >> tvHours;

    // Create objects of each appliance type
    Fan fan(fanPower, fanHours);
    Light light(lightPower, lightHours);
    TV tv(tvPower, tvHours);

    // Calculate and print the total bill amount
    double totalBillAmount = fan.amount() + light.amount() + tv.amount();
    cout << totalBillAmount << endl;

    return 0;
}

