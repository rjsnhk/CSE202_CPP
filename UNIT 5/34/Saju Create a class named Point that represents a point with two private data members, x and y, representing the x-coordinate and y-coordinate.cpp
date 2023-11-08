#include <iostream>

class Point {
protected:
    int x, y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    void setX(int _x) {
        x = _x;
    }

    void setY(int _y) {
        y = _y;
    }

    virtual void display() {
        std::cout << "Point: (" << x << "," << y << ")" << std::endl;
    }
};

class Line : public Point {
private:
    int x2, y2;

public:
    Line(int _x1, int _y1, int _x2, int _y2) : Point(_x1, _y1), x2(_x2), y2(_y2) {}

    void setX2(int _x2) {
        x2 = _x2;
    }

    void setY2(int _y2) {
        y2 = _y2;
    }

    void display() override {
        std::cout << "The line is:" << std::endl;
        std::cout << "Start point: (" << x << "," << y << ")" << std::endl;
        std::cout << "End point: (" << x2 << "," << y2 << ")" << std::endl;
    }
};

int main() {
    int x1, y1, x2, y2;
    
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;

    Line line(x1, y1, x2, y2);
    line.display();

    return 0;
}

