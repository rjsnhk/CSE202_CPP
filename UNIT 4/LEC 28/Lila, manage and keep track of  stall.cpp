#include <iostream>
#include <string>

using namespace std;

class SilverStall {
protected:
    string name;
    string detail;
    string owner;
    int cost;

public:
    SilverStall(string n, string d, string o, int c) {
        name = n;
        detail = d;
        owner = o;
        cost = c;
    }

    int get_cost() {
        return cost;
    }
};

class GoldStall : public SilverStall {
protected:
    int tvSet;

public:
    GoldStall(string n, string d, string o, int c, int t) : SilverStall(n, d, o, c) {
        tvSet = t;
        cost += t * 100;
    }
};

class PlatinumStall : public GoldStall {
protected:
    int projector;

public:
    PlatinumStall(string n, string d, string o, int c, int t, int p) : GoldStall(n, d, o, c, t) {
        projector = p;
        cost += p * 500;
    }
};

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        string name, detail, owner;
        int cost;
        cin >> name >> detail >> owner >> cost;
        SilverStall s(name, detail, owner, cost);
        cout << s.get_cost() << endl;
    } else if (n == 2) {
        string name, detail, owner;
        int cost, tvSet;
        cin >> name >> detail >> owner >> cost >> tvSet;
        GoldStall g(name, detail, owner, cost, tvSet);
        cout << g.get_cost() << endl;
    } else if (n == 3) {
        string name, detail, owner;
        int cost, tvSet, projector;
        cin >> name >> detail >> owner >> cost >> tvSet >> projector;
        PlatinumStall p(name, detail, owner, cost, tvSet, projector);
        cout << p.get_cost() << endl;
    } else {
        cout << "Invalid Input" << endl;
    }

    return 0;
}

