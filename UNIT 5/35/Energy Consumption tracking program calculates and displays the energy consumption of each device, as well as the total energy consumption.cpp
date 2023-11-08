#include <iostream>
#include <vector>

class Device {
public:
    Device(int powerRating, int usageHours) : powerRating(powerRating), usageHours(usageHours) {}

    virtual void calculateEnergyConsumption() = 0;

    int getEnergyConsumption() const {
        return energyConsumption;
    }

protected:
    int powerRating;
    int usageHours;
    int energyConsumption;
};

class Refrigerator : public Device {
public:
    Refrigerator(int powerRating, int usageHours) : Device(powerRating, usageHours) {}

    void calculateEnergyConsumption() override {
        energyConsumption = powerRating * usageHours;
    }
};

class AirConditioner : public Device {
public:
    AirConditioner(int powerRating, int usageHours) : Device(powerRating, usageHours) {}

    void calculateEnergyConsumption() override {
        energyConsumption = powerRating * usageHours;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Device*> devices;

    for (int i = 0; i < n; i++) {
        int deviceType, powerRating, usageHours;
        std::cin >> deviceType >> powerRating >> usageHours;

        if (deviceType == 1) {
            devices.push_back(new Refrigerator(powerRating, usageHours));
        } else if (deviceType == 2) {
            devices.push_back(new AirConditioner(powerRating, usageHours));
        }
    }

    int totalEnergyConsumption = 0;

    for (Device* device : devices) {
        device->calculateEnergyConsumption();
        std::cout << "Device Type: ";
        if (dynamic_cast<Refrigerator*>(device)) {
            std::cout << "Refrigerator" << std::endl;
        } else if (dynamic_cast<AirConditioner*>(device)) {
            std::cout << "Air Conditioner" << std::endl;
        }
        // std::cout << "Energy Consumption: " << device->getEnergyConsumption() << " watt-hours" << std::endl;
        totalEnergyConsumption += device->getEnergyConsumption();
        delete device;
    }

    std::cout << "Total Energy Consumption: " << totalEnergyConsumption << " watt-hours" << std::endl;

    return 0;
}

