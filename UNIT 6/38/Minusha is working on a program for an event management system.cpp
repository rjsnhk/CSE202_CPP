#include <iostream>
#include <map>
#include <exception>

const int MAX_EVENTS = 20;

class InvalidEventIDException : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid event ID.";
    }
};

class InsufficientSeatsException : public std::exception {
public:
    const char* what() const throw() {
        return "Insufficient seats available for booking.";
    }
};

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> events;

    try {
        for (int i = 0; i < n; ++i) {
            std::string eventID;
            int totalSeats;
            std::cin >> eventID >> totalSeats;

            if (events.size() >= MAX_EVENTS) {
                throw std::runtime_error("Maximum number of events reached.");
            }

            events[eventID] = totalSeats;
            std::cout << "Event with ID " << eventID << " added with " << totalSeats << " seats." << std::endl;
        }

        std::string eventID;
        int numTickets;
        std::cin >> eventID >> numTickets;

        if (events.find(eventID) == events.end()) {
            throw InvalidEventIDException();
        }

        if (numTickets > events[eventID]) {
            throw InsufficientSeatsException();
        }

        events[eventID] -= numTickets;
        std::cout << numTickets << " tickets booked for event with ID " << eventID << ". Remaining seats: " << events[eventID] << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "Exception caught: Error: " << ex.what() << std::endl;
    }

    return 0;
}

