#include <iostream>
#include <string>

class FullName {
private:
    std::string firstName;
    std::string lastName;

public:
    FullName(const std::string& first, const std::string& last) {
        firstName = first;
        lastName = last;
    }

    std::string toString() const {
        return firstName + " " + lastName;
    }
};

int main() {
    std::string firstName, lastName;
    std::getline(std::cin, firstName);
    std::getline(std::cin, lastName);

    FullName fullName(firstName, lastName);
    std::cout << fullName.toString() << std::endl;

    return 0;
}

