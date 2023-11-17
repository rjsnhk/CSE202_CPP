#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

template <typename T>
class Point {
public:
    T x, y, z;

    Point() : x(0), y(0), z(0) {}
    Point(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
};

template <typename T>
T calculateDistance(Point<T> p1, Point<T> p2) {
    T dx = p1.x - p2.x;
    T dy = p1.y - p2.y;
    T dz = p1.z - p2.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    int choice;
    cin >> choice;

    if (choice == 2) {
        Point<double> p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;

        double distance = calculateDistance(p1, p2);
        cout << "Distance between the points in two-dimensional space: " << fixed << setprecision(2) << distance << endl;
    } else if (choice == 3) {
        Point<double> p1, p2;
        cin >> p1.x >> p1.y >> p1.z >> p2.x >> p2.y >> p2.z;

        double distance = calculateDistance(p1, p2);
        cout << "Distance between the points in three-dimensional space: " << fixed << setprecision(2) << distance << endl;
    } else {
        cout << "Invalid choice. Please enter 2 or 3." << endl;
    }

    return 0;
}

