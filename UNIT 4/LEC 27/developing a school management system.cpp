#include <iostream>
#include <string>

class Person {
protected:
    std::string firstName;
    std::string lastName;
    int id;

public:
    Person(const std::string& firstName, const std::string& lastName, int id)
        : firstName(firstName), lastName(lastName), id(id) {}

    void printInfo() const {
        std::cout << "Name: " << firstName << " " << lastName << std::endl;
        std::cout << "ID: " << id << std::endl;
    }
};

class Student : public Person {
private:
    int numScores;
    int* scores;

public:
    Student(const std::string& firstName, const std::string& lastName, int id, int numScores, int* scores)
        : Person(firstName, lastName, id), numScores(numScores) {
        this->scores = new int[numScores];
        for (int i = 0; i < numScores; ++i) {
            this->scores[i] = scores[i];
        }
    }

    ~Student() {
        delete[] scores;
    }

    void calculateGrade() const {
        int total = 0;
        for (int i = 0; i < numScores; ++i) {
            total += scores[i];
        }
        double average = static_cast<double>(total) / numScores;

        char grade;
        if (average >= 90) {
            grade = 'O';
        } else if (average >= 80) {
            grade = 'E';
        } else if (average >= 70) {
            grade = 'A';
        } else if (average >= 55) {
            grade = 'P';
        
        } else if (average >= 40) {
            grade = 'D';
        } else {
            grade = 'T';
        }

        std::cout << "Grade: " << grade << std::endl;
    }
};

int main() {
    std::string firstName, lastName;
    int id, numScores;

    std::getline(std::cin, firstName);
    std::getline(std::cin, lastName);
    std::cin >> id;
    std::cin >> numScores;

    int* scores = new int[numScores];
    for (int i = 0; i < numScores; ++i) {
        std::cin >> scores[i];
    }

    Student student(firstName, lastName, id, numScores, scores);
    student.printInfo();
    student.calculateGrade();

    delete[] scores;

    return 0;
}
