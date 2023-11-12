#include <iostream>
#include <map>
#include <exception>
#include <iomanip>

const int MAX_ASSETS = 20;

class InvalidAssetIDException : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid asset ID.";
    }
};

class NegativeValueException : public std::exception {
public:
    const char* what() const throw() {
        return "Asset value cannot be negative.";
    }
};

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, double> assets;

    try {
        for (int i = 0; i < n; ++i) {
            std::string assetID;
            double initialValue;
            std::cin >> assetID >> initialValue;

            if (assets.size() >= MAX_ASSETS) {
                throw std::runtime_error("Maximum number of assets reached.");
            }

            assets[assetID] = initialValue;
            std::cout << "Asset with ID " << assetID << " added with an initial value of " << std::fixed << std::setprecision(0) << initialValue << std::endl;
        }

        std::string assetID;
        double newValue;
        std::cin >> assetID >> newValue;

        if (assets.find(assetID) == assets.end()) {
            throw InvalidAssetIDException();
        }

        if (newValue < 0) {
            throw NegativeValueException();
        }

        assets[assetID] = newValue;
        std::cout << "Value of asset with ID " << assetID << " updated to " << std::fixed << std::setprecision(0) << newValue << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "Exception caught: Error: " << ex.what() << std::endl;
    }

    return 0;
}

