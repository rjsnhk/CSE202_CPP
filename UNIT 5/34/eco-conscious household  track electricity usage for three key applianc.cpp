//In an eco-conscious household, a smart energy monitoring system is implemented to track electricity usage for three key appliances: a Fan, a Light, and a TV.
//
//
//
//The system has three classes: "Fan," "Light," and "TV" - all inheriting from a base class named "currentBill." Each class includes attributes for the watts (power consumption) and the number of hours the appliance is used.
//
//
//
//When the user interacts with the system, they provide the power consumption (in watts) and the usage hours for each appliance. The system then calculates the electricity consumption for each device, converting it to kilowatt-hours (kWh) based on the formula (watts * hours / 1000). The energy cost is assumed to be $1.5 per kWh.
//
//
//
//Write a program using virtual functions to accomplish this task.
//
//Input format :
//The first line consists of the power rating of the fan and the total hours used, separated by space.
//
//The second line consists of the power rating of Light and the total hours used, separated by space.
//
//The third line consists of the power rating of the TV and the total hours used, separated by space.
//
//Output format :
//The output prints the bill amount, rounding off to two decimal places.
//
//Code constraints :
//Power rating > 0
//
//Total hours > 0
//
//Sample test cases :
//Input 1 :
//40 123
//55 200
//33 400
//Output 1 :
//43.68
//Note :
//The program will be evaluated only after the “Submit Code” is clicked.
//Extra spaces and new line characters in the program output will result in the failure of the test case.
//Marks : 10
//Negative Marks : 0
//image
//Whitelist
//Set 1:
//virtual

#include <iostream>
#include <iomanip>

class CurrentBill {
public:
    virtual double calculateBill(double watts, double hours) {
        return (watts * hours / 1000) * 1.5;
    }
};

class Fan : public CurrentBill {
};

class Light : public CurrentBill {
};

class TV : public CurrentBill {
};

int main() {
    double fanPower, lightPower, tvPower;
    double fanHours, lightHours, tvHours;

    std::cin >> fanPower >> fanHours;
    std::cin >> lightPower >> lightHours;
    std::cin >> tvPower >> tvHours;

    Fan fan;
    Light light;
    TV tv;

    double fanCost = fan.calculateBill(fanPower, fanHours);
    double lightCost = light.calculateBill(lightPower, lightHours);
    double tvCost = tv.calculateBill(tvPower, tvHours);

    double totalCost = fanCost + lightCost + tvCost;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << totalCost << std::endl;

    return 0;
}

