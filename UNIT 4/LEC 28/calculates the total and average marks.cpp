#include <iostream>
#include <string>
using namespace std;

class Marks {
protected:
    int rollNumber;
    string name;
    int marksPhysics;
    int marksChemistry;
    int marksMathematics;
public:
    static int count;
    Marks(string name, int physics, int chemistry, int mathematics) {
        rollNumber = ++count;
        this->name = name;
        marksPhysics = physics;
        marksChemistry = chemistry;
        marksMathematics = mathematics;
    }
    int getTotalMarks() {
        return marksPhysics + marksChemistry + marksMathematics;
    }
    void displayMarks() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Total marks: " << getTotalMarks() << endl << endl;
    }
};

int Marks::count = 0;

class Physics : public Marks {
public:
    Physics(string name, int marks) : Marks(name, marks, 0, 0) {}
};

class Chemistry : public Marks {
public:
    Chemistry(string name, int marks) : Marks(name, 0, marks, 0) {}
};

class Mathematics : public Marks {
public:
    Mathematics(string name, int marks) : Marks(name, 0, 0, marks) {}
};

int main() {
    int n;
    cin >> n;

    Marks* students[n];

    for (int i = 0; i < n; i++) {
        string name;
        int physics, chemistry, mathematics;
        cin >> name >> physics >> chemistry >> mathematics;
        students[i] = new Marks(name, physics, chemistry, mathematics);
    }

    int totalClassMarks = 0;
    for (int i = 0; i < n; i++) {
        students[i]->displayMarks();
        totalClassMarks += students[i]->getTotalMarks();
    }

    double averageClassMarks = static_cast<double>(totalClassMarks) / n;

    cout << "Total marks of the class is: " << totalClassMarks << endl;
    cout << "The average marks of the class is: " << averageClassMarks << endl;

    return 0;
}
