#include <iostream>
#include <unordered_set>

const int MAX_CAPACITY = 30;

class DuplicateIDException : public std::exception {
public:
    const char* what() const throw() {
        return "Student ID already exists.";
    }
};

class FullDatabaseException : public std::exception {
public:
    const char* what() const throw() {
        return "Student database is full.";
    }
};

class StudentDatabase {
private:
    std::unordered_set<int> studentIDs;

public:
    void addStudent(int id, const std::string& name) {
        if (studentIDs.size() >= MAX_CAPACITY) {
            throw FullDatabaseException();
        }

        if (studentIDs.find(id) != studentIDs.end()) {
            throw DuplicateIDException();
        }

        studentIDs.insert(id);
        std::cout << "Student with ID " << id << " added to the database." << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    StudentDatabase database;

    for (int i = 0; i < n; ++i) {
        int id;
        std::string name;
        std::cin >> id >> name;

        try {
            database.addStudent(id, name);
        } catch (DuplicateIDException& ex) {
            std::cout << "Exception caught. Error: " << ex.what() << std::endl;
        } catch (FullDatabaseException& ex) {
            std::cout << "Exception caught. Error: " << ex.what() << std::endl;
            break;
        }
    }

    return 0;
}

