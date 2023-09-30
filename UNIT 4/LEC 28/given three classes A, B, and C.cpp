#include <iostream>
using namespace std;

class A {
public:
    void func(int &val) {
        val *= 2;
    }
};

class B {
public:
    void func(int &val) {
        val *= 3;
    }
};

class C {
public:
    void func(int &val) {
        val *= 5;
    }
};

class D {
private:
    int val;
    int cnt[3] = {0};
    A a;
    B b;
    C c;
public:
    D() : val(1) {}
    
    // Implement this function
    void update_val(int new_val) {
        while (new_val % 2 == 0) {
            new_val /= 2;
            a.func(val);
            cnt[0]++;
        }
        while (new_val % 3 == 0) {
            new_val /= 3;
            b.func(val);
            cnt[1]++;
        }
        while (new_val % 5 == 0) {
            new_val /= 5;
            c.func(val);
            cnt[2]++;
        }
    }

    void check(int); // Do not delete this line.
};

void D::check(int new_val) {
    update_val(new_val);
    cout << "Value = " << val << endl;
    cout << "A's func called " << cnt[0] << " times " << endl;
    cout << "B's func called " << cnt[1] << " times " << endl;
    cout << "C's func called " << cnt[2] << " times " << endl;
}

int main() {
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

    return 0;
}

